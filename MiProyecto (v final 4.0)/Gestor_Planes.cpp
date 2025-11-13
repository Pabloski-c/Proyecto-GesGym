#include "Gestor_Planes.h"
#include "Plan.h"

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Gestor_Planes::Gestor_Planes(string a):archivoplanes(a){}

void Gestor_Planes::GuardarPlanes(){
	
	if(Lista_Planes.empty()){
		ofstream vacio(archivoplanes,ios::binary);
		if(!vacio.is_open()){
			cerr<<"No se pudo abrir el archivo: "<<archivoplanes<<endl;
			return;
		}
		vacio.close();
		return;
	}
	
	ofstream archivo(archivoplanes,ios::binary|ios::trunc);
	
	if(!archivo.is_open()){
		cerr<<"No se pudo abrir el archivo: "<<archivoplanes<<endl;
		return;
	}
	
	for(auto &aux:Lista_Planes){
		archivo.write(reinterpret_cast<char*>(&aux), sizeof(Plan));
	}
	archivo.close();
};

void Gestor_Planes::CargarPlanes(){
	
	Lista_Planes.clear();
	ifstream archivo(archivoplanes, ios::binary);
	
	if (!archivo.is_open()) {
		cerr << "No se pudo abrir el archivo: " << archivoplanes << endl;
		return;
	}
	
	Plan aux;
	
	while(archivo.read(reinterpret_cast<char*>(&aux), sizeof(Plan))){
		if(archivo.gcount() != sizeof(Plan)){
			cerr << "Error: Se leyó un tamaño incorrecto del Plan. Archivo posiblemente corrupto." << endl;
			break;
		}
		
		if(ValidarDatos(aux)){
			Lista_Planes.push_back(aux);
		}else{
			cerr<<"PLan invalido detectado: "<<aux.VerPlan()<<endl;
		}
	}
	
	archivo.close();
}


void Gestor_Planes::AgregarPlan(Plan a){
	for(auto plan:Lista_Planes){
		if(plan.VerPlan() == a.VerPlan()){
			throw invalid_argument("Este Plan ya existe");
		}
	}
	Lista_Planes.push_back(a);
}

void Gestor_Planes::EliminarPlan(int pos){
	
	if (Lista_Planes.empty()) return;
	
	auto it = next(Lista_Planes.begin(), pos);
	Lista_Planes.erase(it);
	
	GuardarPlanes();
}

void Gestor_Planes::ModificarPlan(string planViejo, string planNuevo, int pr){
	bool encontrado = false;
	
	for (auto &plan : Lista_Planes) {
		if (plan.VerPlan() == planViejo) {
			if (!planNuevo.empty()) {
				plan.ModificarPlan(planNuevo);
			}
			if (pr > 0) {
				plan.ModificarPrecio(pr);
			}
			
			encontrado = true;
			break;
		}
	}
	
	if (!encontrado) {
		cerr << "Error: No se encontró el plan a modificar." << endl;
		return;
	}
	
	GuardarPlanes();
	CargarPlanes();
}

string Gestor_Planes::VerPlan(int pos){
	return Lista_Planes[pos].VerPlan();
}

bool Gestor_Planes::EsSoloLetras(string texto){
	for(char x:texto){
		if(!isalpha(static_cast<unsigned char>(x)) and x!=' '){
			return false;
		}
	}
	return true;
}

int Gestor_Planes::VerPrecio(int pos){
	return Lista_Planes[pos].VerPrecio();
}

bool Gestor_Planes::ValidarDatos(Plan aux){
	if(aux.VerPlan().empty()){
		return false;
	}
	if(aux.VerPlan().empty()){
		return false;
	}
	
	return true;
}

void Gestor_Planes::CargarUnSoloPlan(Plan aux){
	ofstream archivo(archivoplanes, ios::binary | ios::app);
	if (!archivo.is_open()){
		cerr << "No se pudo abrir el archivo: " << archivoplanes << endl;
		return;
	}
	archivo.write(reinterpret_cast<char*>(&aux), sizeof(aux));
	
	archivo.close();
}

bool Gestor_Planes::ExisteEstePlan(Plan x){
	for(auto plan:Lista_Planes){
		if(plan.VerPlan()==x.VerPlan()){
			return true;
		}
	}
	return false;
}

void Gestor_Planes::ActualizarPlan(string nombre, Plan x){
	
	bool encontrado = false;
	for(auto &plan:Lista_Planes){
		if(plan.VerPlan() == nombre){
			plan = x;
			encontrado = true;
			break;
		}
	}
	
	if(!encontrado){
		cerr << "Error: Plan no encontrado en la lista." << endl;
		return;
	};
	
	GuardarPlanes();
}

int Gestor_Planes::VerCantidadDePlanes(){
	return Lista_Planes.size();
}

Plan Gestor_Planes::VerPlanPorPosicion(int i){
	return Lista_Planes[i];
}

void Gestor_Planes::CargarBackupInicial(){
	P_Backup = Lista_Planes;
}

void Gestor_Planes::GuardarPlanSeleccionado(string nombre_plan) {
	for (auto &plan : Lista_Planes) {
		if (plan.VerPlan() == nombre_plan) {
			p_backup = plan;  ///Guardamos el plan antes de modificarlo
			return;
		}
	}
	cerr << "Error: No se encontró el plan a modificar." << endl;
}

