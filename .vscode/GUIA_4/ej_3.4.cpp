/*Escribir una función recursiva que, dado un número entero, lo imprima en orden inverso.

Ejemplo: si el número es 5182, la función debe imprimir 2815.*/



#include <iostream>
#include <cstring>
#include <cctype>
#include <thread>
#include <chrono>

using namespace std;


int invert_num(int num, int resultado=0)
{
    if (num < 10) {
        return resultado * 10 + num;
        }   
    resultado = (resultado * 10) + (num % 10);
    return invert_num(num / 10, resultado); 

}





int main()
{
    int num_len=0;
    int num;
    cout << "INSERT NUMBER TO REVERSE IT: ";
    cin >> num;
    cout << "El numero "<< num << " invertido es: "<< invert_num(num);


}
