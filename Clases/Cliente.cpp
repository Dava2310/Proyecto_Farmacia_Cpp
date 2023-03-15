// Archivo fuente de la implementacion de la clase
#include "Cliente.h"
#include "Producto.h"
#include "Compra.h"

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

void Cliente::incluirProducto(Producto *obj_producto, int cantidadUnidades){

    Compra *nueva_compra = new Compra(obj_producto, cantidadUnidades);

    if (nueva_compra == NULL)
    {   
        cout << "Error al agregar el nuevo item a la lista de la compra." << endl;
        return;
    }

    // Proceso para añadir un producto
    this->lista_compra.push_back(nueva_compra);

}


void Cliente::limpiarLista(){


    // Descontar para cada producto, la cantidad de unidades especificada 
    
    // Recorriendo la lista de compra
    for (int i = 0; i < this->lista_compra.size(); i++)
    {
        Compra *tempCompra = this->lista_compra.at(i);

        Producto *tempProducto = tempCompra->getProducto();
        int cantidadUnidades  = tempCompra->getUnidades();

        // Descontar la cantidad de productos
        tempProducto->descontarProducto(cantidadUnidades);

        // Sacando la deuda parcial
        float deudaParcial = tempProducto->getPrecio() * cantidadUnidades;

        // Descontando esa deuda del dinero
        this->retirarDinero(deudaParcial);
    }
    
    // Terminado el proceso, se limpia la lista
    this->lista_compra.clear();
}

float Cliente::sacarCuenta(){

    float cuenta = 0;

    // Recorrer cada producto de la lista de compra
    for (int i = 0; i < this->lista_compra.size(); i++) {

        int cantidadUnidades = this->lista_compra.at(i)->getUnidades();
        float precio = this->lista_compra.at(i)->getProducto()->getPrecio();

        cuenta += cantidadUnidades * precio;

    }

    return cuenta;
}

void Cliente::retirarDinero(float monto)
{
    // Se resta del monto por parametro al dinero en cuenta
    this->dineroCuenta -= monto;
}

void Cliente::depositarDinero(float monto)
{
    // Se aumenta del monto por parametro al dinero en cuenta
    this->dineroCuenta += monto; 
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