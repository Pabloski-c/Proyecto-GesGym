#ifndef HIJATABLA_H
#define HIJATABLA_H
#include "wxfb_project.h"
#include "Gestor_Alumnos.h"
#include "Gestor_Planes.h"
using namespace std;

class HijaTabla : public Tabla {
	
private:
	Gestor_Alumnos *m_gestor;
	Gestor_Planes *m_planes;
protected:
	void ClickVerDatos( wxCommandEvent& event )  override;
	void ClickOrdenar( wxCommandEvent& event )  override;
	void ClickBuscar( wxCommandEvent& event )  override;
	void ClickFiltrar( wxCommandEvent& event )  override;
	void ClickEliminar( wxCommandEvent& event )  override;
	void ClickSalir( wxCommandEvent& event )  override;
	void RefrescarGrilla();
	void SeleccionPlanes();
public:
	HijaTabla(wxWindow *parent, Gestor_Alumnos *gestor, Gestor_Planes *planes);
	void OnVerDatosCerrado(wxCloseEvent& event);
};

#endif

