/*  Escribir una función recursiva que reciba un arreglo de int y su dimensión lógica, y retorne el primer número
    impar encontrado en el arreglo. En caso de no haber números impares, debe retornar 0.
    Ejemplo: Dado el arreglo [ 2, 0, 8, 7, 4, 3 ] retornará 3.*/



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
        return 0;
    }
    else
    {
        return a;

    }


}


int busqueda_impar(int arreglo[],int dl)
{
    if (dl==0)
    {
        return 0; 
    }
    if ((arreglo[dl]%2)!=0)
    {
        return arreglo[dl];

    }
    return busqueda_impar(arreglo,dl);

}



int main()
{
    int arreglo[]={2,0,8,2,4,3};
    int dl=6;
    if (busqueda_impar(arreglo,dl)==0)
    {
        cout << "No hay numeros impares dentro del arreglo";
    }
    else
    {
        cout << "El primer numero impar encontrado en el arreglo es el: "<< busqueda_impar(arreglo,dl-1);
    }
    
}