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
#include "Clases/Compra.h"

using namespace std;

// ======================== OPERACIONES PARA: CLIENTE ======================== ||
void crearCliente();
void listarClientes();
void cambiarDatos(Cliente*);
Cliente* encontrarCliente(const string &cedula);
void depositar_retirar(Cliente*);
void agregar_al_Carrito(Cliente*);

// ======================== OPERACIONES PARA: PRODUCTO ======================== ||
void crearProducto();
void listarProductos();
void cambiarDatos(Producto*);
Producto* encontrarProducto(const string &codigo);
void agregarProducto(Producto*);

// ======================== AGREGADOS ======================== ||
void bordes();
int numerosNo_Decimales(float);

// ======================== ESTRUCTURAS DE DATOS PRINCIPALES ======================== ||
vector<Cliente*> listaClientes;
vector<Producto*> listaProductos;

// ======================== FUNCION PRINCIPAL DEL SISTEMA ======================== ||
int main()
{

    int opcion, salir = 0;
    string cedula;
    string codigo;

    Cliente *obj_cliente;
    Producto *obj_producto;

    // Bienvenida al sistema
    cout << "\t\t Bienvenido al sistema de Farmacia" << endl;

    // Ciclo principal del sistema
    do
    {

        system("pause");
        system("cls");      // Limpiar pantalla

        // Items del menu
        cout << "\t\t MENU PRINCIPAL DEL SISTEMA " << endl << endl;
        cout << "1- Crear un cliente" << endl;
        cout << "2- Listar los clientes del sistema" << endl;
        cout << "3- Cambiar los datos de un cliente" << endl;
        cout << "4- Crear un producto" << endl;
        cout << "5- Listar los productos" << endl;
        cout << "6- Cambiar los datos de un producto (nombre, precio, descripcion)" << endl;
        cout << "7- Depositar o Retirar dinero a la cuenta del cliente en la farmacia" << endl;
        cout << "8- Agregar unidades a un producto en especifico." << endl;
        cout << "9- Hacer una compra." << endl;
        cout << "10- Salir del sistema" << endl << endl;

        cout << "Ingrese una opcion del 1 al 10: ";
        cin >> opcion;
        cout << endl;

        switch(opcion)
        {
            case 1:
                crearCliente();
                break;
            case 2:
                listarClientes();
                break;
            case 3:
                cout << "Ingrese la cedula del cliente: ";
                cin >> cedula;
                cout << endl;

                obj_cliente = encontrarCliente(cedula);

                if (obj_cliente == NULL)
                {
                    cout << "No hay ningun cliente con la cedula indicada." << endl << endl;
                    break;
                }
                
                cambiarDatos(obj_cliente);
                break;
            case 4:
                crearProducto();
                break;
            case 5:
                listarProductos();
                break;
            case 6:
                cout << "Ingrese el codigo del producto: ";
                cin >> codigo;
                cout << endl;

                obj_producto = encontrarProducto(codigo);

                if (obj_producto == NULL)
                {
                    cout << "No hay ningun producto con el codigo ingresado." << endl;
                    break;
                }

                cambiarDatos(obj_producto);
                break;
            case 7:
                cout << "Ingrese la cedula del cliente: ";
                cin >> cedula;
                cout << endl;

                obj_cliente = encontrarCliente(cedula);

                if (obj_cliente == NULL)
                {
                    cout << "No hay ningun cliente con al cedula indicada." << endl << endl;
                    break;
                }

                depositar_retirar(obj_cliente);
                break;
            case 8:
                cout << "Ingrese el codigo del producto: ";
                cin >> codigo;
                cout << endl;

                obj_producto = encontrarProducto(codigo);

                if (obj_producto == NULL)
                {
                    cout << "No hay ningun producto con el codigo ingresado." << endl;
                    break;
                }

                agregarProducto(obj_producto);
                break;
            case 9:
                cout << "Ingrese la cedula del cliente: ";
                cin >> cedula;
                cout << endl;

                obj_cliente = encontrarCliente(cedula);

                if (obj_cliente == NULL)
                {
                    cout << "No hay ningun cliente con al cedula indicada." << endl << endl;
                    break;
                }

                agregar_al_Carrito(obj_cliente);
                break;
            case 10:
                cout << "SALIENDO DEL SISTEMA" << endl << endl;
                break;
            default:
                cout << "Ingrese una opcion valida del 1 al 10" << endl << endl;
        }
    }while(opcion != 10);

    cout << "Muchas gracias por usar el sistema de farmacia." << endl;
    return 0;
}

