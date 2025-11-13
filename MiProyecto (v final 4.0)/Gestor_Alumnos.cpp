#include "Gestor_Alumnos.h"
#include "Alumno.h"

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <ctime>
using namespace std;

///CONSTRUCTORES
Gestor_Alumnos::Gestor_Alumnos(string a):m_archivo(a){}

///GUARDAR
void Gestor_Alumnos::GuardarArchivo(){
	
	if (m_lista.empty()) {
		ofstream vacio(m_archivo,ios::binary);
		if(!vacio.is_open()){
			cerr<<"No se pudo abrir el archivo: "<<m_archivo<<endl;
			return;
		}
		vacio.close();
		return;
	}
	
	ofstream archivo(m_archivo,ios::binary|ios::trunc); ///NUEVO: Se agrego el trunc
	
	if(!archivo.is_open()){
		cerr<<"No se pudo abrir el archivo: "<<m_archivo<<endl;
		return;
	}
	for(auto &aux:m_lista){
		archivo.write(reinterpret_cast<char*>(&aux),sizeof(Alumno)); ///NUEVO: Se cambio aux por Alumn
	}
	archivo.close();
	
}

///FECHA TO CHAR
void Fecha_To_Char(Fecha fecha,char* nueva_fecha){
	stringstream ss;
	ss <<setfill('0')<<setw(2)<<fecha.dia<<"/" 
		<<setw(2)<<fecha.mes<<"/" 
		<<setw(4)<<fecha.anio;
	strncpy(nueva_fecha,ss.str().c_str(), 11);
}

///CARGAR UN SOLO ALUMNO
void Gestor_Alumnos::CargarUnSoloDato(Alumno aux) {
	ofstream archivo(m_archivo, ios::binary | ios::app);
	if (!archivo.is_open()){
		cerr << "No se pudo abrir el archivo: " << m_archivo << endl;
		return;
	}
	archivo.write(reinterpret_cast<char*>(&aux), sizeof(aux));
	
	archivo.close();
	
}

///NUEVO
Fecha ObtenerFechaActual(){
	time_t t=time(nullptr);
	tm* now=localtime(&t);
	Fecha fecha_actual;
	fecha_actual.dia=now->tm_mday;
	fecha_actual.mes=now->tm_mon+1;
	fecha_actual.anio=now->tm_year+1900;
	return fecha_actual;
}

///CARGAR
void Gestor_Alumnos::CargarDatos(){
	
	m_lista.clear();
	ifstream archivo(m_archivo, ios::binary);
	
	if (!archivo.is_open()) {
		cerr << "No se pudo abrir el archivo: " << m_archivo << endl;
		return;
	}
	
	Alumno aux;
	Fecha fecha_actual = ObtenerFechaActual();
	bool hubo_cambios = false;
	
	while (archivo.read(reinterpret_cast<char*>(&aux), sizeof(Alumno))) {
		if (archivo.gcount() != sizeof(Alumno)) {
			cerr << "Error: Se leyó un tamaño incorrecto de Alumno. Archivo posiblemente corrupto." << endl;
			break;
		}
		
		bool estaba_activo = aux.VerEstado();
		aux.ActualizarEstado(fecha_actual);
		
		if (estaba_activo && !aux.VerEstado()) {
			hubo_cambios = true;
		}
		
		if (ValidarDatos(aux)) {
			m_lista.push_back(aux);
		} else {
			cerr << "Alumno inválido detectado: " << aux.VerDNI() << endl;
		}
	}
	
	archivo.close();
	
	if (hubo_cambios) {
		GuardarArchivo();
	}
}

///AGREGAR
void Gestor_Alumnos::AgregarAlumno(Alumno x){
	for(auto alumno:m_lista){
		if(alumno.VerDNI()==x.VerDNI()){
			throw invalid_argument("Este DNI ya existe");
		}
	}
	m_lista.push_back(x);
}

///ELIMINAR
void Gestor_Alumnos::EliminarAlumno(int pos){
	
	if (pos<0||pos>=(int)m_lista.size()) return;
	
	///Obtener el DNI del alumno en la tabla filtrada
	int dni_a_eliminar = m_lista[pos].VerDNI();
	
	///Buscar al alumno en la lista original `backup`
	auto it=find_if(backup.begin(), backup.end(), [&](Alumno& a){
		return a.VerDNI()==dni_a_eliminar;
	});
	
	if(it!= backup.end()){
		backup.erase(it);/// Eliminar del backup
	}
	
	///Actualizar m_lista
	m_lista=backup;
	
	GuardarArchivo();
}

void Gestor_Alumnos::EliminarAlumnoPorDNI(int dni){
	auto it=find_if(backup.begin(), backup.end(), [&](Alumno& a) {
		return a.VerDNI() == dni;
	});
	if (it!=backup.end()) {
		backup.erase(it);
	}
	m_lista=backup;
	GuardarArchivo(); ///Guardar cambios en el archivo binario
}

void Gestor_Alumnos::ObtenerAlumnosPorPlan(string plan){
	if(plan.empty()){
		if (!backup.empty()) {
			m_lista = backup;
			backup.clear();
		}
		///Si el backup esta vacio, se recarga el archivo
		else{
			CargarDatos();
		}
	} else{
		if (backup.empty()){
			backup=m_lista;
		}
		vector<Alumno> listaFiltrada;
		for (Alumno alumno : backup) {
			if (alumno.VerPlan() == plan) {
				listaFiltrada.push_back(alumno);
			}
		}
		m_lista = listaFiltrada;
	}
}

