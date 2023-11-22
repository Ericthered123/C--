/*Dos sucursales de Fiestísima disponen cada una de una lista enlazada simple con el detalle de las ventas
realizadas. De cada venta se conoce: código de producto y cantidad vendida (un producto pudo haber sido
vendido 0, 1 o más veces en la misma sucursal). Las listas de ventas están ordenadas de menor a mayor por
código de producto.//TODO Realizar una función que reciba las dos listas y retorne una nueva lista unificando todas las
ventas, ordenada por el mismo criterio. 
Utilizar un algoritmo destructivo (que reutilice los nodos de las listas
originales). Agregar las funciones auxiliares que sean necesarias. */



#include <iostream>
#include <cstring>
#include <thread>
#include <chrono>

using namespace std;

struct venta_P
{
    int code_P;
    int quantity_sold;
};

struct nodo
{
    venta_P venta;
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

nodo* insert_by_order(nodo* inicio,nodo* nuevo)
{
    if (inicio==nullptr || nuevo->venta.code_P < inicio->venta.code_P)
    {
        inicio=nuevo;
    }
    else
    {
    nodo* aux=inicio;
    while (aux->siguiente != nullptr && aux->siguiente->venta.code_P < nuevo->venta.code_P) 
        {
        aux = aux->siguiente;
        }
    nuevo->siguiente = aux->siguiente;
    aux->siguiente = nuevo;
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


void print_list_of_sold_items(nodo *inicio,int w)
{   
    int i=1;
    cout << '\t' <<"|SOLD ITEMS---SUCURSAL "<<w<<"|"<<endl;
    for (nodo  *aux = inicio; aux!=nullptr; aux=aux->siguiente)
    {
        cout << "Producto "<< i <<"-";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << "|Codigo= " << aux->venta.code_P<< " Cantidad vendida= "<< aux->venta.quantity_sold << '|';
        cout <<endl;
        i++;
        
    }
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

int verify_code(nodo* inicio,int codigo_nuevo)
//TODO this can get better, verification not working for second element
{
     
    for (nodo*aux = inicio; aux!=nullptr; aux=aux->siguiente)
        {
            if (aux->venta.code_P==codigo_nuevo)
            {
                cout << " Ese codigo ya esta en la lista..."<<endl;
                std::this_thread::sleep_for(std::chrono::seconds(5));
                cout << "Ingrese otro codigo: ";
                cin >> codigo_nuevo;
            }
                
        }
    
    return codigo_nuevo;
}

void verify_adequate_quantity(int &nueva_cant)
{
    while (nueva_cant<0)
    {
        cout <<endl<< "Ingrese una cantidad valida!!!!!";
        cin >> nueva_cant;

    }

}



nodo* charge_of_sold_items(nodo* head)
{
    bool deseo=true;
    nodo *nuevo;
    venta_P venta;
    cout << "Ingresar codigo del producto : ";
    cin >> venta.code_P;
    while (deseo)
    {
        nuevo=new nodo;
        nuevo->siguiente=nullptr;
        cout << "Ingrese la cantidad de producto vendido: ";
        cin >> venta.quantity_sold;
        verify_adequate_quantity(venta.quantity_sold);
        nuevo->venta=venta;
        head=insert_by_order(head,nuevo);
        deseo=verify_wish();
        if (not deseo)
        {
            cout << "Finalizando..."<<endl;
            std::this_thread::sleep_for(std::chrono::seconds(3));
            break;
        }
        cout << "Ingresar codigo del producto : ";
        cin >> venta.code_P;
        venta.code_P=verify_code(head,venta.code_P);

    }
    return head;
}

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
    if (a->venta.code_P <= b->venta.code_P) {
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
    int sucursal=1;
    nodo* head=nullptr;
    nodo* head_2=nullptr;
    head=charge_of_sold_items(head);
    space_jump();
    print_list_of_sold_items(head,sucursal);
    space_jump();
    head_2=charge_of_sold_items(head_2);
    sucursal++;
    print_list_of_sold_items(head_2,sucursal);
    space_jump();
    nodo* head_merged=nullptr;
    head_merged=merge(head,head_2);
    sucursal=1;
    print_list_of_sold_items(head_merged,sucursal);
    

}