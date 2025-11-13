#ifndef HIJAAGREGAR_H
#define HIJAAGREGAR_H
#include "wxfb_project.h"
#include "Gestor_Alumnos.h"
#include "Gestor_Planes.h"

class HijaAgregar : public Agregar {
	
private:
	Gestor_Alumnos *m_gestor;
	Gestor_Planes *m_planes;
protected:
	void SeleccionPlanes();
	void ClickAceptar( wxCommandEvent& event )  override;
	void ClickCancelar( wxCommandEvent& event )  override;
public:
	HijaAgregar(wxWindow *parent, Gestor_Alumnos *gestor, Gestor_Planes *planes);

};

#endif

