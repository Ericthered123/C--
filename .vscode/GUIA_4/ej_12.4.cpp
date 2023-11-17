/*Escribir una función recursiva que reciba un arreglo de int y su dimensión lógica, y retorne la suma de los
elementos pares almacenados en el arreglo. En caso de no haber números pares, debe retornar 0.
Ejemplo: Dado el arreglo [ 4, 5, 10, 17, 2, 3 ] retornará 16.*/



#include <iostream>
#include <cstring>
#include <cctype>
#include <thread>
#include <chrono>
#include <cmath>

using namespace std;


int parity(int a)
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
        return parity(arreglo[0]);
    }
    return parity(arreglo[dl])+suma_pares(arreglo,dl-1);       

}   


int main()
{
    int arreglo[]={4,5,10,17,2,4};
    int dl=6;
    cout << "La suma de los numeros pares del arreglo es igual a: "<< suma_pares(arreglo,dl-1);

}