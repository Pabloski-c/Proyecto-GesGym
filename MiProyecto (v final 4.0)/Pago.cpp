#include "Pago.h"

Pago::Pago(){}
Pago::Pago(int p,Fecha fp,string pl,string m):m_pago(p),fecha_pago(fp),plan(pl),MetodoDePago(m){}

int Pago::VerPago(){
	return m_pago;
}

Fecha Pago::VerFecha(){
	return fecha_pago;
}

string Pago::VerPlan(){
	return plan;
}

string Pago::VerMetodoDePago(){
	return MetodoDePago;
}
