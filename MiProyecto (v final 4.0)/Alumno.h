#ifndef ALUMNO_H
#define ALUMNO_H

#include <string>
#include <vector>
#include <iostream>
#include "Alumno.h"
using namespace std;

struct Fecha{
	int dia,mes,anio;
	bool operator==(Fecha b){
		return dia==b.dia and mes==b.mes and anio==b.anio;
	}
	ostream &operator<<(ostream &o){
		o<<dia<<"/"<<mes<<"/"<<anio;
		return o;
	}
};

class Alumno{
	
public:
	Alumno();
	Alumno(string nom,string ape,int dni,string sexo,string plan,int telefono,Fecha ingreso,string mail); ///creacion de un alumno
	
	///Metodos para consultar datos
	string VerNombre();
	string VerSexo();
	string VerApellido();
	string VerPlan();
	int VerTelefono();
	int VerDNI();
	Fecha VerFechaIngreso();
	Fecha VerFechaUltimoIngreso(); ///NUEVO
	string VerEmail();
	bool VerEstado(); ///NUEVO
	string VerEstadoSTR(); ///NUEVO
	string VerFechaUltimoIngresoSTR(); ///NUEVO
	Fecha (*VerHistorialIngresos())[10];

	///Metodos para modificar datos
	void ModificarNombre(string nuevo_nombre);
	void ModificarApellido(string nuevo_apellido);
	void ModificarSexo(string nuevo_sexo);
	void ModificarPlan(string nuevo_plan);
	void ModificarTelefono(int nuevo_telefono);
	void ModificarDNI(int nuevo_dni);
	void ModFechaIngreso(Fecha nueva_fecha);
	void ModUltimoIngreso(Fecha nuevo_ingreso);
	void ModificarEstado(bool estado);  ///NUEVO
	void ActualizarEstado(Fecha fecha_actual); ///NUEVO
	void AgregarIngreso(Fecha fecha); ///NUEVO
	void ModificarMail(string nuevo_mail);

	///sobrecargas
	bool operator==(Alumno b);
	
private:
	char m_nombre[20], m_apellido[20], m_plan[20], m_sexo[20], m_mail[40]; ///nombre, apellido y plan
	int m_DNI, m_telefono, m_cantidad_ingresos; ///DNI y telefono
	Fecha m_ingreso,m_ultimo_ingreso, m_historial_ingresos[10]; ///registro de fechas
	bool m_estado;
};

#endif