// ======================== OPERACIONES PARA: CLIENTE ======================== ||

void crearCliente()
{

    /*
        1- Recoger los datos necesarios para el cliente
        2- Crear el objeto cliente
        3- Asignarlo al vector de clientes
    */

    // Variables necesarias
    string nombre, apellido, cedula;
    float edad, estatura, peso, dineroCuenta;

    // Recoleccion de datos
    cout << "\n\t\tIngrese los datos del cliente a registrar: " << endl << endl;
    cout << "Cedula: "; cin >> cedula;

    // Se verifica que no se consiga ningun objeto tipo cliente con la cedula ingresada
    if (encontrarCliente(cedula) != NULL) {
        
        cout << "Ya existe un cliente con la cedula: " << cedula << endl << endl;
        return;

    }
    
    // Resto de la recoleccion
    cout << "Primer nombre: "; cin >> nombre;
    cout << "Primer apellido: "; cin >> apellido;
    
    cout << "Edad: "; cin >> edad;
    if (edad < 18)
    {
        cout << "El cliente no puede ser menor de edad." << endl << endl;
        return;
    }

    cout << "Estatura(cm): "; cin >> estatura;
    if (estatura <= 0)
    {
        cout << "La estatura ingresada no es valida." << endl << endl;
        return;
    }

    cout << "Peso(Kg): "; cin >> peso;
    if (peso <= 0 || peso >= 1000)
    {
        cout << "El peso ingresado no es valido." << endl << endl; 
        return;
    }

    cout << "Ingrese el dinero($) que tiene el cliente: "; cin >> dineroCuenta;
    if (dineroCuenta < 0)
    {
        cout << "El dinero ingresado no es valido." << endl << endl;
        return;
    }

    // Crear el objeto cliente
    Cliente *obj_cliente = new Cliente(nombre, apellido, edad, cedula, estatura, peso, dineroCuenta);

    // Verificacion si el objeto ha sido creado correctamente
    if (obj_cliente == NULL) {
        cout << "ERROR: No se pudo crear el cliente." << endl << endl;
        return;
    }

    // Asignar el estudiante al vector general de clientes
    listaClientes.push_back(obj_cliente);
}

Cliente* encontrarCliente(const string &cedula) 
{

    // Recorrer la lista de clientes
    for (int i = 0; i < listaClientes.size(); i++) {
        
        // Obtener el cliente de la posicion actual en la lista
        Cliente *temp = listaClientes.at(i);

        // Si la cedula del cliente actual es igual a la cedula de referencia por parametro
        // se devuelve ese objeto
        if (temp->getCedula() == cedula) {
            return temp;
        }
    }

    return NULL;
}

void listarClientes()
{

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
        cout << "|";

        printf("%8.5f", dineroCuenta);
        // Quedan 13
        espacios = numerosNo_Decimales(dineroCuenta);
        for (int j = 0; j < 12 - espacios; j++) {
            cout << " ";
        }
        cout << "|";
        cout << endl;
    }

    // Ultimo borde
    bordes();
}

