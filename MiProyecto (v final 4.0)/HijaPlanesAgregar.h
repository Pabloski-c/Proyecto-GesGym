#ifndef HIJAPLANESAGREGAR_H
#define HIJAPLANESAGREGAR_H
#include "wxfb_project.h"
#include "Gestor_Planes.h"

class HijaPlanesAgregar : public PlanesAgregar {
	
private:
	
protected:
	void ClickSalir( wxCommandEvent& event )  override;
	void ClickAgregar( wxCommandEvent& event )  override;
	Gestor_Planes *m_planes;
	
public:
	HijaPlanesAgregar(wxWindow *parent, Gestor_Planes *planes);
	~HijaPlanesAgregar();
};

#endif

