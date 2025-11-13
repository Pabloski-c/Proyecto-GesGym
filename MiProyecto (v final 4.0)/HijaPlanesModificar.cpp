#include "HijaPlanesModificar.h"
#include "Gestor_Planes.h"
#include <wx/msgdlg.h>

HijaPlanesModificar::HijaPlanesModificar(wxWindow *parent, Gestor_Planes *planes, string nombrePlan, int precioPlan) 
	: PlanesModificar(parent), m_planes(planes), planOriginal(nombrePlan) {
	e_plan->SetValue(nombrePlan);
	e_costo->SetValue(to_string(precioPlan));
}

void HijaPlanesModificar::ClickModificar( wxCommandEvent& event )  {
	int costo = atoi(e_costo->GetValue());
	if (costo <= 0) {
		wxMessageBox("Ingrese un precio válido.");
		return;
	}
	
	string planNuevo = e_plan->GetValue().ToStdString();
	if (!planNuevo.empty() && !m_planes->EsSoloLetras(planNuevo)) {
		wxMessageBox("Ingrese un plan válido.");
		return;
	}
	
	/// Si el usuario cambió el nombre del plan, lo modificamos
	if (planNuevo != planOriginal) {
		m_planes->ModificarPlan(planOriginal, planNuevo, costo);
	} else {
		m_planes->ModificarPlan(planOriginal, "", costo);
	}
	
	m_planes->GuardarPlanes();
	m_planes->CargarPlanes();
	
	Close();
}

void HijaPlanesModificar::ClickSalir( wxCommandEvent& event )  {
	Close();
}

HijaPlanesModificar::~HijaPlanesModificar() {
	
}

