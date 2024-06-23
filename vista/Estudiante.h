#pragma once
#include "Persona.h"
#include "ConexionBD.h"
#include <iostream>
#include <mysql.h>
#include <string>
using namespace std;
class Estudiante : Persona{
private:
    string codigo;
    int id_estudiante = 0;

public:
    // Constructores
    Estudiante() {}
    Estudiante(string nom, string ape, string dir, int tel, string fn, int id_ts, string cod, int id_e, string ce)
        : Persona(nom, ape, dir, tel, fn, id_ts, ce) {
        codigo = cod;
        id_estudiante = id_e;
    }

    // Métodos set
    void setId_estudiante(int e) { id_estudiante = e; }
    void setCodigo(string c) { codigo = c; }
    void setNombres(string n) { nombres = n; }
    void setApellidos(string a) { apellidos = a; }
    void setDireccion(string d) { direccion = d; }
    void setTelefono(int t) { telefono = t; }
    void setFecha_nacimiento(string f) { fecha_nacimiento = f; }
    void setId_Tipo_sangre(int ts) { id_tipo_sangre = ts; }
    void setCorreo_electronico(string ce) { correo_electronico = ce; }

    // Métodos get
    int getId_estudiante() { return id_estudiante; }
    string getNombre() { return nombres; }
    string getApellidos() { return apellidos; }
    string getDireccion() { return direccion; }
    int getTelefono() { return telefono; }
    string getFecha_nacimiento() { return fecha_nacimiento; }
    int getId_tipo_sangre() { return id_tipo_sangre; }
    string getCorreo_electronico() { return correo_electronico; }

    // Método para crear un registro en la base de datos
    void crear() {
        int q_estado = 0;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();

        if (cn.getConector()) {
            string t = to_string(telefono);
            string id_ts = to_string(id_tipo_sangre);
            // Corrección en la consulta SQL
            string query = "INSERT INTO estudiantes(codigo, nombres, apellidos, direccion, telefono, fecha_nacimiento, id_tipo_sangre, correo_electronico) VALUES ('" + codigo + "', '" + nombres + "', '" + apellidos + "', '" + direccion + "', " + t + ", '" + fecha_nacimiento + "', " + id_ts + ", '" + correo_electronico + "');";
            const char* c = query.c_str();
            q_estado = mysql_query(cn.getConector(), c);

            if (!q_estado) {
                cout << "Ingreso de datos exitoso... " << endl;
            }
            else {
                cout << "------ Consulta fallida -----" << endl;
            }
        }
        else {
            cout << "Conexion fallida" << endl;
        }
        cn.cerrar_conexion();
    }

    // Método para leer los registros de la base de datos
    void leer() {
        int q_estado = 0;
        ConexionBD cn = ConexionBD();
        MYSQL_ROW fila;
        MYSQL_RES* resultado;
        cn.abrir_conexion();

        if (cn.getConector()) {
            cout << "_____________Datos del estudiante___________" << endl;
            string consulta = "SELECT e.id_estudiante AS id, e.codigo, e.nombres, e.apellidos, e.direccion, e.telefono, e.fecha_nacimiento, ts.sangre, e.correo_electronico FROM estudiantes AS e INNER JOIN tipos_sangre AS ts ON e.id_tipo_sangre = ts.id_tipo_sangre;";
            const char* c = consulta.c_str();
            q_estado = mysql_query(cn.getConector(), c);

            if (!q_estado) {
                resultado = mysql_store_result(cn.getConector());
                while ((fila = mysql_fetch_row(resultado))) {
                    cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << "," << fila[8] << endl;
                }
                mysql_free_result(resultado);
            }
            else {
                cout << "XXX Consulta Fallida XXX" << endl;
            }
        }
        else {
            cout << "XXX Fallo la conexión XXX" << endl;
        }
        cn.cerrar_conexion();
    }

    // Método para actualizar un registro en la base de datos
    void actualizar() {
        int q_estado = 0;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();

        if (cn.getConector()) {
            string t = to_string(telefono);
            string id_ts = to_string(id_tipo_sangre);
            string id_e = to_string(id_estudiante);
            string consulta = "UPDATE estudiantes SET codigo = '" + codigo + "', nombres = '" + nombres + "', apellidos = '" + apellidos + "', direccion = '" + direccion + "', telefono = " + t + ", fecha_nacimiento = '" + fecha_nacimiento + "', id_tipo_sangre = " + id_ts + ", correo_electronico = '" + correo_electronico + "' WHERE id_estudiante = " + id_e + ";";
            const char* c = consulta.c_str();
            q_estado = mysql_query(cn.getConector(), c);

            if (!q_estado) {
                cout << "Modificacion de datos exitosa... " << endl;
            }
            else {
                cout << "XXXXXX Consulta fallida XXXXX" << endl;
            }
        }
        else {
            cout << "Conexion fallida" << endl;
        }
        cn.cerrar_conexion();
    }

    // Método para borrar un registro de la base de datos
    void borrar() {
        int q_estado = 0;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();

        if (cn.getConector()) {
            string id_e = to_string(id_estudiante);
            string consulta = "DELETE FROM estudiantes WHERE id_estudiante = " + id_e + ";";
            const char* c = consulta.c_str();
            q_estado = mysql_query(cn.getConector(), c);

            if (!q_estado) {
                cout << "Eliminacion de datos exitosa... " << endl;
            }
            else {
                cout << "XXXXXX Consulta fallida XXXXX" << endl;
            }
        }
        else {
            cout << "Conexion fallida" << endl;
        }
        cn.cerrar_conexion();
    }
};

