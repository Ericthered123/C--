/*a) Suponer la existencia de una lista de números enteros positivos cuyos nodos se definen como:
struct Nodo {
 int dato;
 Nodo* siguiente;
};
Analizar la siguiente función (sin ejecutarla en la máquina) e indicar qué retorna si la lista pasada por
parámetro contiene los siguientes elementos: 6 - 2 - 8 - 1.
b) ¿Qué debería cambiarse en la función anterior si se intentara obtener el resultado opuesto? En el
ejemplo de la lista con los números 6 - 2 - 8 - 1 se debería obtener el número 1. Se asume que la lista
no contiene valores mayores que 99*/



#include <iostream>
#include <cstring>
#include <cctype>
#include <thread>
#include <chrono>
#include <cmath>

using namespace std;


struct Nodo {
 int dato;
 Nodo* siguiente;
};

int funcion_Max(Nodo* inicio, int M = -1) {
 if (inicio == nullptr)
 return M;
 if (inicio->dato > M)
 M = inicio->dato; //Busca eL mayor numero positivo dentro de la lista y lo devuelve
 return funcion_Max(inicio->siguiente, M);
}

int funcion_Min(Nodo* inicio, int m = 99) {
 if (inicio == nullptr)
 return m;
 if (inicio->dato < m)
 m = inicio->dato; //Busca eL menor numero positivo dentro de la lista y lo devuelve
 return funcion_Min(inicio->siguiente, m);
}

Nodo* create_node(Nodo *inicio,Nodo*nuevo)
{
    nuevo->siguiente=inicio;
    return nuevo;


}
Nodo* start_insertion(Nodo *inicio)
{
    int ejemplo=0;                  
    Nodo *nuevo;
    cout << "Ingresar numero a guardar al principio(0 para cortar): ";
    cin >> ejemplo;
    while (ejemplo!=0)              
    {
        nuevo=new Nodo;
        nuevo->dato=ejemplo;
        inicio=create_node(inicio,nuevo);
        cout << "Ingresar numero a guardar al principio(0 para cortar): ";
        cin >> ejemplo;
        
    }                               
    return inicio;
}

int main()
{
    int max,min;
    Nodo* head=nullptr;
    head=start_insertion(head);
    max=funcion_Max(head);
    min=funcion_Min(head);
    cout<< endl<<"Maximo de la lista= "<< max<< '\t'<< "Minimo de la lista= "<< min;


}