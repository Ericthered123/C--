/*Generar una lista enlazada simple con la nómina de artículos de un supermercado. 
De cada artículo se conoce:
código, descripción, precio y stock. La carga finaliza con el código -1. 
Se solicita:

A. Leer de teclado un porcentaje e incrementar el precio de todos los artículos en esa cantidad.

B. Incrementar el stock de un artículo. Se lee de teclado el código y la cantidad con la que se debe
incrementar el stock. Si no existe el artículo en la lista se debe informar.

C. Eliminar de la lista los artículos que no tienen stock.*/

#include <iostream>
#include <cstring>
#include <thread>
#include <chrono>

using namespace std;

struct Articulo
{
    int codigo;
    string descripcion;
    float precio;
    int stock;
};

struct nodo
{
    Articulo articulo;
    nodo* siguiente;
};




int main()
{
    nodo* head=nullptr;



}
