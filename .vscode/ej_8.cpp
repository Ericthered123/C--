/*Implementar una función que reciba dos parámetros: una lista enlazada simple de números enteros y un
número entero. La función debe eliminar todas las ocurrencias del número indicado en el segundo parámetro.
Retornar la cantidad de ocurrencias eliminadas. Nota: se debe pasar una sola vez por cada uno de los
elementos de la lista.*/


#include <iostream>
#include <cstring>
#include <thread>
#include <chrono>

using namespace std;

struct nodo_int
{
    int num;
    nodo_int* siguiente;
};
void space_jump()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    for (int i = 0; i < 10; i++)
    {
        cout << endl;
    }
    

}


nodo_int* node_insertion(nodo_int* inicio,nodo_int* nuevo)
{
    if (inicio==nullptr)
        {
            inicio=nuevo;
        }
        else
        {

            nodo_int *aux=inicio;
            while (aux->siguiente!=nullptr)
            {
                aux=aux->siguiente;
            }
            aux->siguiente=nuevo;
        }
    return inicio;
}
bool verify_wish()
{
    int eleccion=2;
    while (eleccion==2)
    {
    cout << "Desea seguir con la carga?"<<endl;        
    cout << "[0] NO"<<endl;
    cout << "[1] SI"<<endl;
    cout << "Ingresar eleccion: ";
    cin >>eleccion;
    if (eleccion<0&&eleccion>1)
    {
        cout << "VUELVA A INGRESAR SU ELECCION..."<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        continue;
    }
    }
    if (eleccion==1)
    {
        return true;
    }
    else
    {
        return false;
    }

}
nodo_int* load_of_ints(nodo_int* inicio)
{
    bool deseo=true;
    int entero=0;
    nodo_int* nuevo;
    cout << "\t"<<"***LOAD OF NUMBERS***"<<endl<<endl;
    cout << "Ingrese un numero a cargar: ";
    cin >> entero;
    while (deseo!=false)
    {
        nuevo=new nodo_int;
        nuevo->siguiente=nullptr;
        nuevo->num=entero;
        inicio=node_insertion(inicio,nuevo);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        deseo=verify_wish();
        if (deseo==false)
        {
            cout <<endl<< "FINALIZANDO...";
            std::this_thread::sleep_for(std::chrono::seconds(3));
            break;                   
        }
        space_jump();
        cout << "Ingrese un numero a cargar: ";
        cin >> entero;
        
        
    }
    return inicio;
}

int main()
{
    nodo_int* inicio=nullptr;
    inicio=load_of_ints(inicio);



}