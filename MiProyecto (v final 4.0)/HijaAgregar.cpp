#include "HijaAgregar.h"
#include <string>
#include "Alumno.h"
#include "Gestor_Alumnos.h"
#include <wx/msgdlg.h>
#include "Gestor_Planes.h"
#include <wx/utils.h>
using namespace std;

HijaAgregar::HijaAgregar(wxWindow *parent, Gestor_Alumnos *gestor, Gestor_Planes *planes) : Agregar(parent), m_gestor(gestor), m_planes(planes){
	m_planes->CargarPlanes();
	SeleccionPlanes();
}

void HijaAgregar::ClickAceptar( wxCommandEvent& event ){
	
	string nombre, apellido, mail, sexo, plan;
	int dni, telefono;
	Fecha ingreso;
	///asignacion + validacion
	nombre = entrada_nombre->GetValue().c_str();
	if(nombre.empty() or !m_gestor->EsSoloLetras(nombre)){
		wxMessageBox("Ingrese un nombre valido.");
		return;
	}
	
	apellido = entrada_apellido->GetValue().c_str();
	if(apellido.empty() or !m_gestor->EsSoloLetras(apellido)){
		wxMessageBox("Ingrese un apellido valido.");
		return;
	}
	
	mail = entrada_mail->GetValue().c_str();
	if(mail.empty() or mail.find('@')==string::npos){
		wxMessageBox("Ingrese un email valido.");
		return;
	}
	
	sexo = seleccion_sexo->GetStringSelection().c_str();
	if(sexo!="Masculino" and sexo!="Femenino" and sexo!="Otro"){
		wxMessageBox("Seleccione una opcion valida: Masculino, Femenino u Otro.");
		return;
	}
	
	plan = seleccion_plan->GetStringSelection().c_str();
	if(plan.empty() or !m_gestor->EsSoloLetras(plan)){
		wxMessageBox("Ingrese un plan valido.");
		return;
	}
	
	dni = atoi(entrada_dni->GetValue());
	if(to_string(dni).size()!=8){
		wxMessageBox("Ingrese un DNI de 8 digitos.");
		return;
	}
	
	telefono = atoi(entrada_telefono->GetValue());
	if(to_string(telefono).size()!=7 and telefono!=0){
		wxMessageBox("El telefino debe contener 7 digitos o 0 (cero).");
		return;
	}
	
	ingreso.dia = atoi(entrada_dia->GetValue());
	ingreso.mes = atoi(entrada_mes->GetValue());
	ingreso.anio = atoi(entrada_anio->GetValue());
	if(ingreso.dia<1 or ingreso.dia>31 or ingreso.mes<1 or ingreso.mes>12 or ingreso.anio<1900){
		wxMessageBox("Ingrese una fecha válida.");
		return;
	}
	if((ingreso.mes==4 or ingreso.mes==6 or ingreso.mes==9 or ingreso.mes==11) and ingreso.dia>30){
		wxMessageBox("El mes ingresado no tiene más de 30 días.");
		return;
	}
	if((ingreso.mes==2 and ingreso.dia>28) and !m_gestor->AnioBisiesto(ingreso.anio)){
		wxMessageBox("Febrero no tiene esa cantidad de días.");
		return;
	}
	
	Alumno aux(nombre,apellido,dni,sexo,plan,telefono,ingreso,mail);
	if(m_gestor->ExisteEsteAlumno(aux)){
		wxMessageBox("Este alumno ya existe.");
		return;
	}
	
	///Si el alumno es valido, se carga en el vector y el archivo.
	m_gestor->AgregarAlumno(aux);
	m_gestor->CargarUnSoloDato(aux);
	
	Close();
}

void HijaAgregar::ClickCancelar( wxCommandEvent& event )  {
	Close();
}

void HijaAgregar::SeleccionPlanes(){
	wxArrayString opciones;
	for(int i=0;i<m_planes->VerCantidadDePlanes();i++){
		wxString plan = m_planes->VerPlan(i);
		opciones.Add(plan);
	}
	for(size_t i=0;i<opciones.GetCount();i++){
		seleccion_plan->Append(opciones[i]);
	}
}

