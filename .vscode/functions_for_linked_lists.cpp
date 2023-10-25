


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

nodo* insert_by_order(nodo* inicio,nodo* nuevo)//se ordena de menor a mayor,algunas partes de la estructura puede variar segun el contexto
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


void inform_quantity_of_existences(nodo* inicio)
{
    cout << "\t"<<"***QUANTITY OF EXISTENCES***"<<endl<<endl;
    int quantity=0;
    int looked_existence;
    cout << "Ingresar ocurrencia a buscar: ";
    cin >> looked_existence;
    nodo *aux=inicio;
    while ( aux!=nullptr)//Use of while structure instead of a for, due to the context of the function
    {
    
    
        if (aux->dato==looked_existence)
        {
            quantity++;
        }    
        aux=aux->siguiente;
    }    
    cout << "El dato "<< looked_existence<< " se encuentra "<< quantity << " veces en la lista."<<endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));

}

// Sobre la union y division de listas segun un criterio
//-------------------------------------------------------

void reinsert_node(nodo* & lista_original, nodo* & lista_nueva) {
    nodo* anterior = lista_original;
    lista_original = lista_original->siguiente;
    anterior->siguiente = nullptr;
    lista_nueva = insert_by_order(lista_nueva, anterior);
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


//  Verificacion de la existencia de un elemento en toda la lista
//  Eliminacion de  un elemento y sus ocurrencias
//  Exterminacion del elemento por completo
//  Verificacion de ocurrencias
//  Eliminar un elemento ingresado por el usuario de la lista  
// ----------------------------------------------------
bool verify_extermination(nodo* inicio)
{
    for (nodo*aux = inicio; aux!=nullptr; aux=aux->siguiente)
    {
        if (aux->dato%3==0)//Condicion que varia segun el enunciado
        {
            
            return true;
        }
                
    }
    cout << " Los datos han sido exterminados de la lista..."<<endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return false;
}
nodo* elimination_of_existences(nodo* inicio,int &chosen_number)
{
    cout<<endl<< "Ingrese numero a exterminar por completo de la lista: ";
    cin >>chosen_number;
    inicio=exterminate_number(inicio,chosen_number);
    return inicio;


}
nodo* exterminate_number(nodo* inicio,int chosen_number)
{ 
    while (verify_extermination(inicio))
    {
        
    
    
        if (inicio!=nullptr)
        {
            nodo* aux=inicio;
            if (chosen_number==inicio->dato)
            {
                inicio=inicio->siguiente;
                delete aux;
            }
            else
            {
                while (aux->siguiente!=nullptr&&aux->siguiente->dato!=chosen_number)
                {
                    aux=aux->siguiente;
                
                }
                if (aux->siguiente->dato==chosen_number)
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
bool verify_eliminated(nodo* inicio,int dato_delete)
{
    for (nodo *aux = inicio; aux!=nullptr; aux=aux->siguiente)
    {
        if (aux->dato==dato_delete)
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
    int eliminado;
    cout <<endl<< "\t"<< "***ELIMINACION DE DATO***"<<endl<<endl;
    cout << "Ingrese dato a eliminar: ";
    cin >> eliminado;
    bool existencia_eliminado=verify_eliminated(inicio,eliminado);
    if (not existencia_eliminado)
    {
        cout << "!!Debe ingresar un dato que pertenezca a la lista!!";
        return inicio;
    }
    
    if (inicio!=nullptr)
    {
        nodo* aux=inicio;
        if (eliminado==inicio->dato)
        {
            inicio=inicio->siguiente;//Aqui inicio->siguiente seria=NULLPTR
            delete aux;//Borrando el nodo sin perder el initial PTR
        }
        else
        {
            while (aux->siguiente!=nullptr&&aux->siguiente->dato!=eliminado)
            {
                aux=aux->siguiente;
                
            }
            if (aux->siguiente->dato==eliminado)
            {
                nodo* aborrar=aux->siguiente;//Aqui se pasa la direccion del nodo a eliminar a un puntero que va a servir de chivo expiatorio xd
                aux->siguiente=aborrar->siguiente;//Aqui se pasa la direccion del nodo que le sigue al que se borra
                delete aborrar;
            }
        }
    }
    return inicio;
}
