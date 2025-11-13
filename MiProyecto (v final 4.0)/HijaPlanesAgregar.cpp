#include "HijaPlanesAgregar.h"
#include <wx/msgdlg.h>

HijaPlanesAgregar::HijaPlanesAgregar(wxWindow *parent, Gestor_Planes *planes) : PlanesAgregar(parent), m_planes(planes) {
	
}

void HijaPlanesAgregar::ClickAgregar( wxCommandEvent& event )  {
	int costo = atoi(e_costo->GetValue());
	string plan;
	plan = e_plan->GetValue().c_str();
	if(!plan.empty() and !m_planes->EsSoloLetras(plan)){
		wxMessageBox("ingrese un plan valido.");
		return;
	}
	Plan p(plan, costo);
	if(m_planes->ExisteEstePlan(p)){
		wxMessageBox("Este plan ya existe.");
		return;
	}
	
	m_planes->AgregarPlan(p);
	m_planes->GuardarPlanes();
	
	Close();
}

HijaPlanesAgregar::~HijaPlanesAgregar() {
	
}

void HijaPlanesAgregar::ClickSalir( wxCommandEvent& event )  {
	Close();
}

