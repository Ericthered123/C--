/*Se lee de teclado una secuencia de números enteros, finalizando cuando el usuario ingresa un cero (que no
debe insertarse). Los números leídos deberán ser almacenados en una lista circular. Hacer dos versiones,
insertando en cada una con diferente criterio, a saber:
a) Al inicio de la lista.
b) Al final de la lista.
*/


#include <iostream>
#include <cctype>
#include <cstring>
#include <thread>
#include <chrono>

using namespace std;


struct nodo
{
    int num;
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

nodo* load_of_data(nodo* end)
{ 
    int ejemplo;                  
    nodo *nuevo;
    cout << "Ingresar numero a guardar al principio(0 para cortar): ";
    cin >> ejemplo;
    while (ejemplo!=0)              
    {
        nuevo=new nodo;
        nuevo->num=ejemplo;
        end=insert_at_circular_end(end,nuevo);
        cout << "Ingresar numero a guardar al principio(0 para cortar): ";
        cin >> ejemplo;
        
    }                                
    return end;
}


void print_list(nodo *end)
{   
    if (end != nullptr)
    {
    nodo* aux = end->siguiente;
    cout << '\t' <<"|Datos Enlazados|"<<endl<<'|';
    do {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << aux->num<< '|';
    aux = aux->siguiente;
    } 
    while (aux != end->siguiente);
    }
}

int main()
{
    nodo* tail=nullptr;
    tail=load_of_data(tail);
    space_jump();
    print_list(tail);
    cout <<endl<< tail->num<<endl;
    cout << tail->siguiente->num;
    cout <<tail->siguiente->siguiente->num;


}