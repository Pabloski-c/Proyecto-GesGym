#ifndef HIJAPLANESMODIFICAR_H
#define HIJAPLANESMODIFICAR_H
#include "wxfb_project.h"
#include "HijaPlanesModificar.h"
#include "Gestor_Planes.h"

class HijaPlanesModificar : public PlanesModificar {
	
private:
	
protected:
	void ClickModificar( wxCommandEvent& event )  override;
	void ClickSalir( wxCommandEvent& event )  override;
	Gestor_Planes *m_planes;
	string planOriginal;
	
public:
	HijaPlanesModificar(wxWindow *parent, Gestor_Planes *planes, string nombrePlan, int precioPlan);
	~HijaPlanesModificar();
};

#endif

