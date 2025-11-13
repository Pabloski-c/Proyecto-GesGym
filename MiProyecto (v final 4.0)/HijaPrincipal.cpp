#include "HijaPrincipal.h"
#include "HijaAgregar.h"
#include "HijaTabla.h"
#include <wx/msgdlg.h>
#include "Gestor_Alumnos.h"
#include "Alumno.h"
#include <wx/wx.h>
#include <string>
#include "Gestor_Planes.h"
#include "HijaPlanes.h"

HijaPrincipal::HijaPrincipal(Gestor_Alumnos *gestor, Gestor_Planes *planes) : Principal(nullptr), m_gestor(gestor),m_planes(planes){
	m_gestor->CargarDatos();
}

void HijaPrincipal::ClickAgregar( wxCommandEvent& event )  {
	HijaAgregar *win = new HijaAgregar(this, m_gestor, m_planes); ///Ventana agregar
	win->Show();
}

void HijaPrincipal::ClickTabla( wxCommandEvent& event )  {
	HijaTabla *win = new  HijaTabla(this, m_gestor,m_planes); ///Ventana tabla
	win->Show();
}

void HijaPrincipal::ClickSalir( wxCommandEvent& event )  {
	Close();
}


void HijaPrincipal::ClickIngresoDNI( wxCommandEvent& event ) {
	
	string dni_str = ingreso_dni->GetValue().ToStdString();
	
	if (dni_str.length() != 8 || !all_of(dni_str.begin(), dni_str.end(), ::isdigit)) {
		wxMessageBox("Ingrese un DNI de 8 dígitos numéricos.");
		return;
	}
	
	int dni;
	try {
		dni = stoi(dni_str);
	} catch (invalid_argument&) {
		wxMessageBox("Ingrese un DNI válido (solo números).");
		return;
	} catch (out_of_range&) {
		wxMessageBox("El DNI ingresado es demasiado grande.");
		return;
	}
	
	auto alumno_opt = m_gestor->VerAlumno(dni);
	if (!alumno_opt) {
		wxMessageBox("No se encontró un alumno con ese DNI.");
		return;
	}
	
	Alumno alumno = *alumno_opt;
	
	Fecha fecha_hoy = ObtenerFechaActual();
	alumno.ModUltimoIngreso(fecha_hoy);
	alumno.AgregarIngreso(fecha_hoy);
	
	if (!alumno.VerEstado()) {
		alumno.ActualizarEstado(fecha_hoy);
	}
	
	m_gestor->ActualizarAlumno(dni, alumno);
	
	wxString info = "DNI: " + to_string(dni) +
		"\nEstado: " + alumno.VerEstadoSTR() +
		"\nÚltimo ingreso: " + alumno.VerFechaUltimoIngresoSTR();
	
	wxMessageBox(info, "Información del Alumno");
	
	m_gestor->CargarDatos();
	ingreso_dni->Clear();

}

void HijaPrincipal::ClickPlanes( wxCommandEvent& event )  {
	HijaPlanes *win = new HijaPlanes(this,m_planes);
	win->Show();
}

