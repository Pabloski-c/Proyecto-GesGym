#ifndef HIJAMODIFICAR_H
#define HIJAMODIFICAR_H
#include "wxfb_project.h"
#include "Gestor_Alumnos.h"

class HijaModificar : public Modificar {
	
private:
	
protected:
	void ClickAceptar( wxCommandEvent& event )  override;
	void ClickCancelar( wxCommandEvent& event )  override;
	Gestor_Alumnos *m_gestor;
public:
	HijaModificar(wxWindow *parent, Gestor_Alumnos *gestor);
	~HijaModificar();
};

#endif

