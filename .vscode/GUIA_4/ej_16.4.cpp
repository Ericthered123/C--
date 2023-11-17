/*Escribir una función recursiva que, dadas dos listas enlazadas simples, 
retorne true si ambas listas tienen la misma longitud (cantidad de nodos), 
false en caso contrario. 
Optimizar la función para que, en caso de que una
lista sea más corta que la otra (por ejemplo, la lista A tiene 10000 nodos y la lista B tiene 5 nodos)
, no se continúe contabilizando la cantidad de nodos de la lista más larga.*/



#include <iostream>
#include <cstring>
#include <cctype>
#include <thread>
#include <chrono>
#include <cmath>

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
        nuevo->num=ejemplo;
        inicio=create_node(inicio,nuevo);
        cout << "Ingresar numero a guardar al principio(0 para cortar): ";
        cin >> ejemplo;
        
    }                               
    return inicio;
}

int node_quantity(nodo* head)
{
    if (head==nullptr)
    {
        return 0;
    }
    
    else 
    {
        return 1+node_quantity(head->siguiente);
    }
    


}

bool node_equality(nodo* a,nodo* b)
{
    if (a==nullptr&&b==nullptr)
    {
        return true;
    }
    if (a!=nullptr&&b==nullptr||a==nullptr&&b!=nullptr)
    {
        return false;
    }
    else
    {
        return node_equality(a->siguiente,b->siguiente);
    }

}

int main()
{
    nodo* head_A=nullptr;
    nodo* head_B=nullptr;
    int q_nodes_A,q_nodes_B;
    cout << "\t"<< "***LOAD LIST A***"<<endl;
    head_A=start_insertion(head_A);
    space_jump();
    cout << "\t"<< "***LOAD LIST B***"<<endl;
    head_B=start_insertion(head_B);
    q_nodes_A=node_quantity(head_A);
    q_nodes_B=node_quantity(head_B);
    space_jump();
    if (node_equality(head_A,head_B))
    {
        cout << "|A nodes= "<< q_nodes_A<< "| B nodes= "<< q_nodes_B<<"|";
    }
    else
    {
        cout <<'\t'<< "Las listas tienen distinta cantidad de nodos";
    }

}