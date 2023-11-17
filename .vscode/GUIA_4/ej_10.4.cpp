/*Indicar qué imprime el siguiente programa (sin ejecutarlo en la máquina). 
¿Cuál sería un nombre adecuado para la función llamada "f"?:*/



#include <iostream>
#include <cstring>
#include <cctype>
#include <thread>
#include <chrono>
#include <cmath>

using namespace std;




int min(int a, int b) {
 if (a < b)
 return a;
 else
 return b;
}


int f(int arreglo[], int dl) //La funcion "f" utiliza otra funcion llamada min que compara dos valores y retorna el menor
// En este caso se compara cada elemento del arreglo, utilizando la dimension logica para saber cuando se llega al final
// se retorna el elemento mas chico.
{
    if (dl == 1)
 return arreglo[0];
 else
 return min(arreglo[dl-1], f(arreglo, dl-1));
}
int main() {
 int a[] = { 6,2,3,7,9,4 };
 int dl = 6;
 cout << f(a, dl);
}