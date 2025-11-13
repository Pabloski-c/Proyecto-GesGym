#ifndef GESTOR_ALUMNOS_H
#define GESTOR_ALUMNOS_H

#include "Alumno.h"
#include <vector>
using namespace std;

Fecha ObtenerFechaActual();

class Gestor_Alumnos {
public:
	Gestor_Alumnos(string a);
	
	void AgregarAlumno(Alumno x);
	void EliminarAlumno(int pos);
	void ActualizarAlumno(int DNI,Alumno x);
	Alumno* VerAlumno(int DNI);
	
	///adicional
	void GuardarArchivo(); ///Guarda los datos del vector en el archivo
	void CargarUnSoloDato(Alumno aux);
	void CargarDatos(); ///se utiliza en el constructor para leer el archivo
	void ObtenerAlumnosPorPlan(string plan);
	int VerCantidadAlumnos();
	Alumno VerAlumnoPorPosicion(int i);
	vector<Alumno> ObtenerListaAlumnos();
	bool ExisteEsteAlumno(Alumno x);
	bool AnioBisiesto(int anio);
	void UsarRespaldo();
	bool ValidarDatos(Alumno aux);
	bool EsSoloLetras(string texto);
	void GuardarDatosDelAlumno(string dni);
	void ModificarAlumno(string nombre, string apellido, string plan, string sexo, string mail, int dni, int telefono);
	///Ordenar
	void OrdenarSegunCriterio(string criterio);
	void CargarBackupInicial();
	Alumno Verm_backup();
	void EliminarAlumnoPorDNI(int dni);
	
	
private:
	float m_precio_cuota;
	vector<Alumno> m_lista;///puntero para poder utilizarlo en todo el programa.
	Alumno m_backup;
	vector<Alumno> backup;
	string m_archivo;
	int backup_dni;
};

#endif

