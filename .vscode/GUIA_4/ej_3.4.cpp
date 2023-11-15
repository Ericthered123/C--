/*Escribir una función recursiva que, dado un número entero, lo imprima en orden inverso.

Ejemplo: si el número es 5182, la función debe imprimir 2815.*/



#include <iostream>
#include <cstring>
#include <cctype>
#include <thread>
#include <chrono>

using namespace std;


int invert_num(int num, int num_len)
{
    string num_invert;
    if (num_len==0)
    {
        return 0;
    }
    return num%10*invert_num(num,num_len-1);



}





int main()
{
    int num_len=0;
    int num;
    cout << "INSERT NUMBER TO REVERSE IT: ";
    cin >> num;
    num_len=to_string(num).length();
    cout << "El numero "<< num << " invertido es: "<< invert_num(num,num_len);
    cout << num_len;

}