void cambiarDatos(Cliente *obj_cliente)
{
    char opcion = 'Y';
    string nombre;
    string apellido;
    int edad;
    float estatura;
    float peso;

    cout << "\n\t\t PROCESO PARA CAMBIAR DATOS DEL CIENTE: " << obj_cliente->getNombre() << " " << obj_cliente->getApellido() << " C.I: " << obj_cliente->getCedula() << "." << endl << endl;

    cout << "Desea cambiar el nombre? (Y/N): ";
    cin >> opcion;
    cout << endl;
    
    if (opcion == 'Y')
    {
        cout << "Ingrese el nuevo nombre: ";
        cin >> nombre;
        cout << endl;

        obj_cliente->setNombre(nombre);
    }

    cout << "Desea cambiar el apellido? (Y/N): ";
    cin >> opcion;
    cout << endl;

    if (opcion == 'Y')
    {
        cout << "Ingrese el nuevo apellido: ";
        cin >> apellido;
        cout << endl;

        obj_cliente->setApellido(apellido);
    }

    cout << "Desea cambiar la edad? (Y/N): ";
    cin >> opcion;
    cout << endl;

    if (opcion == 'Y')
    {
        cout << "Ingrese la nueva edad: ";
        cin >> edad;
        cout << endl;
        
        if (edad < 18)
        {
            cout << "El cliente no puede ser menor de edad" << endl << endl;
        }
        else
        {
            obj_cliente->setEdad(edad);
        }
    }

    cout << "Desea cambiar la estatura? (Y/N): ";
    cin >> opcion;
    cout << endl;

    if (opcion == 'Y')
    {
        cout << "Ingrese la nueva estatura: ";
        cin >> estatura;
        cout << endl;
        
        if (estatura <= 0)
        {
            cout << "La estatura ingresada no es valida." << endl << endl;
        }
        else
        {
            obj_cliente->setEstatura(estatura);
        }
    }

    cout << "Desea cambiar el peso? (Y/N): ";
    cin >> opcion;
    cout << endl;

    if (opcion == 'Y')
    {
        cout << "Ingrese el nuevo peso: ";
        cin >> peso;
        cout << endl;
        
        if (peso <= 0 || peso >= 1000)
        {
            cout << "El peso ingresado no es valido." << endl << endl; 
        }
        else
        {
            obj_cliente->setPeso(peso);
        }
    }

    cout << "Terminado el proceso de cambiar los datos disponibles." << endl << endl;
}

void depositar_retirar(Cliente *obj_cliente)
{   
    int opcion;
    float monto;
    cout << "\n\t\t PROCESO DE RETIRO O DEPOSITO PARA EL CLIENTE: " << obj_cliente->getNombre() << " " << obj_cliente->getApellido() << " C.I: " << obj_cliente->getCedula() << "." << endl << endl;

    cout << "Ingrese 1 para RETIRAR, ingrese 2 para DEPOSITAR: ";
    cin >> opcion;
    cout << endl;

    // Opcion para RETIRAR
    if (opcion == 1)
    {   
        cout << "Ingrese la cantidad que desea retirar: ";
        cin >> monto;
        cout << endl;

        if (monto < 0)
        {
            cout << "El monto no puede ser negativo." << endl;
            return;
        }

        // Se verifica que la cantidad a retirar sea menor o igual al dinero en cuenta del cliente
        if (monto > obj_cliente->getDinero())
        {
            cout << "El cliente no posee tal cantidad de dinero en su cuenta." << endl;
            return;
        }
        
        // Se procede a realizar el retiro
        obj_cliente->retirarDinero(monto);
        cout << "Dinero actual en cuenta: $" << obj_cliente->getDinero() << "." << endl;
        return;
    }

    // Opcion para DEPOSITAR
    if (opcion == 2)
    {
        cout << "Ingrese la cantidad a depositar: ";
        cin >> monto;
        cout << endl;

        if (monto < 0)
        {
            cout << "El monto no puede ser negativo." << endl;
            return;
        }

        // Se procede a realizar el deposito
        obj_cliente->depositarDinero(monto);
        cout << "Dinero actual en cuenta: $" << obj_cliente->getDinero() << "." << endl;
        return;
    }

    cout << "Ha ingresado un numero invalido." << endl;
}

