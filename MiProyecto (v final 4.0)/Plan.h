#ifndef PLAN_H
#define PLAN_H
#include <string>
using namespace std;

class Plan{
private:
	char m_plan[20];
	int precio;
public:
	Plan();
	Plan(string p,int pr);
	string VerPlan();
	bool operator==(Plan b);
	int VerPrecio();
	void ModificarPrecio(int precio_nuevo);
	void ModificarPlan(string plan);
};


#endif
