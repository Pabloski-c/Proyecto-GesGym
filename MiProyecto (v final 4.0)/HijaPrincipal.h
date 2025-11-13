#ifndef HIJAPRINCIPAL_H
#define HIJAPRINCIPAL_H
#include "wxfb_project.h"
#include "Gestor_Alumnos.h"
#include "Gestor_Planes.h"

class HijaPrincipal : public Principal {
	
private:

protected:
	void ClickPlanes( wxCommandEvent& event )  override;
	void ClickIngresoDNI( wxCommandEvent& event )  override;
	void ClickSalir( wxCommandEvent& event )  override;
	void ClickTabla( wxCommandEvent& event ) override;
	void ClickAgregar( wxCommandEvent& event )  override;
	Gestor_Alumnos *m_gestor;
	Gestor_Planes *m_planes;
public:
	HijaPrincipal(Gestor_Alumnos *gestor, Gestor_Planes *planes);
};

#endif

