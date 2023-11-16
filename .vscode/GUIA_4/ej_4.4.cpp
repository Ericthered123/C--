/*  Escribir una función recursiva que, dado un número entero, 
    retorne la cantidad de dígitos que tiene.
    Ejemplo: si el número es 650, la función debe retornar 3*/



#include <iostream>
#include <cstring>
#include <cctype>
#include <thread>
#include <chrono>

using namespace std;


int search_digits(int num,int q_digits=1)
{
    if (num<1)
    {
        return 0;
    }
    
    return q_digits + search_digits(num/10);



}


int main()
{
    int num;
    int num_len=0;
    num_len= to_string(num).length();
    cout << "INSERT NUMBER TO KNOW ITS DIGITS: ";
    cin >> num;
    cout <<endl<< '\t' <<"Number "<< num << " has "<< search_digits(num)<< " digits";
}