/*Escribir una función recursiva que, dada una lista de enteros, retorne la suma de todos sus elementos. En caso
de que la lista esté vacía, deberá retornar 0.
Ejemplo: si la lista contiene 5 - 2 - 1 - 9 retornará 17.*/



#include <iostream>
#include <cstring>
#include <cctype>
#include <thread>
#include <chrono>
#include <cmath>

using namespace std;


struct nodo
{
    int integer;
    nodo* siguiente;
};


int sum_of_list_elements(nodo* head)
{
    if (head==nullptr)
    {
        return 0;
    }
    else
    {

        return head->integer+sum_of_list_elements(head->siguiente);
    }


}

nodo* create_node(nodo *inicio,nodo*nuevo)
{
    nuevo->siguiente=inicio;
    return nuevo;


}
nodo* start_insertion(nodo *inicio)
{
    int ejemplo=0;                  
    nodo *nuevo;
    cout << "Ingresar numero a guardar al principio(0 para cortar): ";
    cin >> ejemplo;
    while (ejemplo!=0)              
    {
        nuevo=new nodo;
        nuevo->integer=ejemplo;
        inicio=create_node(inicio,nuevo);
        cout << "Ingresar numero a guardar al principio(0 para cortar): ";
        cin >> ejemplo;
        
    }                               
    return inicio;
}


int main()
{
    nodo* head=nullptr;
    head=start_insertion(head);
    cout <<endl <<'\t'<<" The sum of list elements is equal to: "<< sum_of_list_elements(head);



}