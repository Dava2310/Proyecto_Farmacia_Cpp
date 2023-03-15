#include "Compra.h"
#include "Producto.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Constructor
Compra::Compra(Producto* obj_producto, int cantidad)
{
    this->obj_producto = obj_producto;
    this->cantidadUnidades = cantidad;
}