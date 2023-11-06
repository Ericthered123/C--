/*Cargar en una lista circular, insertando al inicio, 
los números de CUIT de los proveedores de un comercio.
a) Dado un número de CUIT, eliminarlo de la lista.
b) Informar cuántos elementos hay en la lista después de la eliminación.  */



#include <iostream>
#include <cctype>
#include <cstring>
#include <thread>
#include <chrono>

using namespace std;


struct nodo
{
    int cuit;
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
    cout << aux->cuit<< '|';
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
bool look_for_cuit_existence(int cuit_a_verificar,nodo* end)
{
    if (end!=nullptr)
    {
    nodo* aux=end->siguiente;
    
    do
    {

        if (cuit_a_verificar==aux->cuit)
        {
            cout <<endl<< " El cuit "<< cuit_a_verificar<< " ya se encuentra en el listado...";
            return true;
        }
        aux=aux->siguiente;
     } while (aux!=end->siguiente);
    }
    return false;
}
int cuit_verification(int cuit,nodo* end)
{
    while (look_for_cuit_existence(cuit,end))
    {
        cout << endl<<"Ingrese un cuit no repetido: ";
        cin >> cuit;
    }
    return cuit;


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
    int cuit;   
    nodo *nuevo;
    cout << "Ingresar CUIT a guardar: ";
    cin >> cuit;
    while (deseo)              
    {
        nuevo=new nodo;
        nuevo->cuit=cuit;
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

nodo* eliminate_element(nodo* end, int cuil_to_eliminate)
{
    
    if (end!=nullptr)
    {
    nodo* aux = end;
    nodo* aEliminar;
    do {
        if (aux->siguiente->cuit == cuil_to_eliminate)
        {
        aEliminar = aux->siguiente;
        if (aEliminar == end)
        {
        end= aux;
        }
        aux->siguiente = aEliminar->siguiente;
        delete aEliminar;
        break;
        }
    else
        aux = aux->siguiente;
    } while (aux != end);
 }
 cout << "El CUIT "<< cuil_to_eliminate<< " fue eliminado...";
 std::this_thread::sleep_for(std::chrono::seconds(3));
 return end;
}

int main()
{
    nodo* cuit_pointer=nullptr;
    int cuit_quantity=0,cuil_elimination;
    cuit_pointer=load_of_cuits(cuit_pointer,cuit_quantity);
    space_jump();
    print_circular_list(cuit_pointer);
    space_jump();
    cout << "Ingrese CUIT a eliminar: ";
    cin >>cuil_elimination;
    cuit_pointer=eliminate_element(cuit_pointer,cuil_elimination);
    space_jump();
    print_circular_list(cuit_pointer);

}