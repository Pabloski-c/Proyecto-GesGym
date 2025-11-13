#ifndef HIJAVERDATOS_H
#define HIJAVERDATOS_H
#include "wxfb_project.h"
#include "HijaVerDatos.h"
#include "Gestor_Alumnos.h"

class HijaVerDatos : public VerDatos {
	
private:
	
protected:
	void ClickModificar( wxCommandEvent& event )  override;
	void ClickSalir( wxCommandEvent& event )  override;
	Gestor_Alumnos *m_gestor;
public:
	HijaVerDatos(wxWindow *parent,Gestor_Alumnos *gestor);
	void RefrescarGrilla();
	void OnModificarCerrado(wxCloseEvent& event);
	~HijaVerDatos();
};

#endif

