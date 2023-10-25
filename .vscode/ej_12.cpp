/*Generar una lista enlazada simple con la nómina de artículos de un supermercado. 
De cada artículo se conoce:
código, descripción, precio y stock. La carga finaliza con el código -1. 
Se solicita:

A. Leer de teclado un porcentaje e incrementar el precio de todos los artículos en esa cantidad.

B. Incrementar el stock de un artículo. Se lee de teclado el código y la cantidad con la que se debe
incrementar el stock. Si no existe el artículo en la lista se debe informar.

C. Eliminar de la lista los artículos que no tienen stock.*/

#include <iostream>
#include <cstring>
#include <thread>
#include <chrono>

using namespace std;

struct Articulo
{
    int codigo;
    string descripcion;
    float precio;
    int stock;
};

struct nodo
{
    Articulo articulo;
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
int verify_code(nodo* inicio,int codigo_nuevo)
{
     
    for (nodo*aux = inicio; aux!=nullptr; aux=aux->siguiente)
        {
            if (aux->articulo.codigo==codigo_nuevo)
            {
                cout << " Ese codigo ya esta en la lista..."<<endl;
                std::this_thread::sleep_for(std::chrono::seconds(5));
                cout << "Ingrese otro codigo: ";
                cin >> codigo_nuevo;
                aux=inicio;
            }
                
        }
    
    return codigo_nuevo;
}
nodo* end_insertion(nodo *inicio,nodo *nuevo)
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


nodo* article_insertion(nodo *inicio)
{
    nodo *nuevo;
    Articulo art;
    cout << "Ingresar codigo del articulo (-1 para cortar): ";
    cin >> art.codigo;
    while (art.codigo!=-1)
    {
        nuevo=new nodo;
        nuevo->siguiente=nullptr;
        cout << "Ingresar descripcion del articulo : ";
        getline(cin>>ws,art.descripcion);
        cout << "Ingresar stock del articulo : ";
        cin >> art.stock;
        cout << "Ingresar precio del articulo : ";
        cin >> art.precio;
        nuevo->articulo=art;
        inicio=end_insertion(inicio,nuevo);
        std::this_thread::sleep_for(std::chrono::seconds(3));
        cout << "Ingresar codigo del articulo (-1 para cortar): ";
        cin >> art.codigo;
        art.codigo=verify_code(inicio,art.codigo);
        
        
    }
    return inicio;
}
void print_list_of_articles(nodo *inicio)
{   
    int i=1;
    cout << '\t' <<"|ARTICULOS|"<<endl;
    for (nodo  *aux = inicio; aux!=nullptr; aux=aux->siguiente)
    {
        cout << "Articulo "<< i <<"-";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << "|Codigo= " << aux->articulo.codigo<<" Descripcion-"<<aux->articulo.descripcion<<" Precio= "<<aux->articulo.precio<<" Stock= "<<aux->articulo.stock << '|';
        cout <<endl;
        i++;
        
    }
}
int main()
{
    nodo* head=nullptr;
    
    head=article_insertion(head);
    space_jump();
    print_list_of_articles(head);

}
