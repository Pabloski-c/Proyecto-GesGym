#include "HijaTabla.h"
#include "Gestor_Alumnos.h"
#include "Alumno.h"
#include <string>
#include <wx/msgdlg.h>
#include <vector>
#include <wx/wx.h>
#include "HijaVerDatos.h"
#include "Gestor_Planes.h"
using namespace std;

HijaTabla::HijaTabla(wxWindow *parent, Gestor_Alumnos *gestor, Gestor_Planes *planes) : Tabla(parent), m_gestor(gestor), m_planes(planes){
	m_gestor->CargarDatos();
	m_planes->CargarPlanes();
	m_gestor->CargarBackupInicial();
	
	SeleccionPlanes();
	RefrescarGrilla();
	
	m_grilla->EnableGridLines(true);
	m_grilla->SetSelectionMode(wxGrid::wxGridSelectRows);
	
}

void HijaTabla::ClickFiltrar( wxCommandEvent& event ){
	
	string criterio_seleccionado = seleccion_filtro->GetStringSelection().ToStdString();
	
	if (criterio_seleccionado == "Sin filtro") {
		m_gestor->CargarDatos();  ///Cargar todos los alumnos nuevamente
	} else {
		m_gestor->ObtenerAlumnosPorPlan(criterio_seleccionado);
	}
	
	RefrescarGrilla();
}

void HijaTabla::ClickEliminar(wxCommandEvent& event){
	
	wxArrayInt FilasSeleccionadas = m_grilla->GetSelectedRows();
	
	if (FilasSeleccionadas.empty()) {
		wxMessageBox("Seleccione un alumno primero.");
		return;
	}
	
	int respuesta = wxMessageBox("¿Está seguro de eliminar el alumno seleccionado?",
	"Confirmar eliminación", wxYES_NO | wxICON_QUESTION);
	
	if (respuesta == wxYES) {
		///Obtener los DNIs de los alumnos seleccionados
		vector<int> dnis_a_eliminar;
		for (unsigned int i = 0; i < FilasSeleccionadas.GetCount(); i++) {
			int fila = FilasSeleccionadas[i];
			int dni = stoi(m_grilla->GetCellValue(fila, 1).ToStdString()); ///Convertir a int
			dnis_a_eliminar.push_back(dni);
		}
		
		///Eliminar cada alumno usando su DNI
		for (int dni : dnis_a_eliminar) {
			m_gestor->EliminarAlumnoPorDNI(dni);
		}
		
		m_gestor->CargarDatos(); ///Recargar la lista actualizada
		RefrescarGrilla();
	}
}

void HijaTabla::ClickSalir( wxCommandEvent& event ){
	Close();
}

///Funcion para refrescar la tabla
void HijaTabla::RefrescarGrilla(){
	if(m_grilla->GetNumberRows()!=0) m_grilla->DeleteRows(0,m_grilla->GetNumberRows());
	for(int i=0;i<m_gestor->VerCantidadAlumnos();i++){
		m_grilla->AppendRows();
		Alumno a = m_gestor->VerAlumnoPorPosicion(i);
		m_grilla->SetCellValue(i,0,a.VerApellido()+", "+a.VerNombre());
		m_grilla->SetCellValue(i,1,to_string(a.VerDNI()));
		m_grilla->SetCellValue(i,2,a.VerPlan());
		m_grilla->SetCellValue(i,3,to_string(a.VerTelefono()));
		m_grilla->SetCellValue(i, 4, a.VerEstadoSTR());  ///NUEVO
	}
}

void HijaTabla::ClickBuscar( wxCommandEvent& event ){
	
	string dni_o_nombre_buscado = entrada_buscar->GetValue().ToStdString(); ///Obtenemos el valor ingresado en la casilla de texto de buscar
	///chequeamos que sea un valor valido
	if(dni_o_nombre_buscado.empty()){
		RefrescarGrilla();
		return;
	}
	
	if(!m_gestor->EsSoloLetras(dni_o_nombre_buscado) and dni_o_nombre_buscado.size()>8){
		wxMessageBox("Un DNI no puede tener mas de 8 digitos.");
		RefrescarGrilla();
		return;
	}
	
	m_grilla->ClearGrid();
	if(m_grilla->GetNumberRows()!=0){
		m_grilla->DeleteRows(0, m_grilla->GetNumberRows());
	}
	
	int fila=0;
	for(Alumno alumno:m_gestor->ObtenerListaAlumnos()){
		if(alumno.VerNombre() == dni_o_nombre_buscado or alumno.VerApellido() == dni_o_nombre_buscado or to_string(alumno.VerDNI()) == dni_o_nombre_buscado){
			m_grilla->AppendRows(1);
			m_grilla->SetCellValue(fila,0,alumno.VerApellido()+", "+alumno.VerNombre());
			m_grilla->SetCellValue(fila,1,to_string(alumno.VerDNI()));
			m_grilla->SetCellValue(fila,2,alumno.VerPlan());
			m_grilla->SetCellValue(fila,3,to_string(alumno.VerTelefono()));
			m_grilla->SetCellValue(fila, 4, alumno.VerEstadoSTR());
			fila++;
		}
	}
	
	if(fila==0){
		wxMessageBox("No existen resultados");
		RefrescarGrilla();
		return;
	}
}

void HijaTabla::ClickOrdenar( wxCommandEvent& event )  {
	string criterio_seleccionado;
	criterio_seleccionado=seleccion_orden_tabla->GetStringSelection();
	m_gestor->OrdenarSegunCriterio(criterio_seleccionado);
	RefrescarGrilla();
}

void HijaTabla::ClickVerDatos( wxCommandEvent& event )  {
	
	wxArrayInt FilasSeleccionadas=m_grilla->GetSelectedRows();
	
	if(FilasSeleccionadas.empty()){
		wxMessageBox("Seleccione un elemento primero.");
		return;
	}
	
	string dni_datos;
	dni_datos=(m_grilla->GetCellValue(m_grilla->GetGridCursorRow(),1)).c_str();
	m_gestor->GuardarDatosDelAlumno(dni_datos);
	
	HijaVerDatos *win=new HijaVerDatos(this,m_gestor);
	win->Bind(wxEVT_CLOSE_WINDOW, &HijaTabla::OnVerDatosCerrado, this);
	win->Show();
	
}

void HijaTabla::OnVerDatosCerrado(wxCloseEvent& event) { ///Evento close
	RefrescarGrilla();  /// Se actualiza la tabla después de cerrar la ventana
	event.Skip();  /// Permite el cierre CORRECTO de la ventana
}

void HijaTabla::SeleccionPlanes(){
	wxArrayString opciones;
	opciones.Add("Sin filtro");
	for (int i=0;i<m_planes->VerCantidadDePlanes();i++){
		wxString plan=m_planes->VerPlan(i);
		opciones.Add(plan);
	}
	seleccion_filtro->Append(opciones);
}
