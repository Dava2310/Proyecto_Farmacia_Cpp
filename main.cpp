/*

    Descripcion del sistema:

*/

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

// Librerias de clases
#include "Clases/Cliente.h"
#include "Clases/Producto.h"

using namespace std;

// Procedimientos y funciones del sistema
void crearCliente();
void crearProducto();
void listarClientes();
void bordes();
bool encontrarCliente(const string &cedula);
bool encontrarProducto(const string &codigo);
// Lista de clientes
vector<Cliente*> listaClientes;

// Lista de productos
vector<Producto*> listaProductos;

int main(){

    crearCliente();
    listarClientes();
    system("pause");
    return 0;
}

void crearCliente(){

    /*
        1- Recoger los datos necesarios para el cliente
        2- Crear el objeto cliente
        3- Asignarlo al vector de clientes
    */

    // Variables necesarias
    string nombre, apellido, cedula;
    float edad, estatura, peso, dineroCuenta;

    // Recoleccion de datos
    cout << "\t\tIngrese los datos del cliente a registrar: " << endl << endl;
    cout << "Cedula: "; cin >> cedula;

    if (encontrarCliente(cedula)) {

        cout << "Ya existe un cliente con la cedula: " << cedula << endl << endl;
        return;

    }

    cout << "Nombre: "; cin >> nombre;
    cout << "Apellido: "; cin >> apellido;
    
    cout << "Edad: "; cin >> edad;
    cout << "Estatura: "; cin >> estatura;
    cout << "Peso: "; cin >> peso;
    cout << "Ingrese el dinero que tiene el cliente: "; cin >> dineroCuenta;

    // Crear el objeto cliente
    Cliente *obj_cliente = new Cliente(nombre, apellido, edad, cedula, estatura, peso, dineroCuenta);

    // Asignar el estudiante al vector general de clientes
    if (obj_cliente == NULL) {
        cout << "ERROR: No se pudo crear el cliente." << endl << endl;
        return;
    }

    listaClientes.push_back(obj_cliente);
}

void crearProducto() {

    /*
        1- Recoger los datos necesarios para el producto
        2- Crear el objeto producto
        3- Asignarlo al vector de productos
    */

    // Variables necesarias
    string codigo, nombre, descripcion;
    float precio;
    int cantidadProducto;

    cout << "\t\t INGRESE LOS DATOS DEL PRODUCTO: " << endl << endl;
    
    cout << "Ingrese el codigo del producto: "; cin >> codigo;

    if (encontrarProducto(codigo)) {

        cout << "Ya existe un producto con el codigo: " << codigo << endl << endl;
        return;
    }

    cout << "Nombre: "; cin >> nombre;
    cout << "Descripcion: "; cin >> descripcion;
    cout << "Precio: "; cin >> precio;
    cout << "Indique la cantidad disponible de este producto: "; cin >> cantidadProducto;

    // Crear el objeto producto
    Producto *obj_producto = new Producto(codigo, nombre, precio, descripcion, cantidadProducto);

    if (obj_producto == NULL) {
        cout << "ERROR: No se pudo crear el producto." << endl << endl;
        return;
    }

    listaProductos.push_back(obj_producto);
}

bool encontrarCliente(const string &cedula) {

    bool respuesta = false;

    // Recorrer la lista de clientes
    for (int i = 0; i < listaClientes.size(); i++) {

        if (listaClientes.at(i)->getCedula() == cedula) {
            return true;
        }

    }

    return respuesta;

}

bool encontrarProducto(const string &codigo) {

    bool respuesta = false;

    // Recorrer la listsa de productos
    for (int i = 0; i < listaProductos.size(); i++) {

        if (listaProductos.at(i)->getCodigo() == codigo) {
            return true;
        }

    }

    return respuesta;
}

void listarClientes(){

    cout << "\t\tLISTADO DE ESTUDANTES " << endl << endl;

    for (int i = 0; i < listaClientes.size(); i++) {

        cout << "Nombre: " << listaClientes.at(i)->getNombre() << endl;
        cout << "Apellido: " << listaClientes.at(i)->getApellido() << endl;
        cout << "Edad: " << listaClientes.at(i)->getEdad() << endl;
        cout << "Cedula: " << listaClientes.at(i)->getCedula() << endl;
        cout << "Estatura: " << listaClientes.at(i)->getEstatura() << endl;
        cout << "Peso: " << listaClientes.at(i)->getPeso() << endl;
        cout << "Dinero: " << listaClientes.at(i)->getDinero() << endl;
    }
    

}

void bordes(){

    cout << "+";
    for (int j = 0; j < 20; j++)
    {
        cout << "-";
    }
    cout << "+";
    for (int j = 0; j < 20; j++)
    {
        cout << "-";
    }
    cout << "+";
    for (int j = 0; j < 10; j++)
    {
        cout << "-";
    }
    cout << "+";
    for (int j = 0; j < 5; j++)
    {
        cout << "-";
    }
    cout << "+";
    for (int j = 0; j < 9; j++)
    {
        cout << "-";
    }
    cout << "+";
    for (int j = 0; j < 6; j++)
    {
        cout << "-";
    }
    cout << "+" << endl;

}