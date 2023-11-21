// Grupo 1: Falcon Franco-Ilafaya Jose;Petrillo Facundo;Doyle Eric; Giecco Francisco



/*-------Desafío 1: “Suma de pares”------------

Escribir en C++ una función recursiva que reciba un arreglo de tipo int, su dimensión lógica y 
cualquier otro parámetro de ser necesario. 
Finalmente, debe retornar la suma de los elementos pares almacenados en el arreglo. 
En caso de no haber números pares, debe retornar 0. 
Ejemplo: dado el arreglo [ 4, 5, 10, 17, 2, 3 ] debe retornar 16.

---------Desafío 2: “Suma de todos los elementos”-----------

Escribir en C++ una función recursiva que, dada una lista simplemente enlazada de enteros, 
retorne la suma de todos sus elementos. 
En caso de que la lista esté vacía, deberá retornar 0. 
Ejemplo: si la lista contiene los nodos 5 - 2 - 1 - 9, debe retornar 17*/




#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
#include <thread>
#include <chrono>


using namespace std;




struct Nodo 
{
    int dato;
    Nodo *siguiente;
};

void insertar_al_final(Nodo *&inicio) // Funcion para cargar la lista
{
    Nodo *nuevo;
    int numero;
    cout << "\nIngrese un entero(0 para cortar): ";
    cin >> numero;
    while (numero != 0) // Condicion de corte 
    {
        nuevo = new Nodo;
        nuevo->dato = numero;
        nuevo->siguiente = nullptr; 
        if (inicio == nullptr) 
        {
            inicio = nuevo;
        }
        else 
        {
            Nodo *aux = inicio;
            while (aux->siguiente != nullptr)
            {
                aux = aux->siguiente;
            }
            aux->siguiente = nuevo;
        }
        cout << "\nIngrese un entero(0 para cortar): ";
        cin >> numero;
    }
}

int suma_elementos(Nodo* inicio){
    if (inicio == nullptr) // Validacion de si la lista esta vacia.
    {
        return 0; // Retorna 0 como indica la consigna
    }
    
    return inicio->dato + suma_elementos(inicio->siguiente); // Si no lo esta va a ir sumando los numeros contenidos dentro de cada nodo

    
}
// Funcion que valida si un numero es par, si lo es retorna a, sino retorna 0 por ser un numero impar.
int paridad(int a)
{
    if (a%2==0) 
    {
        return a;
    }
    else
    {
        return 0;

    }
}




int suma_pares(int arreglo[],int dl)
{
    if (dl==0)
    {
        return paridad(arreglo[0]);// si el arreglo esta vacia, verifica si es par  y retorna 0 y lo suma o retorna el primer elemento del arreglo y lo suma.
    }
    return paridad(arreglo[dl])+suma_pares(arreglo,dl-1);//Aqui se ve el caso recursivo, donde se va verificando la paridad de cada elemento del arreglo y se hace la sumatoria de los pares

}

int main()
{
    cout << '\t'<< "***DESAFIO 1***"<<endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));// Pausa del programa, de 5 segundos
    int arreglo[]={4,5,10,17,2,3};
    int dl=6;
    cout <<endl<< "La suma de numeros pares es igual a: "<< suma_pares(arreglo,dl-1);
    std::this_thread::sleep_for(std::chrono::seconds(3)); 
    cout << endl <<endl <<endl << '\t'<< "***DESAFIO 2***"<<endl;
    Nodo* inicio = nullptr; // Puntero inicial 
    insertar_al_final(inicio);
    cout<<"La suma de los elementos de la lista es: "<<suma_elementos(inicio);
    std::this_thread::sleep_for(std::chrono::seconds(5));
}