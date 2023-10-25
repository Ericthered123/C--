


#include <iostream>
#include <cstring>
#include <chrono>
#include <thread>

using namespace std;

struct nodo
{
    int dato;
    nodo* siguiente;
};

//Funciones con proposito de insercion con diferentes criterios
// --------------------------------------------------------------------------------


nodo* start_insertion(nodo *inicio)
{
    int ejemplo=0;//El tipo de dato varia segun el contexto
    nodo *nuevo;
    cout << "Ingresar numero a guardar al principio(0 para cortar): ";
    cin >> ejemplo;
    while (ejemplo!=0)//La condicion de corte puede variar dependiendo del contexto
    {
        nuevo=new nodo;
        nuevo->dato=ejemplo;
        inicio=create_node(inicio,nuevo);
        cout << "Ingresar numero a guardar al principio(0 para cortar): ";
        cin >> ejemplo;
        
    }//Tambien se puede utilizar una estructura for, para este ingreso, todo depende del contexto
    return inicio;
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

nodo* insercion_ordenada(nodo* inicio,nodo* nuevo)//se ordena de menor a mayor,algunas partes de la estructura puede variar segun el contexto
{
    if (inicio==nullptr || nuevo->dato < inicio->dato)
    {
        inicio=nuevo;
    }
    else
    {
    nodo* aux=inicio;
    while (aux->siguiente != nullptr && aux->siguiente->dato < nuevo->dato) 
        {
        aux = aux->siguiente;
        }
    nuevo->siguiente = aux->siguiente;
    aux->siguiente = nuevo;
    }
return inicio;
}


//Crear nuevo nodo
//-----------------------------------
nodo* create_node(nodo *inicio,nodo*nuevo)
{
    nuevo->siguiente=inicio;
    return nuevo;


}



//Funciones de proposito general
//------------------------------
void space_jump()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    for (int i = 0; i < 20; i++)
    {
        cout << endl;
    }
    

}


bool verify_wish()
{
    int eleccion=2;
    while (eleccion!=0&&eleccion!=1)
    {
    cout << "Desea seguir con la carga?"<<endl;        
    cout << "[0] NO"<<endl;
    cout << "[1] SI"<<endl;
    cout << "Ingresar eleccion: ";
    cin >>eleccion;
    if (eleccion<0||eleccion>1)
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



void print_list(nodo *inicio)
{   
    cout << '\t' <<"|Datos Enlazados|"<<endl<<'|';
    for (nodo  *aux = inicio; aux!=nullptr; aux=aux->siguiente)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << aux->dato<< '|';
    }
}


string lowering_word(string palabra)
{
    string low_word="";
    for (int i = 0; i < palabra.length(); i++)
    {
        low_word+=tolower(palabra[i]);
    }
    return low_word;

}

string uppering_word(string palabra)
{
    string upper_word="";
    for (int i = 0; i < palabra.length(); i++)
    {
        upper_word+=toupper(palabra[i]);
    }
    return upper_word;

}


// Sobre la union y division de listas segun un criterio
//-------------------------------------------------------

void reinsert_node(nodo* & lista_original, nodo* & lista_nueva) {
    nodo* anterior = lista_original;
    lista_original = lista_original->siguiente;
    anterior->siguiente = nullptr;
    lista_nueva = insercion_ordenada(lista_nueva, anterior);
}

nodo* merge(nodo* a,nodo* b)
{
    nodo* c=nullptr;
    while (a != nullptr && b != nullptr) {
    if (a->dato <= b->dato) {
    reinsert_node(a, c);
    }
    else {
    reinsert_node(b, c);
    }
    }
    while (a != nullptr) {
    reinsert_node(a, c);
    }
    while (b != nullptr) {
    reinsert_node(a, c);
    }
    return c;
}

void divide_list_example(nodo* & inicio, nodo* & pares, nodo* & impares) {
nodo* anterior;
while (inicio != nullptr) {
anterior = inicio;
inicio = inicio->siguiente;
anterior->siguiente = nullptr;
if (anterior->dato % 2 == 0) {
pares =end_insertion(pares, anterior);
}
else {
impares = end_insertion(impares, anterior);
}
}
}