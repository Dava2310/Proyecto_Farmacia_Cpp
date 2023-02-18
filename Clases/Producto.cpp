// Archivo fuente de la implementacion de la clase
#include "Cliente.h"
#include "Producto.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Constructor
Producto::Producto(string codigo, string nombre, float precio, string descripcion, int cantidadProducto){

    this->codigo = codigo;
    this->nombre = nombre;
    this->precio = precio;
    this->descripcion = descripcion;
    this->cantidadProducto = cantidadProducto;
    // Llenado de la lista de enfermedades

    bool llenado = true;
    string enfermedad;
    string opcion;
    int numeroEnfermedad = 0;

    while(llenado) {

        numeroEnfermedad++;
        cout << "Ingrese la enfermedad #" << numeroEnfermedad << " que cubre el medicamento: ";
        cin >> enfermedad;

        this->enfermedades_cubre.push_back(enfermedad);

        cout << "\nDesea agregar otra enfermedad? (Y/N)";
        cin >> opcion;

        if (!(opcion == "Y" || opcion == "y")) {

            llenado = false;

        } 
    }
}

void Producto::ListarEnfermedades(){

    if (enfermedades_cubre.size() < 0)
    {
        cout << "Hubo un error, no se ha asignado ninguna enfermedad" << endl;
        return;
    }
    cout << "\t\t Lista de Enfermedades que cubre el medicamento: " << this->nombre << endl << endl;

    for (int i = 0; i < this->enfermedades_cubre.size(); i++) {

        cout << "#" << (i+1) << " Enfermedad:" << this->enfermedades_cubre.at(i) << endl;

    }
}

void Producto::descontarProducto(int cantidadRequerida){

    if (this->cantidadProducto < cantidadRequerida) {
        cout << "No existe la cantidad requerida de este producto";
        return;
    }

    this->cantidadProducto -= cantidadRequerida;

}

// Setters

void Producto::setNombre(const string &nombre){

    this->nombre = nombre;

}

void Producto::setPrecio(float precio) {

    this->precio = precio;

}

void Producto::setDescripcion(const string &descripcion) {

    this->descripcion = descripcion;

}

// Getters

string Producto::getNombre(){

    return this->nombre;

}

float Producto::getPrecio(){

    return this->precio;

}

string Producto::getDescripcion(){

    return this->descripcion;

}

vector<string> Producto::getEnfermedades(){

    return this->enfermedades_cubre;

}

string Producto::getCodigo(){

    return this->codigo;

}