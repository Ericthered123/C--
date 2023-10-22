/*
Se lee de teclado una secuencia de números que finaliza con la primera ocurrencia de un número negativo,el
cual no debe ser procesado. 
Los números deben ser almacenados en una lista enlazada simple. Se solicita:

A. Leer de teclado un número e informar si existe en la lista.

B. Leer de teclado un número e informar la cantidad de ocurrencias del número en la lista.

C. Implementar una función que reciba la lista de números y genere dos nuevas listas, una con los
números pares y otra con los impares. Las nuevas listas deberán estar formadas con los nodos de la lista
original, la que quedará vacía después de invocar a la función. Imprimir las listas resultantes.
*/




#include <iostream>
#include <cstring>
#include <thread>
#include <chrono>


using namespace std;

void space_jump()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    for (int i = 0; i < 20; i++)
    {
        cout << endl;
    }
    

}



struct nodo
{
    int num_pos;
    nodo* siguiente;
};

nodo* node_insertion(nodo* inicio,nodo* nuevo)
{
    if (inicio==nullptr)
        {
            inicio=nuevo;
        }
        else
        {

            nodo *aux=inicio;
            while (aux->siguiente!=nullptr)
            {
                aux=aux->siguiente;
            }
            aux->siguiente=nuevo;
        }
    return inicio;


}


void verify_existence(nodo* inicio)
{
    cout << "\t"<<"***VERIFY EXISTENCE***"<<endl<<endl;
    int looked_number=0;
    cout << "Ingrese numero a buscar: ";
    cin >> looked_number;
    nodo *aux=inicio;
    while (aux!=nullptr)
    
    {
        if (aux->num_pos==looked_number)
        {
            cout<<"El numero " <<looked_number<<  " ya esta en la lista.."<<endl;
            std::this_thread::sleep_for(std::chrono::seconds(3));
            return;
        }
        aux=aux->siguiente;
    }
    cout << "El numero "<< looked_number<< " no esta en la lista..."<<endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));

}

void inform_quantity_of_existences(nodo* inicio)
{
    cout << "\t"<<"***QUANTITY OF EXISTENCES***"<<endl<<endl;
    int quantity=0;
    int looked_existence;
    cout << "Ingresar ocurrencia a buscar: ";
    cin >> looked_existence;
    nodo *aux=inicio;
    while ( aux!=nullptr)
    {
    
    
        if (aux->num_pos==looked_existence)
        {
            quantity++;
        }    
        aux=aux->siguiente;
    }    
    cout << "El numero "<< looked_existence<< " se encuentra "<< quantity << " veces en la lista."<<endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));

}
nodo* carga_numeros(nodo* inicio)
{
    int num=0;
    nodo* nuevo;
    cout << "\t"<<"***LOAD OF NUMBERS***"<<endl<<endl;
    cout << "Ingrese un numero a cargar( n < 0 para cortar): ";
    cin >> num;
    while (num>=0)
    {
        nuevo=new nodo;
        nuevo->siguiente=nullptr;
        nuevo->num_pos=num;
        inicio=node_insertion(inicio,nuevo);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout << "Ingrese un numero a cargar( n < 0 para cortar): ";
        cin >> num;
        if (num<0)
        {
            cout <<endl<< "FINALIZANDO...";
            std::this_thread::sleep_for(std::chrono::seconds(3));                   
        }
        
    }
    return inicio;
}

void impresion_datos(nodo *inicio)
{   
    cout << '\t' <<"|Datos enlazados|"<<endl<<'|';
    for (nodo  *aux = inicio; aux!=nullptr; aux=aux->siguiente)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << aux->num_pos<< '|';
    }
}

int main()
{
    nodo* inicio=nullptr;
    inicio=carga_numeros(inicio);
    space_jump();
    verify_existence(inicio);
    space_jump();
    inform_quantity_of_existences(inicio);




}


