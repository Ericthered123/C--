/*Se lee de teclado una secuencia de números enteros, finalizando cuando el usuario ingresa un cero (que no
debe insertarse). Los números leídos deberán ser almacenados en una lista enlazada simple. Hacer tres
versiones, insertando en cada una con diferente criterio, a saber:
a) Al inicio de la lista.
b) Al final de la lista.
c) En la posición correcta para que la lista quede ordenada de menor a mayor. Si el número a insertar ya
se encontraba en la lista, deberá quedar antes que todas sus repeticiones.
Finalmente, imprimir la lista.*/

#include <iostream>
#include <cstring>
#include <chrono>
#include <thread>

using namespace std;

struct nodo
{
    int numero;
    nodo *siguiente;
};





nodo* ingreso(nodo *inicio)
{
    int num=0;
    nodo *nuevo= new nodo;
    cout << "Ingresar numero a guardar(0 para cortar): ";
    cin >> num;
    while (num!=0)
    {
        nuevo->numero=num;
        nuevo->siguiente=inicio;
        inicio=nuevo;
        cout <<endl<< "Ingresar numero a guardar(0 para cortar): ";
        cin >> num;
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
    return inicio;
}

nodo *ingreso_final(nodo *inicio)
{
    







}



int main()
{
    nodo *inicio=nullptr;
    inicio=ingreso_inicial(inicio);
    cout << inicio->numero;
    inicio=nullptr;
    inicio=ingreso_final(inicio);
    


}