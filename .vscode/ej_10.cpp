/*Cargar una lista enlazada simple con palabras ingresadas por el usuario, las cuales deben almacenarse en
minúsculas independientemente de cómo las ingrese. 
Luego, a partir de esa lista, generar una nueva lista con
las palabras que se encuentran repetidas. Finalmente, imprimir ambas listas.*/


#include <iostream>
#include <cstring>
#include <thread>
#include <chrono>

using namespace std;

struct nodo
{
    string palabra;
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
void impresion_datos(nodo *inicio)
{   
    cout << '\t' <<"|Datos enlazados|"<<endl<<'|';
    for (nodo  *aux = inicio; aux!=nullptr; aux=aux->siguiente)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << aux->palabra<< '|';
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
nodo* create_node(nodo *inicio,nodo*nuevo)
{
    nuevo->siguiente=inicio;
    return nuevo;


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
nodo* load_of_words(nodo *inicio)
{
    bool deseo=true;
    string word;
    nodo *nuevo;
    cout << "Ingresar palabra a guardar: ";
    getline(cin>>ws,word);
    word=lowering_word(word);
    while (deseo)
    {
        nuevo=new nodo;
        nuevo->palabra=word;
        inicio=create_node(inicio,nuevo);
        deseo=verify_wish();
        if (not deseo)
        {
            cout <<endl<< "FINALIZANDO...";
            std::this_thread::sleep_for(std::chrono::seconds(3));
            break;
        }
        cout << "Ingresar palabra a guardar: ";
        getline(cin>>ws,word);
        word=lowering_word(word);
        
    }
    return inicio;
}

void looking_repeated_words(nodo* ptr_head,string arreglo[])
{


}
void divide_by_repeated_words(nodo* &ptr_head,nodo *&ptr_repetidos)
{
    nodo* anterior;
    while (ptr_head!=nullptr)
    {
        anterior=ptr_head;
        ptr_head=ptr_head->siguiente;
        anterior->siguiente=nullptr

        
    }
    



}


int main()
{
    nodo *inicio=nullptr;
    
    inicio=load_of_words(inicio);
    space_jump();
    impresion_datos(inicio);
    nodo* inicio_repetidos=nullptr;


}