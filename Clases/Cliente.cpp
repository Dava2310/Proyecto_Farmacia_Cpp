// Archivo fuente de la implementacion de la clase
#include "Cliente.h"
#include "Producto.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Constructor
Cliente::Cliente(string nombre, string apellido, int edad, string cedula, float estatura, float peso, float dineroCuenta) {

    // Se le dan los valores al objeto
    this->nombre = nombre;
    this->apellido = apellido;
    this->edad = edad;
    this->cedula = cedula;
    this->estatura = estatura;
    this->peso = peso;
    this->dineroCuenta = dineroCuenta;

}

// Metodos publicos

void Cliente::incluirProducto(Producto *obj_producto){

    // Proceso para añadir un producto
    this->lista_compra.push_back(obj_producto);

}


void Cliente::limpiarLista(){

    this->lista_compra.clear();

}

float Cliente::sacarCuenta(){

    float cuenta = 0;

    // Recorrer cada producto de la lista de compra
    for (int i = 0; i < this->lista_compra.size(); i++) {

        cuenta += this->lista_compra.at(i)->getPrecio();

    }

    return cuenta;
}

// Setters

void Cliente::setNombre(const string &nombre){

    this->nombre = nombre;

}

void Cliente::setApellido(const string &apellido) {

    this->apellido = apellido;

}

void Cliente::setEdad(int edad) {

    this->edad = edad;

}

void Cliente::setCedula(const string &cedula) {

    this->cedula = cedula;

}

void Cliente::setEstatura(float estatura) {

    this->estatura = estatura;

}

void Cliente::setPeso(float peso) {

    this->peso = peso;

} 

void Cliente::setDineroCuenta(float dinero) {

    this->dineroCuenta = dinero;

}

// Getters

string Cliente::getNombre() {

    return this->nombre;

}

string Cliente::getApellido() {

    return this->apellido;

}

int Cliente::getEdad(){

    return this->edad;

}

string Cliente::getCedula(){

    return this->cedula;

}

float Cliente::getEstatura(){

    return this->estatura;

}

float Cliente::getPeso(){

    return this->peso;

}

float Cliente::getDinero() {

    return this->dineroCuenta;

}