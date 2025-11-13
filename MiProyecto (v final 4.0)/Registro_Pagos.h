#ifndef REGISTRO_PAGOS_H
#define REGISTRO_PAGOS_H
#include "Pago.h"
#include "Alumno.h"

class Registro_Pagos{
private:
	vector<Pago> r_pagos;
	vector<Pago> r_backup;
	Pago p_backup;
	Fecha f_backup;
	string a_pagos;
public:
	Registro_Pagos(string a);
	Pago VerPago(int i);
	void GuardarPagos();
	void CargarPagos();
	
};

#endif
