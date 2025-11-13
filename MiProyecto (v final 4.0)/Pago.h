#ifndef PAGOS_H
#define PAGOS_H
#include "Alumno.h"

class Pago{
private:
	int m_pago;
	Fecha fecha_pago;
	string plan;
	string MetodoDePago;
public:
	Pago();
	Pago(int p, Fecha fp, string pl, string m);
	int VerPago();
	Fecha VerFecha();
	string VerPlan();
	string VerMetodoDePago();
	
};


#endif
