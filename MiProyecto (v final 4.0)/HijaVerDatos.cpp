#include "HijaVerDatos.h"
#include "HijaModificar.h"

HijaVerDatos::HijaVerDatos(wxWindow *parent, Gestor_Alumnos *gestor) : VerDatos(parent),m_gestor(gestor) {
	RefrescarGrilla();
}

HijaVerDatos::~HijaVerDatos() {
	
}

void HijaVerDatos::RefrescarGrilla(){
	if(m_grilla->GetNumberRows()!=0) m_grilla->DeleteRows(0,m_grilla->GetNumberRows());
	m_grilla->AppendRows();
	Alumno a = m_gestor->Verm_backup();
	m_grilla->SetCellValue(0,0,a.VerApellido()+", "+a.VerNombre());
	m_grilla->SetCellValue(0,1,to_string(a.VerDNI()));
	m_grilla->SetCellValue(0,2,a.VerSexo());
	m_grilla->SetCellValue(0,3,a.VerPlan());
	m_grilla->SetCellValue(0,4,to_string(a.VerTelefono()));
	m_grilla->SetCellValue(0,5,a.VerEmail());
	m_grilla->SetCellValue(0, 6, a.VerEstadoSTR());
}

void HijaVerDatos::ClickSalir( wxCommandEvent& event )  {
	Close();
}

void HijaVerDatos::ClickModificar( wxCommandEvent& event )  {
	HijaModificar *win = new HijaModificar(this, m_gestor);
	win->Bind(wxEVT_CLOSE_WINDOW, &HijaVerDatos::OnModificarCerrado, this); ///Evento close, Metodo(Refrescar y cerrar), la tabla
	win->Show();
	
}

void HijaVerDatos::OnModificarCerrado(wxCloseEvent& event) {
	RefrescarGrilla();  /// Se actualiza la tabla después de cerrar la ventana
	event.Skip();  /// Permite el cierre CORRECTO de la ventana (evita problemas)
}

