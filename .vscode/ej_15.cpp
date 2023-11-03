/*"The Golden Gate Bridge" es el puente más famoso de la ciudad de San Francisco (California). Cuenta con una
longitud aproximada de 1280 metros y posee tres radares de toma de velocidad. Por cada móvil que se
desplaza por las vías principales se registra la siguiente información: sensor que lo captó (puede ser "norte",
"sur" o "medio"), patente (no tiene un formato único ya que difiere de un estado a otro y pueden transitar
autos extranjeros, aunque se sabe que están formadas sólo por letras y números) y velocidad en km/h.
A. Cargar las lecturas que hacen los sensores en una lista enlazada simple ordenando por patente y, para
la misma patente, ordenando por sensor (ya que un mismo automóvil puede ser captado por más de un
sensor). Finaliza con la patente "aaa99", que no se debe ingresar.
B. Dada la lista generada en el inciso anterior, armar tres listas: una por cada sensor (el orden de los
elementos tiene que ser el mismo que en la lista original). Luego, imprimir las tres listas.*/



#include <iostream>
#include <cctype>
#include <cstring>
#include <thread>
#include <chrono>

using namespace std;




struct fetched_data
{
    string sensor;
    string patente;
    float velocidad;
};


struct nodo
{
    fetched_data data;
    nodo* siguiente;
};

string lowering_word(string palabra)
{
    string low_word="";
    for (int i = 0; i < palabra.length(); i++)
    {
        low_word+=tolower(palabra[i]);
    }
    return low_word;

}

void space_jump()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    for (int i = 0; i < 20; i++)
    {
        cout << endl;
    }
}

string patent_verification(string low_word)
{
    getline(cin>>ws,low_word);
    int s=0;
    int len;
    low_word=lowering_word(low_word);
    len=low_word.length();
    while (isalpha(low_word[s])&&len!=0)
    {
        if (not isalpha(low_word[s]))
        {
            cout << "Ha ingresado una patente con un formato incorrecto(usar caracteres alfanumericos!!!)...";
            s=0;
            std::this_thread::sleep_for(std::chrono::seconds(3));
            cout << "Ingrese la patente con el formato correcto: ";
            getline(cin>>ws,low_word);
            low_word=lowering_word(low_word);
            len=low_word.length();
        }
        s++;
        len--;
    }
    return low_word;
}

void print_list(nodo *inicio)
{   
    cout << '\t' <<"|'GOLDEN STATE BRIDGE' FETCHED DATA OF SPEEDING|"<<endl<<'|';
    for (nodo  *aux = inicio; aux!=nullptr; aux=aux->siguiente)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout <<"|Patente del auto infractor: "<< aux->data.patente<< '|'<< "Captada por el sensor: "<< aux->data.sensor<< "| A la velocidad de: " << aux->data.velocidad<< " km/h|";
        cout << endl;
    }
}

string captor_sensor()
{
    string sensor;
    int opcion=3;
    cout << "\t"<< " ***SENSOR CAPTOR*** "<<endl;
    while (opcion<0||opcion>2)
    {
        cout << "[0] SENSOR 'SUR' "<<endl;
        cout << "[1] SENSOR 'MEDIO' "<<endl;
        cout << "[2] SENSOR 'NORTE' "<<endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 0:
            sensor="SUR";
            break;
        case 1:
            sensor="MEDIO";
            break;
        case 2:
            sensor="NORTE";
            break;
        default:
            cout<<endl<< "Ha ingresado una opcion incorrecta";
            break;
        }
    }
    return sensor;


}
nodo* insert_by_patent_number(nodo* head,nodo* nuevo)
{
    if (head==nullptr || nuevo->data.patente < head->data.patente)
    {
        head=nuevo;
    }
    else
    {
    nodo* aux=head;
    while (aux->siguiente != nullptr && aux->siguiente->data.patente < nuevo->data.patente) 
        {
        aux = aux->siguiente;
        }
    nuevo->siguiente = aux->siguiente;
    aux->siguiente = nuevo;
    }
return head;

}

nodo* load_sensor_data(nodo* head)
{ 
    nodo *nuevo;
    fetched_data data;
    cout << "Ingresar numero de patente a guardar('aaa99' para cortar): ";
    data.patente=patent_verification(data.patente);
    while (data.patente!="aaa99")              
    { 
        nuevo=new nodo;
        data.sensor=captor_sensor();
        cout << "Ingrese la velocidad captada por el sensor(mayor a 72.4 km/h): ";
        cin >> data.velocidad;
        if (data.velocidad<72.4)
        {
            cout << "ERROR DEL SENSOR, ese auto no infrigio la velocidad maxima permitida!!!";
            std::this_thread::sleep_for(std::chrono::seconds(3));
            cout << endl<< endl;
        }
        nuevo->data=data;
        head=insert_by_patent_number(head,nuevo);
        cout << "Ingresar numero de patente a guardar('aaa99' para cortar): ";
        data.patente=patent_verification(data.patente);
    }    
    return head;
}

int main()
{
    nodo* head=nullptr;
    head=load_sensor_data(head);
    space_jump();
    print_list(head);




}



