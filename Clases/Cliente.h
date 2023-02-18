#ifndef CLIENTE_H
#define CLIENTE_H

using namespace std;

#include <string>
#include <vector>
#include "Producto.h"

class Cliente {

    private:
        // Atributos del cliente
        string nombre; // 20 caracteres 20 - 6 = 14
        string apellido; // 20 caracteres 20 - 6 = 14
        int edad; // 5 caracteres 5 - 4 = 1
        string cedula; // 9 caracteres 9 - 8 = 1
        float estatura; // 10
        float peso; // 6 caracteres 6 - 4 = 2
        float dineroCuenta;
        vector<Producto*> lista_compra;
    public:
        // Constructor
        Cliente(string nombre, string apellido, int edad, string cedula, float estatura, float peso, float dineroCuenta);
        void incluirProducto(Producto *obj_producto);
        void limpiarLista();
        float sacarCuenta();
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