/*Dos sucursales de Fiestísima disponen cada una de una lista enlazada simple con el detalle de las ventas
realizadas. De cada venta se conoce: código de producto y cantidad vendida (un producto pudo haber sido
vendido 0, 1 o más veces en la misma sucursal). Las listas de ventas están ordenadas de menor a mayor por
código de producto. Realizar una función que reciba las dos listas y retorne una nueva lista unificando todas las
ventas, ordenada por el mismo criterio. 
Utilizar un algoritmo destructivo (que reutilice los nodos de las listas
originales). Agregar las funciones auxiliares que sean necesarias. */



#include <iostream>
#include <cstring>
#include <thread>
#include <chrono>

using namespace std;

struct venta_P
{
    int code_P;
    int quantity_sold;
};

struct nodo
{
    venta_P venta;
    nodo* siguiente;

};

void space_jump()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    for (int i = 0; i < 20; i++)
    {
        cout << endl;
    }
}

bool verify_wish()
{
    int eleccion=2;
    while (eleccion!=0&&eleccion!=1)
    {
    cout << "Desea seguir con la carga?"<<endl;        
    cout << "[0] NO"<<endl;
    cout << "[1] SI"<<endl;
    cout << "Ingresar eleccion: ";
    cin >>eleccion;
    if (eleccion<0||eleccion>1)
    {
        cout << "VUELVA A INGRESAR SU ELECCION..."<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        continue;
    }
    }
    if (eleccion==1)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void print_list_of_sold_items(nodo *inicio)
{   
    int i=1;
    cout << '\t' <<"|SOLD ITEMS|"<<endl;
    for (nodo  *aux = inicio; aux!=nullptr; aux=aux->siguiente)
    {
        cout << "Producto "<< i <<"-";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << "|Codigo= " << aux->venta.code_P<< " Cantidad vendida= "<< aux->venta.quantity_sold << '|';
        cout <<endl;
        i++;
        
    }
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

int verify_code(nodo* inicio,int codigo_nuevo)
//TODO this can get better, verification not working for second element
{
     
    for (nodo*aux = inicio; aux!=nullptr; aux=aux->siguiente)
        {
            if (aux->venta.code_P==codigo_nuevo)
            {
                cout << " Ese codigo ya esta en la lista..."<<endl;
                std::this_thread::sleep_for(std::chrono::seconds(5));
                cout << "Ingrese otro codigo: ";
                cin >> codigo_nuevo;
                aux=inicio;
            }
                
        }
    
    return codigo_nuevo;
}


nodo* charge_of_sold_items(nodo* head)
{
    nodo *nuevo;
    venta_P venta;
    cout << "Ingresar codigo del producto : ";
    cin >> venta.code_P;
    while (verify_wish())
    {
        


    }
}