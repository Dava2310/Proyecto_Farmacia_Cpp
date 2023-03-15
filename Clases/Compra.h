#ifndef COMPRA_H
#define COMPRA_H

#include "Producto.h"
#include <string>
#include <vector>

using namespace std;

class Compra
{   
    public:
        Compra(Producto*, int);
        Producto* getProducto() {return this->obj_producto;}
        int getUnidades() {return this->cantidadUnidades;}
    private:
        Producto *obj_producto;
        int cantidadUnidades;
};

#endif