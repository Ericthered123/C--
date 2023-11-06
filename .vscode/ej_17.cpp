/*Dada una lista circular que contiene palabras, solicitar al usuario el ingreso de una posición (numérica, mayor a
0 y menor o igual que N, siendo N la cantidad de nodos en la lista) 
y luego el ingreso de una nueva palabra para insertarla en la posición indicada. 
Ejemplo: si la lista contiene las siguientes palabras, 
en este orden: "chocolate"- "merengue" - "frutilla" - "caramelo",
y el usuario quiere insertar la palabra "menta" en la posición 4, 
la lista quedará: "chocolate" - "merengue" - "frutilla" - "menta" - "caramelo". 
Para ello, realizar dos funciones:
a) Nodo* buscar_posicion(Nodo* fin, int posicion)
Parámetros: el puntero al final de la lista y un número que indica la posición dada por el usuario.
Retorno: puntero al nodo anterior a la posición (si es que existe). En el ejemplo dado, el puntero
apuntará al nodo con la palabra “frutilla”. Si no existe la posición, retornará nullptr.
b) void insertar_despues(Nodo* anterior, string palabra)
Parámetros: puntero al nodo anterior (el retornado por la función buscar_posicion) y la palabra a
insertar en un nuevo nodo (a continuación de anterior).
*/



#include <iostream>
#include <cctype>
#include <cstring>
#include <thread>
#include <chrono>

using namespace std;


struct nodo
{
    string word;
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
void print_circular_list(nodo *end)
{   
    if (end != nullptr)
    {
    nodo* aux = end->siguiente;
    cout << '\t' <<"|PALABRAS ENLAZADAS|"<<endl<<'|';
    do {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << aux->word<< '|';
    aux = aux->siguiente;
    } 
    while (aux != end->siguiente);
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

nodo* insert_at_circular_end(nodo* end,nodo* nuevo)
{ 
    if (end == nullptr)
    {
    nuevo->siguiente = nuevo;
    }
    else
    {
    nuevo->siguiente = end->siguiente;
    end->siguiente = nuevo;
    }   
    return nuevo;
}

nodo* load_of_words(nodo* end,int &cantidad)
{              
    int i=4;
    string word;   
    nodo *nuevo;
    cout << "Ingresar palabra a guardar(la lista iniciara con 4 palabras): ";
    getline(cin>>ws,word);
    while (i!=0)              
    {
        nuevo=new nodo;
        nuevo->word=word;
        i--;
        cantidad++;
        end=insert_at_circular_end(end,nuevo);
        if (i==0)
        {
            cout <<endl<<" FINISHING CHARGE...";
            std::this_thread::sleep_for(std::chrono::seconds(3));
            break;
        }
        cout << "Ingresar palabra a guardar(la lista iniciara con 4 palabras): ";
        getline(cin>>ws,word);

    }                                
    return end;
}

nodo* buscar_posicion(nodo* fin,int cantidad)//TODO parte A
{
    int desired_position;
    cout << endl<< "Ingrese posicion que va a ocupar la nueva palabra: ";
    cin >> desired_position;
    if (desired_position>cantidad||desired_position<=0)
    {
        cout<<endl<< "Ingrese una posicion valida!!!";
        return nullptr;
    }
    if (desired_position==1)
    {
        return fin;
    }
    for (nodo* aux=fin ; desired_position!=0; aux=aux->siguiente)
    {
        desired_position--;
        if (desired_position==0)
        {
            return aux;
        }
        
    }
}
void insertar_despues(nodo* anterior,string palabra)
{
    nodo* aux=anterior->siguiente;
    anterior->siguiente=new nodo;
    anterior->siguiente->word=palabra;
    anterior->siguiente->siguiente=aux;
    
    
    

}
int main()
{
    string word;
    int node_quantity=0;
    nodo* c_pointer=nullptr;
    nodo* anterior=nullptr;
    c_pointer=load_of_words(c_pointer,node_quantity);
    space_jump();
    //print_circular_list(c_pointer);
    anterior=buscar_posicion(c_pointer,node_quantity);
    cout << endl<<" Ingrese la palabra a insertar en la posicion deseada: ";
    getline(cin>>ws,word);
    insertar_despues(anterior,word);
    print_circular_list(c_pointer);
}