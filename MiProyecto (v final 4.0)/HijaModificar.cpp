#include "HijaModificar.h"
#include <wx/msgdlg.h>
#include "HijaTabla.h"
#include "HijaVerDatos.h"

HijaModificar::HijaModificar(wxWindow *parent, Gestor_Alumnos *gestor) : Modificar(parent), m_gestor(gestor) {

}

void HijaModificar::ClickAceptar( wxCommandEvent& event )  {
	string nom, ape, plan, sexo, mail;
	int dni, tel;
	
	nom = e_nombre->GetValue().ToStdString();
	if(!nom.empty() and !m_gestor->EsSoloLetras(nom)){
		wxMessageBox("Ingrese un nombre valido.");
		return;
	}
	ape = e_apellido->GetValue().ToStdString();
	if(!ape.empty() and !m_gestor->EsSoloLetras(ape)){
		wxMessageBox("Ingrese un apellido valido.");
		return;
	}
	plan = e_plan->GetValue().ToStdString();
	if(!plan.empty() and !m_gestor->EsSoloLetras(plan)){
		wxMessageBox("Ingrese un plan valido.");
		return;
	}
	sexo = seleccion_sexo->GetStringSelection().ToStdString();
	if(sexo!="Masculino" and sexo!="Femenino" and sexo!="Otro"){
		wxMessageBox("Seleccione una opcion valida: Masculino, Femenino u Otro.");
		return;
	}
	mail = e_mail->GetValue().ToStdString();
	if(!mail.empty() and mail.find('@')==string::npos){
		wxMessageBox("Ingrese un email valido.");
		return;
	}else{
		if(mail.empty()){
			mail = m_gestor->Verm_backup().VerEmail();
		}
	}
	dni = atoi(e_dni->GetValue());
	if(to_string(dni).size()!=8 and dni !=0){
		wxMessageBox("Ingrese un DNI de 8 digitos.");
		return;
	}
	tel = atoi(e_telefono->GetValue());
	if(to_string(tel).size()!=7 and tel!=0){
		wxMessageBox("El telefino debe contener 7 digitos o 0 (cero).");
		return;
	}
	
	m_gestor->ModificarAlumno(nom, ape, plan, sexo, mail, dni, tel);
	
	m_gestor->CargarDatos();
	
	Close();
}

void HijaModificar::ClickCancelar( wxCommandEvent& event )  {
	Close();
}

HijaModificar::~HijaModificar() {
	
}