///ACTUALIZAR
void Gestor_Alumnos::ActualizarAlumno(int DNI,Alumno x){
	
	bool encontrado = false;
	for (auto &alumno : m_lista) {
		if (alumno.VerDNI() == DNI) {
			alumno = x;
			encontrado = true;
			break;
		}
	}
	
	if (!encontrado) {
		cerr << "Error: Alumno no encontrado en la lista." << endl;
		return;
	}
	
	GuardarArchivo();
}

///VER ALUMNO, UTILIZANDO DNI COMO STRING
Alumno* Gestor_Alumnos::VerAlumno(int DNI){
	for(auto &alumno:m_lista){
		if(alumno.VerDNI()==DNI){
			return &alumno;
		}
	}
	return nullptr;
}

///Adicionales
bool Gestor_Alumnos::ExisteEsteAlumno(Alumno x){
	for(auto alumno:m_lista){
		if(alumno.VerDNI()==x.VerDNI()){
			return true;
		}
	}
	return false;
}

int Gestor_Alumnos::VerCantidadAlumnos(){
	return m_lista.size();
}

Alumno Gestor_Alumnos::VerAlumnoPorPosicion(int i){
	return m_lista[i];
}

vector<Alumno> Gestor_Alumnos::ObtenerListaAlumnos(){
	return m_lista;
}

bool Gestor_Alumnos::AnioBisiesto(int anio){
	return (anio%4 == 0 && anio%100 != 0) || (anio%400 == 0);
}

///USO DEL RESPALDO
void Gestor_Alumnos::UsarRespaldo(){
	int size = m_lista.size();
	for(size_t i=0;i<backup.size();i++){
		m_lista.push_back(backup[i]); 
	}
	auto it = next(m_lista.begin(),size);
	m_lista.erase(m_lista.begin(),it);
}

void Gestor_Alumnos::CargarBackupInicial(){
	backup=m_lista;
}

bool Gestor_Alumnos::ValidarDatos(Alumno aux){
	if(aux.VerNombre().empty() or aux.VerApellido().empty()){
		return false;
	}
	
	if(aux.VerSexo()!="Masculino" and aux.VerSexo()!="Femenino" and aux.VerSexo()!="Otro"){
		return false;
	}
	
	if(aux.VerPlan().empty()){
		return false;
	}
	
	if(aux.VerDNI()<=0 or to_string(aux.VerDNI()).size()!=8){
		return false;
	}
	
	Fecha ingreso=aux.VerFechaIngreso();
	if(ingreso.dia<1 or ingreso.dia>31 or ingreso.mes<1 or ingreso.mes>12 or ingreso.anio<1900){
		return false;
	}
	if((ingreso.mes==4 or ingreso.mes==6 or ingreso.mes==9 or ingreso.mes==11) and ingreso.dia>30){
		return false;
	}
	
	if((ingreso.mes==2 and ingreso.dia>28) and !AnioBisiesto(ingreso.anio)){
		return false;
	}
	
	return true;
}

bool Gestor_Alumnos::EsSoloLetras(string texto){
	for(char x:texto){
		if(!isalpha(static_cast<unsigned char>(x)) and x!=' '){
			return false;
		}
	}
	return true;
}

bool OrdenarSegunApellido(Alumno a, Alumno b){
	return a.VerApellido()<b.VerApellido();
}

bool OrdenarSegunDNI(Alumno a, Alumno b){
	return a.VerDNI()<b.VerDNI();
}

bool OrdenarSegunPlan(Alumno a, Alumno b){
	return a.VerPlan()<b.VerPlan();
}

void Gestor_Alumnos::OrdenarSegunCriterio(string criterio){
	if(criterio=="Apellido"){
		sort(m_lista.begin(), m_lista.end(), OrdenarSegunApellido);
	}else{
		if(criterio=="DNI"){
			sort(m_lista.begin(), m_lista.end(), OrdenarSegunDNI);
		}else{
			sort(m_lista.begin(), m_lista.end(), OrdenarSegunPlan);
		}
	}
}

void Gestor_Alumnos::GuardarDatosDelAlumno(string DNI){
	stringstream ss(DNI);
	int DNI_AUX;
	ss>>DNI_AUX;
	bool encontrado=false;
	for(auto alumno:m_lista){
		if(alumno.VerDNI()==DNI_AUX){
			m_backup = alumno;
			encontrado=true;
			break;
		}
	}
	if(!encontrado){
		throw invalid_argument("Alumno no se encuentra en la lista");
	}
}

Alumno Gestor_Alumnos::Verm_backup(){return m_backup;}

void Gestor_Alumnos::ModificarAlumno(string nombre, string apellido, string plan, string sexo, string mail, int dni, int telefono){
	bool encontrado = false;
	for (auto &alumno : m_lista) {
		if (alumno.VerDNI() == m_backup.VerDNI()) {
			m_backup = alumno; // Cargar datos actuales antes de modificar
			backup_dni = m_backup.VerDNI();
			encontrado = true;
			break;
		}
	}
	
	if (!encontrado) {
		throw("Error: No se encontró el alumno a modificar.");
		return;
	}
	
	if (!nombre.empty()) m_backup.ModificarNombre(nombre);
	if (!apellido.empty()) m_backup.ModificarApellido(apellido);
	if (!plan.empty()) m_backup.ModificarPlan(plan);
	if (!sexo.empty()) m_backup.ModificarSexo(sexo);
	if (!mail.empty()) m_backup.ModificarMail(mail);
	if (telefono != 0) m_backup.ModificarTelefono(telefono);
	if (dni!=0) m_backup.ModificarDNI(dni);
	
	ActualizarAlumno(backup_dni, m_backup);
	GuardarArchivo();
	CargarDatos();
}
