#include "HijaPlanes.h"
#include "Gestor_Alumnos.h"
#include "Gestor_Planes.h"
#include "HijaPlanesAgregar.h"
#include "HijaPlanesModificar.h"
#include <wx/msgdlg.h>

HijaPlanes::HijaPlanes(wxWindow *parent, Gestor_Planes *planes) : Planes(parent), m_planes(planes) {
	m_planes->CargarPlanes();
	m_planes->CargarBackupInicial();
	RefrescarGrilla();
	Tabla_P->EnableGridLines(true);
	Tabla_P->SetSelectionMode(wxGrid::wxGridSelectRows);
}

void HijaPlanes::ClickAgregar( wxCommandEvent& event )  {
	HijaPlanesAgregar *win = new HijaPlanesAgregar(this,m_planes);
	win->Bind(wxEVT_CLOSE_WINDOW, &HijaPlanes::OnCerrado, this);
	win->Show();
}

void HijaPlanes::ClickEliminar( wxCommandEvent& event )  {
	
	wxArrayInt FilasSeleccionadas=Tabla_P->GetSelectedRows();
	
	if(FilasSeleccionadas.empty()){
		wxMessageBox("Seleccione un elemento primero.");
		return;
	}
	
	int respuesta=wxMessageBox("Esta seguro que desea eliminar el elemento seleccionado?","Confirmar eliminacion",wxYES_NO | wxICON_QUESTION);
	
	if(respuesta == wxYES){
		for(int i=FilasSeleccionadas.GetCount()-1;i>=0;i--){
			int pos = FilasSeleccionadas[i];
			m_planes->EliminarPlan(pos); ///eliminamos ese alumno
		}
		
		m_planes->CargarPlanes();
		RefrescarGrilla(); ///cargamos nuevamente la tabla
	}
	
}

void HijaPlanes::ClickModificar( wxCommandEvent& event )  {
	
	wxArrayInt FilasSeleccionadas = Tabla_P->GetSelectedRows();
	
	if (FilasSeleccionadas.empty()) {
		wxMessageBox("Seleccione un plan para modificar.");
		return;
	}
	
	int fila = FilasSeleccionadas[0];
	string nombrePlan = Tabla_P->GetCellValue(fila, 0).ToStdString();
	int precioPlan = stoi(Tabla_P->GetCellValue(fila, 1).ToStdString());
	
	HijaPlanesModificar *win = new HijaPlanesModificar(this,m_planes, nombrePlan, precioPlan);
	win->Bind(wxEVT_CLOSE_WINDOW, &HijaPlanes::OnCerrado, this);
	win->Show();
}

void HijaPlanes::ClickSalir( wxCommandEvent& event )  {
	Close();
}

void HijaPlanes::RefrescarGrilla(){
	if(Tabla_P->GetNumberRows()!=0) Tabla_P->DeleteRows(0,Tabla_P->GetNumberRows());
	for(int i=0;i<m_planes->VerCantidadDePlanes();i++){
		Tabla_P->AppendRows();
		Plan p = m_planes->VerPlanPorPosicion(i);
		Tabla_P->SetCellValue(i,0,p.VerPlan());
		Tabla_P->SetCellValue(i,1,to_string(p.VerPrecio()));
	}
}

void HijaPlanes::OnCerrado(wxCloseEvent& event) { ///Evento close
	RefrescarGrilla();  /// Se actualiza la tabla después de cerrar la ventana
	event.Skip();  /// Permite el cierre CORRECTO de la ventana
}
