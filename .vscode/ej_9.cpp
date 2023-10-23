/*
Desarrollar un programa que realice las siguientes operaciones en listas enlazadas 
simples de números enteros.

A. Cargar una lista insertando los elementos ordenados en forma descendente. 
Finaliza luego de ingresar el cero, que también se debe agregar a la lista.

B. Eliminar las ocurrencias de los números que son múltiplos de 3.

C. Imprimir la lista antes y después de la eliminación.*/



#include <iostream>
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



void impresion_datos(nodo *inicio)
{   
    cout << '\t' <<"|Datos enlazados|"<<endl<<'|';
    for (nodo  *aux = inicio; aux!=nullptr; aux=aux->siguiente)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << aux->num<< '|';
    }
}

nodo* insercion_ordenada(nodo* inicio,nodo* nuevo)
{
    if (inicio==nullptr || nuevo->num < inicio->num)
    {
        nuevo->siguiente=inicio;
        inicio=nuevo;
    }
    else
    {
    nodo* aux=inicio;
    while (aux->siguiente != nullptr && aux->siguiente->num < nuevo->num) 
        {
        aux = aux->siguiente;
        }
    nuevo->siguiente = aux->siguiente;
    aux->siguiente = nuevo;
    }
return inicio;
}
nodo* ingreso_ordenado(nodo *inicio)
{
    int entero;
    nodo *nuevo;
    do
    {
        cout << "Ingresar numero a guardar(0 para cortar): ";
        cin >> entero;
        nuevo=new nodo;
        nuevo->num=entero;
        nuevo->siguiente=nullptr;
        inicio=insercion_ordenada(inicio,nuevo);
    } while (entero!=0);
    
    return inicio;
}
bool verify_extermination(nodo* inicio)
{
    for (nodo*aux = inicio; aux!=nullptr; aux=aux->siguiente)
    {
        if (aux->num%3==0)
        {
            
            return true;
        }
                
    }
    cout << " Los multiplos de 3 han sido exterminados de la lista..."<<endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return false;
}

nodo* exterminate_3_multi(nodo* inicio)
{
    while (verify_extermination(inicio))
    {
        
    
    
        if (inicio!=nullptr)
        {
            nodo* aux=inicio;
            if (inicio->num%3==0)
            {
                inicio=inicio->siguiente;
                delete aux;
            }
            else
            {
                while (aux->siguiente!=nullptr&&aux->siguiente->num%3!=0)
                {
                    aux=aux->siguiente;
                
                }
                if (aux->siguiente->num%3==0)
                {
                    nodo* aborrar=aux->siguiente;
                    aux->siguiente=aborrar->siguiente;
                    delete aborrar;
                }
            }
        }
    }
    return inicio;


}


int main()
{
    nodo* inicio=nullptr;
    inicio=ingreso_ordenado(inicio);
    space_jump();
    impresion_datos(inicio);
    space_jump();
    inicio=exterminate_3_multi(inicio);
    space_jump();
    impresion_datos(inicio);         

}