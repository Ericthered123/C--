/*Escribir una función recursiva que calcule el producto de dos números naturales, usando sumas.
Ejemplo: 2*3 se puede calcular como 2+2+2.*/


#include <iostream>
#include <cstring>
#include <cctype>
#include <thread>
#include <chrono>
#include <cmath>

using namespace std;




int product(int factor1,int factor2)
{
    if (factor2==0)
    {
        return 0;
    }
    return factor1+product(factor1,factor2-1);

}





int main()
{
    int factor_1,factor_2;
    cout <<'\t'<< "***INSERT FACTORS TO CALCULATE THEIR PRODUCT***"<<endl;
    cout << "X=";
    cin >> factor_1;
    cout << endl<< "Y=";
    cin >> factor_2;
    cout << endl<< "PRODUCT OF FACTORS " << factor_1 << " and "<< factor_2<<" EQUAL TO= "<< product(factor_1,factor_2);



}