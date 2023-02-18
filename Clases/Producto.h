#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <vector>
#include <string>
using namespace std;

class Producto {

    private:
        // Atributos
        string codigo;
        string nombre;
        float precio;
        string descripcion;
        int cantidadProducto;
        vector<string> enfermedades_cubre;
    public:
        // Constructor
        Producto(string codigo, string nombre, float precio, string descripcion, int cantidadProducto);
        void ListarEnfermedades();
        void descontarProducto(int cantidadRequerida);
        // Setters
        void setNombre(const string &nombre);
        void setPrecio(float precio);
        void setDescripcion(const string &descripcion);
        // Getters
        string getCodigo();
        string getNombre();
        float getPrecio();
        string getDescripcion();
        vector<string> getEnfermedades();

};


#endif