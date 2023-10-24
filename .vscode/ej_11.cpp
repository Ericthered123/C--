/*Implementar una función que reciba dos listas enlazadas simples
con datos de tipo string ordenadas según el
alfabeto y retorne una tercera lista ordenada por el mismo criterio, 
conformada por todos los elementos de las      
listas originales (merge). 
Agregar las funciones auxiliares que sean necesarias para cumplir con este propósito*/



#include <iostream>
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
nodo* insertion(nodo *inicio,nodo *nuevo)
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
void impresion_palabras(nodo *inicio)
{   
    cout << '\t' <<"|Palabras enlazadas|"<<endl<<'|';
    for (nodo  *aux = inicio; aux!=nullptr; aux=aux->siguiente)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << aux->word<< '|';
    }
}

void impresion_merge(nodo *inicio)
{   
    cout << '\t' <<"|Union de palabras|"<<endl<<'|';
    for (nodo  *aux = inicio; aux!=nullptr; aux=aux->siguiente)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << aux->word<< '|';
    }
}

nodo* create_node(nodo *inicio,nodo*nuevo)
{
    nuevo->siguiente=inicio;
    return nuevo;


}
nodo* insertion_by_alphabet(nodo* head,nodo* nuevo)
{
    if (head==nullptr || nuevo->word < head->word)
    {
        nuevo->siguiente=head;
        head=nuevo;
    }
    else
    {
    nodo* aux=head;
    while (aux->siguiente != nullptr && aux->siguiente->word < nuevo->word) 
        {
        aux = aux->siguiente;
        }
    nuevo->siguiente = aux->siguiente;
    aux->siguiente = nuevo;
    }
return head;


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
        nuevo->word=word;
        inicio=insertion_by_alphabet(inicio,nuevo);
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



void reinsert_node(nodo* & lista_original, nodo* & lista_nueva) {
    nodo* anterior = lista_original;
    lista_original = lista_original->siguiente;
    anterior->siguiente = nullptr;
    lista_nueva = insertion(lista_nueva, anterior);
}

nodo* merge(nodo* a,nodo* b)
{
    nodo* c=nullptr;
    while (a != nullptr && b != nullptr) {
    if (a->word <= b->word) {
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



int main()
{
    nodo* inicio=nullptr;
    inicio=load_of_words(inicio);
    space_jump();
    impresion_palabras(inicio);
    space_jump();
    nodo* inicio_2=nullptr;
    inicio_2=load_of_words(inicio_2);
    space_jump();
    impresion_palabras(inicio_2);
    space_jump();
    nodo* merge_head=nullptr;
    merge_head=merge(inicio,inicio_2);
    impresion_merge(merge_head);
}
