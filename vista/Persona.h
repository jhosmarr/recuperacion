#pragma once
#include <iostream>
using namespace std;
class Persona{
	// atributos
protected: string nombres, apellidos, direccion, fecha_nacimiento, correo_electronico;
		 int telefono = 0, id_tipo_sangre = 0;
		 // Constructor
		 Persona() {}
		 Persona(string nom, string ape, string dir, int tel, string fn, int id_ts, string ce) {
			 nombres = nom;
			 apellidos = ape;
			 direccion = dir;
			 telefono = tel;
			 fecha_nacimiento = fn;
			 id_tipo_sangre = id_ts;
			 correo_electronico = ce;
		 }
		 // Metodos
};

