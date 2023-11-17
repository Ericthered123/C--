#include <iostream>
#include <cstring>
#include <cctype>
#include <thread>
#include <chrono>
#include <cmath>

using namespace std;



//Analizar el programa siguiente (sin ejecutarlo en la máquina) e indicar cómo queda la lista luego de la
//ejecución.

struct Nodo {
 int dato;
 Nodo* siguiente;
};

Nodo* e(Nodo* inicio, int k) {
    if (k < 1)
    return inicio;
    if (inicio == nullptr)//Si la lista esta vacia, no se sigue.
        return nullptr;
    if (k == 1) {   //Si k es =1 entonces: se elimina el nodo en posicion k y se reenlaza el siguiente para que sea el k
        Nodo *aux = inicio->siguiente;
        delete(inicio);
        return aux;
    }
    else {
        inicio->siguiente = e(inicio->siguiente, k-1);//
        return inicio;
    }
}

Nodo* a(Nodo* inicio, int d) {
     if (inicio == nullptr) {
        Nodo* nuevo = new Nodo;
        nuevo->dato = d;
        nuevo->siguiente = nullptr;
        return nuevo;
    }
    else {
        inicio->siguiente = a(inicio->siguiente, d);//inicio=nuevo(9),inicio->siguiente=nuevo->siguiente(6)
                                                    //Se carga una lista enlazada con insercion al final
    }
 return inicio;
}

void print_linked_list(Nodo* head)
{
    if(head!=nullptr)
    {
        cout << head->dato << " | ";
        print_linked_list(head->siguiente);
    }

}

int main() {
    Nodo* inicio=nullptr;
    inicio = a(inicio, 9);
    inicio = a(inicio, 6);
    inicio = a(inicio, 4);
    inicio = a(inicio, 7);
    inicio = e(inicio, 3);
    print_linked_list(inicio);
}
