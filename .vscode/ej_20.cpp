/*Crear una lista circular con los datos de los procesos en ejecución en un sistema operativo, 
donde cada uno  consta de: 
PID (número de proceso), nombre de usuario, segundos que se ejecutó, fecha en que se empezó a
ejecutar (numérica, formato DDMM). 
Crear la lista insertando al principio.

a) Informar el PID del proceso que más segundos se ejecutó.

b) Eliminar el proceso que se empezó a ejecutar el 14 de marzo (si hay más de uno, sólo el primero).

c) Aumentar en 2 la cantidad de segundos que se ejecutó el proceso con PID 5, si existe.

d) Listar todos los procesos del usuario "root" (imprimiendo el PID y segundos de ejecución de cada uno).*/

#include <iostream>
#include <cctype>
#include <cstring>
#include <thread>
#include <chrono>

using namespace std;

struct proceso
{
    int PID;
    string usuario;
    float  time_of_execution;
    int execution_date;
};

struct nodo
{
    proceso process;
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
    cout << '\t' <<"|CUITS DE PROVEEDORES|"<<endl<<'|';
    do {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << aux->process.execution_date<< '|';
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

nodo* insert_at_circular_start(nodo* end, nodo* nuevo)
{
    if (end == nullptr)
    {
    nuevo->siguiente = nuevo;
    return nuevo;
    }
    else    
    {
    nuevo->siguiente = end->siguiente;
    end->siguiente = nuevo;
    return end;
    }

}

nodo* load_of_cuits(nodo* end,int &quantity)
{              
    bool deseo=true;
    proceso proceso_ex;   
    nodo *nuevo;//TODO VERIFICATIONS
    cout << "Ingresar nombre de usuario a guardar: ";
    getline(cin>>ws,proceso_ex.usuario);
    cout << "Ingresar la cantidad de segundos de ejecucion: ";
    cin >> proceso_ex.time_of_execution;
    cout << "Ingresar la fecha en la que se empezo a ejecutar(formato DDMM): ";
    cin >> proceso_ex.execution_date;
    while (deseo)              
    {
        nuevo=new nodo;
        nuevo->process=;
        end=insert_at_circular_start(end,nuevo);
        quantity++;
        deseo=verify_wish(); 
        cout<< endl<<endl;   
        if (not deseo)
        {
            cout <<endl<<" FINISHING CHARGE...";
            std::this_thread::sleep_for(std::chrono::seconds(3));
            break;
        }    
        cout << "Ingresar CUIT a guardar: ";
        cin >> cuit;
        cuit=cuit_verification(cuit,end);
    }                                
    return end;
}

