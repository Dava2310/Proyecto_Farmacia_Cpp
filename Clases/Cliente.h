#ifndef CLIENTE_H
#define CLIENTE_H

using namespace std;

#include <string>
#include <vector>

#include "Producto.h"
#include "Compra.h"

class Cliente {

    private:
        // Atributos del cliente
        string nombre; // 20 caracteres 20 - 6 = 14
        string apellido; // 20 caracteres 20 - 8 = 12
        int edad; // 5 caracteres 5 - 4 = 1
        string cedula; // 9 caracteres 9 - 6 = 3
        float estatura; // 9 - 8 = 1
        float peso; // 6 caracteres 6 - 4 = 2
        float dineroCuenta; // Dinero en Cuenta 18 - 16 = 2
        vector<Compra*> lista_compra;
    public:
        // Constructor
        Cliente(string nombre, string apellido, int edad, string cedula, float estatura, float peso, float dineroCuenta);
        void incluirProducto(Producto *obj_producto, int cantidadUnidades);
        void limpiarLista();
        float sacarCuenta();
        void retirarDinero(float);
        void depositarDinero(float);
        // Setters
        void setNombre(const string &nombre);
        void setApellido(const string &nombre);
        void setEdad(int edad);
        void setCedula(const string &cedula);
        void setEstatura(float estatura);
        void setPeso(float peso);
        void setDineroCuenta(float dinero);
        // Getters
        string getNombre();
        string getApellido();
        int getEdad();
        string getCedula();
        float getEstatura();
        float getPeso();
        float getDinero();
};

#endif