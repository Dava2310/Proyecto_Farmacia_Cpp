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

int numerosNo_Decimales(float);

// Lista de clientes
vector<Cliente*> listaClientes;

// Lista de productos
vector<Producto*> listaProductos;

int main(){

    crearCliente();
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

    // Primer borde
    bordes();

    // Centro con los titulos
    cout << "|";
    cout << "Nombre";
    for (int i = 0; i < 14; i++) {
        cout << " ";
    }
    cout << "|";
    cout << "Apellido";
    for (int i = 0; i < 12; i++) {
        cout << " ";
    }
    cout << "|";
    cout << "Edad";
    for (int i = 0; i < 1; i++) {
        cout << " ";
    }
    cout << "|";
    cout << "Cedula";
    for (int i = 0; i < 3; i++) {
        cout << " ";
    }
    cout << "|";
    cout << "Estatura";
    for (int i = 0; i < 1; i++) {
        cout << " ";
    }
    cout << "|";
    cout << "Peso";
    for (int i = 0; i < 2; i++) {
        cout << " ";
    }
    cout << "|";
    cout << "Dinero en Cuenta";
    for (int i = 0; i < 2; i++) {
        cout << " ";
    }
    cout << "|" << endl;

    // Segundo borde
    bordes();

    // Recorrido de la lista de clientes
    for (int i = 0; i < listaClientes.size(); i++) 
    {

        Cliente *cliente = listaClientes[i];

        string nombre = cliente->getNombre();
        string apellido = cliente->getApellido();
        int edad = cliente->getEdad();
        string cedula = cliente->getCedula();
        float estatura = cliente->getEstatura();
        float peso = cliente->getPeso();
        float dineroCuenta = cliente->getDinero();

        // Impresion de los resultados

        cout << "|";
        cout << nombre;
        for (int j = 0; j < 20 - nombre.length(); j++) 
        {
            cout << " ";
        }
        cout << "|";

        cout << apellido;
        for (int j = 0; j < 20 - apellido.length(); j++) 
        {
            cout << " ";
        }
        cout << "|";
        
        cout << edad;
        for (int j = 0; j < 3; j++) 
        {
            cout << " ";
        }
        cout << "|";

        cout << cedula;
        for (int j = 0; j < 9 - cedula.length(); j++) 
        {
            cout << " ";
        }
        cout << "|";
        
        printf("%5.2f", estatura);
        int espacios = numerosNo_Decimales(estatura);

        for (int j = 0; j < 6 - espacios; j++) {
            cout << " ";
        }
        cout << "|";

        printf("%3.2f", peso);
        espacios =  numerosNo_Decimales(peso);
        for (int j = 0; j < 3 - espacios; j++) {
            cout << " ";
        }

        // cout << " ";
        cout << "|";

        printf("%10.5f", dineroCuenta);
        // Quedan 13
        espacios = numerosNo_Decimales(dineroCuenta);
        for (int j = 0; j < 12 - espacios; j++) {
            cout << " ";
        }
        cout << "|";
        // cout << "   |";
        cout << endl;
    }

    // Ultimo borde
    bordes();
}

void bordes(){

    cout << "+";
    // Nombre
    for (int i = 0; i < 20; i++) {
        cout << "-";
    }
    cout << "+";
    // Apellido
    for (int i = 0; i < 20; i++) {
        cout << "-";
    }
    // Edad
    cout << "+";
    for (int i = 0; i < 5; i++) {
        cout << "-";
    }
    // Cedula
    cout << "+";
    for (int i = 0; i < 9; i++) {
        cout << "-";
    }
    cout << "+";
    // Estatura
    for (int i = 0; i < 9; i++) {
        cout << "-";
    }
    cout << "+";
    // Peso
    for (int i = 0; i < 6; i++) {
        cout << "-";
    }
    cout << "+";
    // Dinero en cuenta
    for (int i = 0; i < 18; i++) {
        cout << "-";
    }
    cout << "+" << endl;
}

int numerosNo_Decimales(float numero) {

    int cantidadCaracteres = 0;

    string floatStr = to_string(numero);
    int decimalPos = floatStr.find('.');
    cantidadCaracteres = decimalPos;
    // cout << "Cantidad Caracteres: " << cantidadCaracteres << endl;
    return cantidadCaracteres;
}