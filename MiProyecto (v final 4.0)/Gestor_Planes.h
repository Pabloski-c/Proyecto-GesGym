#ifndef GESTOR_PLANES_H
#define GESTOR_PLANES_H

#include "Plan.h"
#include <vector>
using namespace std;

class Gestor_Planes{
private:
	vector<Plan> Lista_Planes;
	string archivoplanes;
	vector<Plan> P_Backup;
	Plan p_backup;
	string n_plan;
public:
	
	Gestor_Planes(string a);
	
	void GuardarPlanes();
	void CargarPlanes();
	void EliminarPlan(int pos);
	void AgregarPlan(Plan a);
	void ModificarPlan(string planViejo, string planNuevo, int pr);
	string VerPlan(int pos);
	int VerPrecio(int pos);
	bool EsSoloLetras(string texto);
	bool ValidarDatos(Plan aux);
	void CargarUnSoloPlan(Plan aux);
	bool ExisteEstePlan(Plan x);
	void ActualizarPlan(string nombre, Plan x);
	int VerCantidadDePlanes();
	Plan VerPlanPorPosicion(int i);
	void CargarBackupInicial();
	void GuardarPlanSeleccionado(string nombre_plan);
};

#endif
