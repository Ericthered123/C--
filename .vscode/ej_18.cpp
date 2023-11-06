/*Cargar en una lista circular, insertando al final, los títulos de las charlas que se darán en una conferencia de
tecnología. Independientemente de cómo las ingrese el usuario, se deben almacenar con la primera letra en
mayúscula y el resto en minúsculas.
a) Imprimir la lista resultante.
b) Solicitar al usuario el ingreso de un título e informar si existe en la lista. 
La búsqueda debe ser 
"case insensitive" (es decir, sin importar que se ingrese con diferentes mayúsculas y minúsculas, 
si el título coincide debe informarse que existe).
*/



#include <iostream>
#include <cctype>
#include <cstring>
#include <thread>
#include <chrono>

using namespace std;

struct nodo
{
    string titulo;
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
    cout << aux->titulo<< '|';
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

string capitalize(string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (i==0)
        {
            word[i]=toupper(word[i]);
        }
        else
        {
            word[i]=tolower(word[i]);
        }
    }
    return word;
}


nodo* load_of_titles(nodo* end)
{              
    bool deseo=true;
    string title;   
    nodo *nuevo;
    cout << "Ingresar titulo a guardar: ";
    getline(cin>>ws,title);
    title=capitalize(title);
    while (deseo)              
    {
        nuevo=new nodo;
        nuevo->titulo=title;
        end=insert_at_circular_end(end,nuevo);
        deseo=verify_wish(); 
        cout<< endl<<endl;   
        if (not deseo)
        {
            cout <<endl<<" FINISHING CHARGE...";
            std::this_thread::sleep_for(std::chrono::seconds(3));
            break;
        }    
        cout << "Ingresar titulo a guardar: ";
        getline(cin>>ws,title);
        title=capitalize(title);

    }                                
    return end;
}

void look_for_title_existence(nodo* end)
{
    string looked_title;
    cout << "Ingrese titulo a buscar: ";
    getline(cin>>ws,looked_title);
    looked_title=capitalize(looked_title);
    nodo* aux=end->siguiente;
    do
    {

        if (looked_title==aux->titulo)
        {
            cout <<endl<< " El titulo "<< looked_title<< " se encuentra en el listado...";
            return;
        }
        aux=aux->siguiente;
     } while (aux!=end->siguiente);
    cout <<endl<< " El titulo "<< looked_title<< " no se encuentra en el listado...";

}
int main()
{
    nodo* titulos_pointer=nullptr;
    titulos_pointer=load_of_titles(titulos_pointer);
    space_jump();
    print_circular_list(titulos_pointer);
    space_jump();
    look_for_title_existence(titulos_pointer);


}