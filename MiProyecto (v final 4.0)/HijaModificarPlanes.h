#ifndef HIJAMODIFICARPLANES_H
#define HIJAMODIFICARPLANES_H
#include "wxfb_project.h"
#include "Gestor_Planes.h"

class HijaModificarPlanes : public ModificarPlanes {
	
private:
	
protected:
	void ClickModificarPlan( wxCommandEvent& event )  override;
	void ClickSalirPlan( wxCommandEvent& event )  override;
	Gestor_Planes *m_planes;
	
public:
	HijaModificarPlanes(wxWindow *parent, Gestor_Planes *planes);
	~HijaModificarPlanes();
};

#endif

