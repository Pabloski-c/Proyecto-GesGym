#include "Alumno.h"

#include <stdexcept>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

///Constructores
Alumno::Alumno(){}

Alumno::Alumno(string nom,string ape,int dni,string sexo,string plan,int telefono,Fecha ingreso,string mail)
	:m_telefono(telefono),m_estado(true)
{	
	strncpy(m_nombre, nom.c_str(), sizeof(m_nombre));
	strncpy(m_apellido, ape.c_str(), sizeof(m_apellido));
	strncpy(m_sexo, sexo.c_str(), sizeof(m_sexo));
	strncpy(m_plan, plan.c_str(), sizeof(m_plan));
	m_DNI=dni;
	m_ingreso=ingreso;
	m_ultimo_ingreso=ingreso;
	strncpy(m_mail, mail.c_str(), sizeof(m_mail));
}

///Consultar datos
string Alumno::VerNombre(){return string(m_nombre);}
string Alumno::VerSexo(){return string(m_sexo);}
string Alumno::VerApellido(){return string(m_apellido);}
string Alumno::VerPlan(){return string(m_plan);}
int Alumno::VerTelefono(){return m_telefono;}
int Alumno::VerDNI(){return m_DNI;}
Fecha Alumno::VerFechaIngreso(){return m_ingreso;}
Fecha Alumno::VerFechaUltimoIngreso(){return m_ultimo_ingreso;} ///Nuevo
string Alumno::VerEmail(){return m_mail;}
Fecha (*Alumno::VerHistorialIngresos())[10]{return &m_historial_ingresos;}
/// NUEVO
bool Alumno::VerEstado(){
	return m_estado;
}
///NUEVO
string Alumno::VerEstadoSTR(){
	if(m_estado){
		return "Activo";
	}else{
		return "Inactivo";
	}
}
///NUEVO
string Alumno::VerFechaUltimoIngresoSTR(){
	string aux;
	aux=to_string(VerFechaUltimoIngreso().dia)+'/'+to_string(VerFechaUltimoIngreso().mes)+'/'+to_string(VerFechaUltimoIngreso().anio);
	return aux;
}

///Metodos para modificar datos
void Alumno::ModificarNombre(string nuevo_nombre){
	strncpy(m_nombre, nuevo_nombre.c_str(),sizeof(m_nombre)-1);
	m_nombre[sizeof(m_nombre)-1]='\0';
}
void Alumno::ModificarApellido(string nuevo_apellido){
	strncpy(m_apellido, nuevo_apellido.c_str(), sizeof(m_apellido)-1);
	m_apellido[sizeof(m_apellido)-1]='\0';
}
void Alumno::ModificarSexo(string nuevo_sexo){
	strncpy(m_sexo, nuevo_sexo.c_str(), sizeof(nuevo_sexo));
}
void Alumno::ModificarPlan(string nuevo_plan){
	strncpy(m_plan, nuevo_plan.c_str(), sizeof(nuevo_plan));
}
void Alumno::ModificarTelefono(int nuevo_telefono){m_telefono=nuevo_telefono;}
void Alumno::ModificarDNI(int nuevo_dni){m_DNI=nuevo_dni;}
void Alumno::ModificarMail(string nuevo_mail){
	memset(m_mail, 0, sizeof(m_mail));/// Limpiar la cadena
	strncpy(m_mail, nuevo_mail.c_str(), sizeof(m_mail) - 1);
	m_mail[sizeof(m_mail)-1]='\0';
}
void Alumno::ModFechaIngreso(Fecha nueva_fecha){m_ingreso=nueva_fecha;}
void Alumno::ModUltimoIngreso(Fecha nuevo_ingreso){m_ultimo_ingreso=nuevo_ingreso;}
void Alumno::ModificarEstado(bool estado){
	m_estado=estado;
}
///NUEVO
void Alumno::ActualizarEstado(Fecha fecha_actual){
	if (fecha_actual.anio-m_ultimo_ingreso.anio>1){ ///SI PASO MAS DE 1 ANIO, CAMBIA A INACTIVO
		m_estado=false;
	}else{
		m_estado=true;
	}
}
///NUEVO
void Alumno::AgregarIngreso(Fecha fecha){
	if (m_cantidad_ingresos<10){
		m_historial_ingresos[m_cantidad_ingresos++]=fecha;
	}
}

///Sobrecargas
bool Alumno::operator==(Alumno b){
	return this->VerDNI() == b.VerDNI();
}
