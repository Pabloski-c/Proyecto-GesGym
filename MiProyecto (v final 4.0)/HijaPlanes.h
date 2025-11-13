#ifndef HIJAPLANES_H
#define HIJAPLANES_H
#include "wxfb_project.h"
#include "HijaPlanes.h"
#include "Gestor_Alumnos.h"
#include "Gestor_Planes.h"

class HijaPlanes : public Planes {
	
private:
	
protected:
	void ClickModificar( wxCommandEvent& event )  override;
	void ClickAgregar( wxCommandEvent& event )  override;
	void ClickEliminar( wxCommandEvent& event )  override;
	void ClickSalir( wxCommandEvent& event )  override;
	void RefrescarGrilla();
	Gestor_Planes *m_planes;
	
public:
	void OnCerrado(wxCloseEvent& event);
	HijaPlanes(wxWindow *parent, Gestor_Planes *planes);
};

#endif