void agregar_al_Carrito(Cliente *obj_cliente)
{

    /*
        Mientras el usuario quiera, agregar un producto
        Para cada producto, tengo que buscarlo con el codigo
        Cuando lo tengamos, lo agregamos a la lista de compra con las unidades
        Despues de que el ingrese todo, se compra o no se compra
    */

    cout << "\n\t\t AGREGANDO CARRITOS A LA LISTA DE COMPRA" << endl << endl;

    // Hacer un ciclo que sea hasta que el usuario quiera
    char opcion = 'Y';
    string codigo;
    Producto *temp;
    int cantidadUnidades;
    float deposito;

    do
    {

        cout << "Ingrese el codigo del producto a agregar: ";
        cin >> codigo;
        cout << endl;

        temp = encontrarProducto(codigo);

        // Tengo un objeto valido
        if (temp != NULL)
        {
            cout << "Ingrese la cantidad de unidades a comprar de ese producto: ";
            cin >> cantidadUnidades;
            
            if (temp->getCantidad() < cantidadUnidades)
            {
                cout << "No existe cantidad suficiente." << endl;
                return;
            }

            obj_cliente->incluirProducto(temp, cantidadUnidades);
        }

        cout << "Desea agregar otros productos a su lista de compra? (Y/N): ";
        cin >> opcion;

    }while(opcion == 'Y');
    
    // Indicar el total de cuenta
    float deuda = obj_cliente->sacarCuenta();

    if (obj_cliente->getDinero() < deuda)
    {
        cout << "No tiene dinero suficiente. Desea depositar en este momento? (Y/N): ";
        cin >> opcion;

        // La persona deniega el deposito, y no puede pagar la deuda
        if (opcion != 'Y')
        {   
            cout << "La compra no se pudo finalizar." << endl;
            return;
        }
        else if (opcion == 'Y')
        {
            
            cout << "\nIngrese la cantidad a depositar: ";
            cin >> deposito;

            if (deposito <= 0)
            {
                cout << "El deposito es invalido." << endl;
                return;
            }
            
            obj_cliente->depositarDinero(deposito);

            if (obj_cliente->getDinero() < deuda)
            {
                cout << "Su deposito no fue suficiente. Se ha cancelado la compra." << endl;
                return;
            }

            // Hacer la compra
            obj_cliente->limpiarLista();
            return;
        }
    }

    // Hacer la compra
    obj_cliente->limpiarLista();
}   

// ======================== OPERACIONES PARA: PRODUCTO ======================== ||

void crearProducto() 
{

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

    // Se verifica que no se consiga ningun objeto con el codigo anteriormente ingresado
    if (encontrarProducto(codigo) != NULL) {

        cout << "Ya existe un producto con el codigo: " << codigo << endl << endl;
        return;
    }

    cout << "Nombre del producto: "; 
    cin.ignore(); 
    getline(cin, nombre);

    cout << "Descripcion: "; 
    cin.ignore();
    getline(cin, descripcion);

    cout << "Precio: "; cin >> precio;
    if (precio <= 0)
    {
        cout << "El precio del producto no es valido." << endl << endl;
        return;
    }

    cout << "Indique la cantidad disponible de este producto: "; cin >> cantidadProducto;
    if (cantidadProducto <= 0)
    {
        cout << "La cantidad del producto no es valida." << endl << endl;
        return;
    }

    // Crear el objeto producto
    Producto *obj_producto = new Producto(codigo, nombre, precio, descripcion, cantidadProducto);

    // Verificar que el objeto se haya creado correctamente
    if (obj_producto == NULL) {
        cout << "ERROR: No se pudo crear el producto." << endl << endl;
        return;
    }

    // Asignando el objeto a la lista de objetos de la misma clase
    listaProductos.push_back(obj_producto);
}

