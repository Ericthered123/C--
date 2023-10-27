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

//A
void percentage_increment(nodo* head)
{
    float incremento_porcentual;
    cout << "Ingrese el porcentaje de aumento de los precios: ";
    cin >> incremento_porcentual;
    for (nodo* aux=head ; aux!=nullptr; aux=aux->siguiente)
    {
        aux->articulo.precio=((incremento_porcentual+100)*aux->articulo.precio)/100;
    }
    cout <<endl<< "\t"<< "Se han aumentado los precios de los articulos en un "<< incremento_porcentual<< "%";
    std::this_thread::sleep_for(std::chrono::seconds(3));
}
//B
void increment_stock(nodo* head)
{

    int code,inc_stock,code_verifier;
    code_verifier=0;
    cout << "Ingrese el codigo del articulo buscado: ";
    cin >> code;
    for ( nodo* aux=head; aux!=nullptr; aux=aux->siguiente)
    {
        if (aux->articulo.codigo==code)
        {
            code_verifier=1;
            cout << "Ingrese en cuanto quiere aumentar el stock de ese articulo: ";
            cin >> inc_stock;
            aux->articulo.stock+=inc_stock;
            cout << "Se ha aumentado el stock del articulo codigo "<< aux->articulo.codigo<<" en "<<inc_stock<<endl<<endl;
            std::this_thread::sleep_for(std::chrono::seconds(3));
        }
        
    }
    if (code_verifier==0)
    {
        cout <<endl<< "Ese codigo no se encuentra en la lista..."<<endl<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }

    


}
//C

nodo* eliminate_absence_of_article(nodo* head)
{
    
    if (head!=nullptr)
    {
        nodo* aux=head;
        if (head->articulo.stock==0)
        {
            head=head->siguiente;
            delete aux;
        }
        else
        {
            while (aux->siguiente!=nullptr&&aux->siguiente->articulo.stock!=0)
            {
                aux=aux->siguiente;
                
            }
            if (aux->siguiente->articulo.stock==0)
            {
                nodo* aborrar=aux->siguiente;
                aux->siguiente=aborrar->siguiente;
                delete aborrar;
            }
        }
    }
    return head;

}
nodo* search_stock_absence(nodo* head)//TODO problems with eliminating stock value 0 fix!!!
{

    for ( nodo* aux=head; aux!=nullptr; aux=aux->siguiente)
    {
        if (aux->articulo.stock==0)
        {
            aux=eliminate_absence_of_article(aux);
        }
        
    }
    return aux;


}
int verify_code(nodo* inicio,int codigo_nuevo)
//TODO this can get better, verification not working for second element
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
    std::this_thread::sleep_for(std::chrono::seconds(5));
}
int main()
{
    nodo* head=nullptr;
    
    head=article_insertion(head);
    space_jump();
    print_list_of_articles(head);
    head=search_stock_absence(head);
    space_jump();
    print_list_of_articles(head);
    space_jump();
    increment_stock(head);
    percentage_increment(head);
    space_jump();
    print_list_of_articles(head);
    space_jump();
    
}
