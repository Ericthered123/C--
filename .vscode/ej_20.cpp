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
    cout << '\t' <<"|DETAILS OF EXECUTING PROCCESES|"<<endl;
    do {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout <<"|PID: "<< aux->process.PID<< " Usuario: "  <<aux->process.usuario<<" Tiempo de ejecucion: "<< aux->process.time_of_execution<<" Fecha de ejecucion: "<<aux->process.execution_date/100<<'/'<<aux->process.execution_date%100<<  '|' ;
    cout << endl;
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
bool verification(nodo* end, int PID)
{   
    if (end!=nullptr)
    {
     nodo* aux=end->siguiente;   
    do
    {
        aux=aux->siguiente;
        if (aux->process.PID==PID||PID<0)
        {
            return true;
        }
        
    } while (aux!=end->siguiente);
    }
    return false;

}
int verify_PID(nodo* end,int PID)
{
    bool verifier;
    int v=0;
    if (end!=nullptr)
    {
     nodo* aux=end->siguiente;   
    do
    {
        aux=aux->siguiente;
        while (v==0)
        {
            verifier=verification(end,PID);
            if (verifier)
            {
                cout<<endl<< "Ese PID ya existe o es negativo, ingrese uno nuevo: ";
                cin >> PID;
            }
            else
            {
                v=1;
            }
            
        }
            
    } while (aux!=end->siguiente);
    return PID;
    }
    return PID;
}

nodo* load_of_each_process(nodo* end)
{              
    bool deseo=true;
    proceso proceso_ex;   
    nodo *nuevo;//TODO VERIFICATIONS
    cout << "Ingresar PID(>=0): ";
    cin  >> proceso_ex.PID;
    proceso_ex.PID=verify_PID(end,proceso_ex.PID);
    cout << "Ingresar nombre de usuario a guardar: ";
    getline(cin>>ws,proceso_ex.usuario);
    cout << "Ingresar la cantidad de segundos de ejecucion: ";
    cin >> proceso_ex.time_of_execution;
    cout << "Ingresar la fecha en la que se empezo a ejecutar(formato DDMM): ";
    cin >> proceso_ex.execution_date;
    while (deseo)              
    {

        nuevo=new nodo;
        nuevo->process=proceso_ex;
        end=insert_at_circular_start(end,nuevo);
        deseo=verify_wish(); 
        cout<< endl<<endl;   
        if (not deseo)
        {
            cout <<endl<<" FINISHING CHARGE...";
            std::this_thread::sleep_for(std::chrono::seconds(3));
            break;
        }    
        cout << "Ingresar PID(>=0): ";
        cin  >> proceso_ex.PID;
        proceso_ex.PID=verify_PID(end,proceso_ex.PID);
        cout << "Ingresar nombre de usuario a guardar: ";
        getline(cin>>ws,proceso_ex.usuario);
        cout << "Ingresar la cantidad de segundos de ejecucion: ";
        cin >> proceso_ex.time_of_execution;
        cout << "Ingresar la fecha en la que se empezo a ejecutar(formato DDMM): ";
        cin >> proceso_ex.execution_date;
    }                                
    return end;
}

int main()
{
    nodo* process_pointer=nullptr;
    process_pointer=load_of_each_process(process_pointer);
    space_jump();
    print_circular_list(process_pointer);
}