

#include <iostream>
#include <cstring>
#include <chrono>
#include <thread>

using namespace std;

struct nodo
{
    int dato;
    nodo* siguiente;
};
//--------------------------------------------------------------------------------------------------------------------------
// IN CIRCULAR LISTS THE POINTER STORED IN THE STACK, COULD BE POINTING AT THE FIRST ELEMENT OR THE LAST ELEMENT OF THE LIST
// THE LATTER IS RECOMMENDED BECAUSE OF THE FUNCTIONALITIES OF IT
// 'LIFO' INSERTION AND 'COLA' INSERTION FOR CIRCULAR LISTS
//--------------------------------------------------------------------------------------------------------------------------

nodo* insert_at_circular_end(nodo* end,nodo* nuevo)
{ 
    if (end == nullptr)
    {
    nuevo->siguiente = nuevo;
    }
    else
    {
    nuevo->siguiente = end->siguiente;
    end->siguiente = nuevo;
    }   
    return nuevo;
}


nodo* insert_at_circular_start(nodo* end, nodo* nuevo)
{
    if (end == nullptr)
    {
    nuevo->siguiente = nuevo;
    return nuevo;
    }
    else    
    {
    nuevo->siguiente = end->siguiente;
    end->siguiente = nuevo;
    return end;
    }

}
//---------------------------------------------------------------------------------------------
// GO THROUGH CIRCULAR LISTS, DIFFERENT CRITERIA COULD BE USED BASED ON THE CONTEXT OF THE CODE

void print_circular_list(nodo *end)
{   
    if (end != nullptr)
    {
    nodo* aux = end->siguiente;
    cout << '\t' <<"|Datos Enlazados|"<<endl<<'|';
    do {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << aux->dato<< '|';
    aux = aux->siguiente;
    } 
    while (aux != end->siguiente);
    }
}
//----------------------------------------
// ELIMINATE AN ELEMENT IN A CIRCULAR LIST
nodo* eliminate_element(nodo* fin, int datoABorrar)
{
    if (fin!=nullptr)
    {
    nodo* aux = fin;
    nodo* aEliminar;
    do {
        if (aux->siguiente->dato == datoABorrar)
        {
        aEliminar = aux->siguiente;
        if (aEliminar == fin)
        {
        fin = aux;
        }
        aux->siguiente = aEliminar->siguiente;
        delete aEliminar;
        break;
        }
    else
        aux = aux->siguiente;
    } while (aux != fin);
 }
 return fin;
}