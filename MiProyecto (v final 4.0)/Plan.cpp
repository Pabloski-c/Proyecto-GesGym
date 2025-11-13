#include "Plan.h"
#include <string>
#include <cstring>
using namespace std;

Plan::Plan(){}

Plan::Plan(string p, int pr): precio(pr){
	strncpy(m_plan, p.c_str(), sizeof(m_plan));
}

string Plan::VerPlan(){return string(m_plan);}
int Plan::VerPrecio(){return precio;}


bool Plan::operator==(Plan b){
	return this->VerPlan() == b.VerPlan();
}

void Plan::ModificarPlan(string plan){
	strncpy (m_plan, plan.c_str(), sizeof(m_plan)-1);
	m_plan[sizeof(m_plan)-1]='\0';
}

void Plan::ModificarPrecio(int precio_nuevo){
	precio = precio_nuevo;
}
