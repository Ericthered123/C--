/*Escribir una función recursiva para calcular la potencia de un número. La función recibirá como parámetros al
número y un exponente (ambos enteros positivos), y retornará la potencia:
int potencia(int numero, int exponente)
Nota 1: Cualquier número elevado a la 0 da como resultado 1. El 0 elevado a cualquier número positivo dará
siempre como resultado 0.
Nota 2: Puede definirse que X^n = X * X^n-1*/



#include <iostream>
#include <cstring>
#include <cctype>
#include <thread>
#include <chrono>
#include <cmath>

using namespace std;


int potencia(int numero,int exponente)
{
    if (exponente==0)
    {
        return 1;
    }
    return numero*pow(numero,exponente-1);    


}



int main()
{
    int num,exponent=-2;
    cout << "INSERT BASE= ";
    cin >> num;
    cout << endl;
    while (exponent<0)
    {
        cout << "INSERT EXPONENT= ";
        cin  >> exponent;
        if (exponent<0)
        {
            cout <<endl<< "Exponent must be a positive integer or 0!!!";
            continue;
        }
    }
    
    cout << num<< " to the power of "<< exponent<< " is equal to = "<< potencia(num,exponent);



}