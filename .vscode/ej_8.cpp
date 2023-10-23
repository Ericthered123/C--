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
            cout <<endl<< "FINALIZANDO..."<<endl;
            std::this_thread::sleep_for(std::chrono::seconds(3));
            break;                   
        }
        space_jump();
        cout << "Ingrese un numero a cargar: ";
        cin >> entero;
        
        
    }
    return inicio;
}
bool verify_extermination(nodo_int* inicio,int exterminated_number)
{
    for (nodo_int *aux = inicio; aux!=nullptr; aux=aux->siguiente)
    {
        if (aux->num==exterminated_number)
        {
            
            return true;
        }
                
    }
    cout << "El numero ingresado ha sido en la lista...";
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return false;
}
nodo_int* exterminate_number(nodo_int* inicio,int chosen_number)
{ 
    while (verify_extermination(inicio,chosen_number))
    {
        
    
    
        if (inicio!=nullptr)
        {
            nodo_int* aux=inicio;
            if (chosen_number==inicio->num)
            {
                inicio=inicio->siguiente;
                delete aux;
            }
            else
            {
                while (aux->siguiente!=nullptr&&aux->siguiente->num!=chosen_number)
                {
                    aux=aux->siguiente;
                
                }
                if (aux->siguiente->num==chosen_number)
                {
                    nodo_int* aborrar=aux->siguiente;
                    aux->siguiente=aborrar->siguiente;
                    delete aborrar;
                }
            }
        }
    }
    return inicio;
}



nodo_int* elimination_of_existences(nodo_int* inicio,int &chosen_number)
{
    cout<<endl<< "Ingrese numero a exterminar por completo de la lista: ";
    cin >>chosen_number;
    inicio=exterminate_number(inicio,chosen_number);
    return inicio;


}
void impresion_datos(nodo_int *inicio)
{   
    cout << '\t' <<"|Datos enlazados|"<<endl<<'|';
    for (nodo_int  *aux = inicio; aux!=nullptr; aux=aux->siguiente)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << aux->num<< '|';
    }
}
int main()
{
    nodo_int* inicio=nullptr;
    inicio=load_of_ints(inicio);
    int chosen_number;
    impresion_datos(inicio);
    inicio=elimination_of_existences(inicio,chosen_number);
    space_jump();
    impresion_datos(inicio);

}