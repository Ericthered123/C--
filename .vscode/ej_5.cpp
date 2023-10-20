/*Permitir al usuario guardar en una lista enlazada simple los nombres de los alumnos de un curso, insertando al
final de la lista y cortando la carga cuando se inserte como nombre "x", ya sea en mayúscula o en minúscula (el
cual no debe insertarse en la lista).
A continuación, solicitar al usuario el nombre de un alumno e informar si se encuentra en la lista o no.
Por último, eliminar a la alumna "Josefina Ortega" de la lista (se asume que no se han almacenado nombres
repetidos).*/
#include <iostream>
#include <cstring>
#include <thread>
#include <chrono>


using namespace std;

struct nodo
{
    string nombre;
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



nodo* insercion(nodo* inicio,nodo* nuevo)
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
nodo* carga_datos(nodo *inicio)
{
    string nombre;
    nodo *nuevo;
    cout << "Ingresar nombre completo a guardar en la lista('x' para cortar): ";
    getline(cin>>ws,nombre);
    while (nombre!="x"&&nombre!="X")
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        nuevo=new nodo;
        nuevo->siguiente=nullptr;
        nuevo->nombre=nombre;
        inicio=insercion(inicio,nuevo);
        cout << "Ingresar nombre completo a guardar en la lista('x' para cortar): ";
        getline(cin>>ws,nombre);
    }
    return inicio;


}
bool verificar_eliminado(nodo* inicio,string nombre_delete)
{
    for (nodo *aux = inicio; aux!=nullptr; aux=aux->siguiente)
    {
        if (aux->nombre==nombre_delete)
        {
            cout << "El nombre buscado se encuentra en la lista...";
            return true;
        }
                
    }
    cout << "El nombre ingresado no se encuentra en la lista...";
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return false;
}
bool informar_ocurrencia(nodo* inicio)
{
    string nombre_buscado=" ";
    cout <<endl<< "\t"<< "***Busqueda de nombre***"<<endl<<endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "Ingrese nombre a buscar: ";
    getline(cin>>ws,nombre_buscado);
    for (nodo *aux = inicio; aux!=nullptr; aux=aux->siguiente)
    {
        if (aux->nombre==nombre_buscado)
        {
            cout << "El nombre buscado se encuentra en la lista...";
            return true;
        }
                
    }
    cout << "El nombre ingresado no se encuentra en la lista...";
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return false;


}
nodo* eliminar_nombre(nodo* inicio)
{
    string eliminado=" ";
    cout <<endl<< "\t"<< "***ELIMINACION DE NOMBRE***"<<endl<<endl;
    cout << "Ingrese nombre a eliminar: ";
    getline(cin>>ws,eliminado);
    bool existencia_eliminado=verificar_eliminado(inicio,eliminado);
    if (not existencia_eliminado)
    {
        cout << "!!Debe ingresar un nombre que pertenezca a la lista!!";
        return inicio;
    }
    
    if (inicio!=nullptr)
    {
        nodo* aux=inicio;
        if (eliminado==inicio->nombre)
        {
            inicio=inicio->siguiente;//Aqui inicio->siguiente seria=NULLPTR
            delete aux;//Borrando el nodo sin perder el initial PTR
        }
        else
        {
            while (aux->siguiente!=nullptr&&aux->siguiente->nombre!=eliminado)
            {
                aux=aux->siguiente;
                
            }
            if (aux->siguiente->nombre==eliminado)
            {
                nodo* aborrar=aux->siguiente;//Aqui se pasa la direccion del nodo a eliminar a un puntero que va a servir de chivo expiatorio xd
                aux->siguiente=aborrar->siguiente;//Aqui se pasa la direccion del nodo que le sigue al que se borra
                delete aborrar;
            }
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
        cout << aux->nombre<< '|';
    }
}

int main()
{
    nodo *inicio=nullptr;
    bool ocurrencia=false;
    inicio=carga_datos(inicio);
    space_jump();
    impresion_datos(inicio);
    ocurrencia=informar_ocurrencia(inicio);
    space_jump();
    inicio=eliminar_nombre(inicio);
    space_jump();
    impresion_datos(inicio);
}