Producto* encontrarProducto(const string &codigo) 
{

    // Recorrer la listsa de productos
    for (int i = 0; i < listaProductos.size(); i++) {
        
        // Obtener el producto de la posicion actual en la lista
        Producto *temp = listaProductos.at(i);

        // Si el codigo del producto es igual al codigo de referencia por parametro
        // se devuelve ese objeto
        if (temp->getCodigo() == codigo) {
            return temp;
        }
    }

    return NULL;
}

void cambiarDatos(Producto *obj_producto)
{
    char opcion = 'Y';
    string nombre;
    float precio;
    string descripcion;

    cout << "\n\t\t PROCESO PARA CAMBIAR DATOS DEL PRODUCTO: " << obj_producto->getNombre() << " (" << obj_producto->getCodigo() << ")" << endl << endl;

    cout << "Desea cambiar el nombre? (Y/N): ";
    cin >> opcion;
    cout << endl;

    if (opcion == 'Y')
    {
        cout << "Ingrese el nuevo nombre: ";
        cin.ignore();
        getline(cin, nombre);
        cout << endl;

        obj_producto->setNombre(nombre);
    }

    cout << "Desea cambiar el precio? (Y/N): ";
    cin >> opcion;
    cout << endl;
    
    if (opcion == 'Y')
    {
        cout << "Ingrese el nuevo precio: ";
        cin >> precio;
        cout << endl;

        if (precio <= 0)
        {
            cout << "El precio es invalido." << endl;
        }
        else
        {
            obj_producto->setPrecio(precio);
        }
    }

    cout << "Desea cambiar la descripcion? (Y/N): ";
    cin >> opcion;
    cout << endl;

    if (opcion == 'Y')
    {
        cout << "Ingrese la nueva descripcion: ";
        cin.ignore();
        getline(cin, descripcion);
        cout << endl;

        obj_producto->setDescripcion(descripcion);
    }

    cout << "Terminando el proceso de cambiar los datos disponibles al producto." << endl << endl;
}

void agregarProducto(Producto *obj_producto)
{   
    int cantidad;
    cout << "\n\t\t PROCESO PARA AGREGAR UNIDADES AL PRODUCTO: " << obj_producto->getNombre() << " Codigo: " << obj_producto->getCodigo() << "." << endl << endl;

    cout << "Ingrese la cantidad que desea agregar: ";
    cin >> cantidad;
    cout << endl;

    if (cantidad <= 0)
    {   
        cout << "La cantidad a agregar es invalida." << endl;
        return;
    }

    // Agregando la cantidad al producto
    obj_producto->agregarProductos(cantidad);
    cout << "El producto: " << obj_producto->getNombre() << " Codigo: " << obj_producto->getCodigo() << " ahora tiene: " << obj_producto->getCantidad()  << " unidad(es)." << endl;
}

void listarProductos()
{
    if (listaProductos.size() < 0)
    {
        cout << "No hay productos registrados." << endl;
        return;
    }

    cout << "\n\t\tLista de Productos: " << endl << endl;

    for (int i = 0; i < listaProductos.size(); i++)
    {
        Producto *temp = listaProductos.at(i);

        cout << "========================================================================" << endl;

        cout << "Codigo del producto: " << temp->getCodigo() << endl;
        cout << "Nombre del producto: " << temp->getNombre() << endl;
        cout << "Precio del producto: $" << temp->getPrecio() << endl;
        cout << "Descripcion del producto: " << temp->getDescripcion() << endl;
        cout << "Cantidad disponible de unidades: " << temp->getCantidad() << " unidad(es)" << endl;
        cout << "\n\t\t Lista de enfermedades que cubre: " << endl;

        vector<string> listaEnfermedades = temp->getEnfermedades();

        for (int j = 0; j < listaEnfermedades.size(); j++)
        {
            cout << listaEnfermedades.at(j);
            
            if (j != listaEnfermedades.size() - 1)
                cout << " | ";
        }
        cout << endl;

        cout << "========================================================================" << endl;
    }
    cout << endl;
}

// ======================== AGREGADOS ======================== ||

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