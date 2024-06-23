
#include <iostream>
#include "Estudiante.h"
using namespace std;

int main(){
	string codigo, nombres, apellidos, direccion, fecha_nacimiento, correo_electronico;
	int telefono = 0, id_tipo_sangre = 0, id_estudiante = 0;
	cout << "ingrese codigo: ";
	cin >> codigo;
	cin.ignore();
	cout << "ingrese Nombres: ";
	getline(cin, nombres);
	cout << "ingrese Apellidos: ";
	getline(cin, apellidos);
	cout << "ingrese Direccion: ";
	getline(cin, direccion);
	cout << "ingrese Telefono: ";
	cin >> telefono;
	cin.ignore();
	cout << "ingrese Fecha_Nacimiento: ";
	getline(cin, fecha_nacimiento);
	cout << "ingrese Tipo_sangre: ";
	cin >> id_tipo_sangre;
	cout << "ingrese correo_electronico: ";
	cin >> correo_electronico;

	Estudiante e = Estudiante(nombres, apellidos, direccion, telefono, fecha_nacimiento, id_tipo_sangre, codigo, id_estudiante, correo_electronico);
	e.crear();
	e.leer();




	//actualizacion
	cout << "ingrese el ID a modificar: ";
	cin >> id_estudiante;
	cout << "ingrese codigo: ";
	cin >> codigo;
	cin.ignore();
	cout << "ingrese Nombres: ";
	getline(cin, nombres);
	cout << "ingrese Apellidos: ";
	getline(cin, apellidos);
	cout << "ingrese Direccion: ";
	getline(cin, direccion);
	cout << "ingrese Telefono: ";
	cin >> telefono;
	cin.ignore();
	cout << "ingrese Fecha_Nacimiento: ";
	getline(cin, fecha_nacimiento);
	cout << "ingrese Tipo_sangre: ";
	cin >> id_tipo_sangre;
	cin.ignore();
	cout << "ingrese correo_electronico: ";
	cin >> correo_electronico;


	e.setId_estudiante(id_estudiante);
	e.setCodigo(codigo);
	e.setNombres(nombres);
	e.setApellidos(apellidos);
	e.setDireccion(direccion);
	e.setTelefono(telefono);
	e.setFecha_nacimiento(fecha_nacimiento);
	e.setId_Tipo_sangre(id_tipo_sangre);
	e.setCorreo_electronico(correo_electronico);

	e.actualizar();
	e.leer();

	cout << "ingrese el ID a eliminar: ";
	cin >> id_estudiante;
	e.setId_estudiante(id_estudiante);
	e.borrar();
	e.leer();

}

