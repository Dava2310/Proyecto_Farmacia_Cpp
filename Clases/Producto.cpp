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
        cout << "\nIngrese la enfermedad #" << numeroEnfermedad << " que cubre el medicamento: ";
        cin.ignore();
        getline(cin, enfermedad);

        this->enfermedades_cubre.push_back(enfermedad);

        cout << "\nDesea agregar otra enfermedad? (Y/N): ";
        cin >> opcion;
        cout << endl;

        if (!(opcion == "Y" || opcion == "y")) {
            llenado = false;
        } 
    }
}

void Producto::ListarEnfermedades()
{

    string enfermedad;

    if (this->enfermedades_cubre.size() < 1)
    {
        cout << "Hubo un error, no se ha asignado ninguna enfermedad" << endl;
        return;
    }
    cout << "\n\t\t Lista de Enfermedades que cubre el medicamento: " << this->nombre << endl << endl;

    // Encabezado de la tabla
    cout << "+-----------------+----------------------------------------+" << endl;
    cout << "|Num. Enfermedad  |Enfermedad                              |" << endl;
    cout << "+-----------------+----------------------------------------+" << endl;

    for (int i = 0; i < this->enfermedades_cubre.size(); i++) 
    {
        
        enfermedad = this->enfermedades_cubre.at(i);

        // Imprimir el numero de la enfermedad en la lista
        cout << "|";
        cout << (i + 1);

        if ( (i+1) < 10)
        {
            for (int j = 0; j < 16; j++)
                cout << " ";
        }
        else if ( (i+1) >= 10)
        {
            for (int j = 0; j < 15; j++)
                cout << " ";
        } 
        cout << "|";

        // Imprimir la enfermedad especifica o el nombre de la misma 
        cout << enfermedad;

        for (int j = 0; j < 40 - enfermedad.length(); j++)
            cout << " ";

        cout << "|" << endl;
    }
    cout << "+-----------------+----------------------------------------+" << endl << endl;
}

void Producto::descontarProducto(int cantidadRequerida){

    if (this->cantidadProducto < cantidadRequerida) {
        cout << "No existe la cantidad requerida de este producto";
        return;
    }

    cout << "\nDescontando: " << cantidadRequerida << " unidad(es) del producto: " << this->codigo << endl << endl;
    this->cantidadProducto -= cantidadRequerida;
}

void Producto::agregarProductos(int cantidad)
{   
    // Sumando la cantidad por parametro ya verificada anteriormente en el main, a la cantidad del producto de este objeto de la clase
    cout << "\nAgregando: " << cantidad << " unidad(es) al producto: " << this->codigo << endl << endl;
    this->cantidadProducto += cantidad;
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

int Producto::getCantidad()
{
    return this->cantidadProducto;
}