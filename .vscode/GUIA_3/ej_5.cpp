/*Se lee de teclado una secuencia de números enteros, finalizando cuando el usuario ingresa un cero (que no
debe insertarse). Los números leídos deberán ser almacenados en una lista enlazada simple. Hacer tres
versiones, insertando en cada una con diferente criterio, a saber:
a) Al inicio de la lista.
b) Al final de la lista.
c) En la posición correcta para que la lista quede ordenada de menor a mayor. Si el número a insertar ya
se encontraba en la lista, deberá quedar antes que todas sus repeticiones.
Finalmente, imprimir la lista.*/
//--------------------------------------------------------------------------------------------------------
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
nodo* insercion(nodo *inicio,nodo *nuevo)
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
nodo* ingreso_inicial(nodo *inicio)
{
    int num=0;
    nodo *nuevo;
    cout << "Ingresar numero a guardar al principio(0 para cortar): ";
    cin >> num;
    while (num!=0)
    {
        nuevo=new nodo;
        nuevo->numero=num;
        inicio=create_node(inicio,nuevo);
        cout << "Ingresar numero a guardar al principio(0 para cortar): ";
        cin >> num;
        
    }
    return inicio;
}

nodo *ingreso_final(nodo *inicio)
{
    int num=0;
    nodo *nuevo;
    cout << "Ingresar numero a guardar al final(0 para cortar): ";
    cin >> num;
    while (num!=0)
    {
        nuevo=new nodo;
        nuevo->siguiente=nullptr;
        nuevo->numero=num;
        inicio=insercion(inicio,nuevo);
        cout << "Ingresar numero a guardar al final(0 para cortar): ";
        cin >> num;
    }
    return inicio;
}
void impresion_datos(nodo *inicio)
{   
    cout << '\t' <<"|Datos enlazados|"<<endl<<'|';
    for (nodo  *aux = inicio; aux!=nullptr; aux=aux->siguiente)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << aux->numero<< ' ';
    }
}
nodo* insercion_ordenada(nodo* inicio,nodo* nuevo)
{
    if (inicio==nullptr || nuevo->numero < inicio->numero)
    {
        inicio=nuevo;
    }
    else
    {
    nodo* aux=inicio;
    while (aux->siguiente != nullptr && aux->siguiente->numero < nuevo->numero) 
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
    int num=0;
    nodo *nuevo;
    cout << "Ingresar numero a guardar(0 para cortar): ";
    cin >> num;
    while (num!=0)
    {
        nuevo=new nodo;
        nuevo->numero=num;
        nuevo->siguiente=nullptr;
        inicio=insercion_ordenada(inicio,nuevo);
        cout << "Ingresar numero a guardar(0 para cortar): ";
        cin >> num;
    }
    return inicio;
}
int main()
{
    nodo *inicio=nullptr;
    //inicio=ingreso_inicial(inicio);
    //impresion_datos(inicio);
    //space_jump();
    //inicio=ingreso_final(inicio);
    //space_jump();
    //impresion_datos(inicio);
    inicio=ingreso_ordenado(inicio);
    impresion_datos(inicio);

}