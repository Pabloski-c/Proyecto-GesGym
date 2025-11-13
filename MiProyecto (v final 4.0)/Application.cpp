#include <wx/image.h>
#include "Application.h"
#include "HijaPrincipal.h"
#include <ctime>
#include "Alumno.h"
#include "Gestor_Planes.h"

IMPLEMENT_APP(Application)

bool Application::OnInit() {
	
	m_planes = new Gestor_Planes("Planes.dat"); ///Archivo binario
	m_gestor = new Gestor_Alumnos("BaseAlumnos.dat"); ///Archivo binario
	HijaPrincipal *win = new HijaPrincipal(m_gestor, m_planes); ///Ventana de la app
	win->Show();
	return true;
}

