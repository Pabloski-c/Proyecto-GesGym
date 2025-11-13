#include "HijaModificarPlanes.h"
#include "Gestor_Planes.h"
#include <wx/msgdlg.h>

HijaModificarPlanes::HijaModificarPlanes(wxWindow *parent, Gestor_Planes *planes) : ModificarPlanes(parent), m_planes(planes) {
	
}

void HijaModificarPlanes::ClickModificarPlan( wxCommandEvent& event )  {
	int costo = atoi(e_costo->GetValue());
	if(costo != 0){
		wxMessageBox("Ingrese un precio valido.");
		return;
	}
	string plan;
	plan = e_plan->GetValue().c_str();
	if(!plan.empty() and !m_planes->EsSoloLetras(plan)){
		wxMessageBox("ingrese un plan valido.");
		return;
	}
	m_planes->ModificarPlan(plan,costo);
}

void HijaModificarPlanes::ClickSalirPlan( wxCommandEvent& event )  {
	Close();
}

HijaModificarPlanes::~HijaModificarPlanes() {
	
}

