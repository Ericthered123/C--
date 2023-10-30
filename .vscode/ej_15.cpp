/*"The Golden Gate Bridge" es el puente más famoso de la ciudad de San Francisco (California). Cuenta con una
longitud aproximada de 1280 metros y posee tres radares de toma de velocidad. Por cada móvil que se
desplaza por las vías principales se registra la siguiente información: sensor que lo captó (puede ser "norte",
"sur" o "medio"), patente (no tiene un formato único ya que difiere de un estado a otro y pueden transitar
autos extranjeros, aunque se sabe que están formadas sólo por letras y números) y velocidad en km/h.
A. Cargar las lecturas que hacen los sensores en una lista enlazada simple ordenando por patente y, para
la misma patente, ordenando por sensor (ya que un mismo automóvil puede ser captado por más de un
sensor). Finaliza con la patente "aaa99", que no se debe ingresar.
B. Dada la lista generada en el inciso anterior, armar tres listas: una por cada sensor (el orden de los
elementos tiene que ser el mismo que en la lista original). Luego, imprimir las tres listas.*/



#include <iostream>
#include <cstring>
#include <thread>
#include <chrono>

using namespace std;




struct fetched_data
{
    string sensor;
    string patente;
    float velocidad;
};


struct nodo
{
    fetched_data data;
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



void print_list(nodo *inicio)
{   
    cout << '\t' <<"|'GOLDEN STATE BRIDGE' FETCHED DATA OF SPEEDING|"<<endl<<'|';
    for (nodo  *aux = inicio; aux!=nullptr; aux=aux->siguiente)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout <<"|Patente del auto infractor: "<< aux->data.patente<< '|'<< "";
    }
}