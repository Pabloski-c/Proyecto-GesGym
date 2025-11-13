#ifndef APPLICATION_H
#define APPLICATION_H

#include <wx/app.h>
#include "Gestor_Alumnos.h"
#include "Gestor_Planes.h"

class Application : public wxApp {
	Gestor_Alumnos *m_gestor; ///Puntero que de tipo gestor
	Gestor_Planes *m_planes; ///Puntero que de tipo plan
public:
	virtual bool OnInit();
};

#endif
