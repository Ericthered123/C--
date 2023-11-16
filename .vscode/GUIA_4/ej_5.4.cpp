/*  Escribir una función recursiva que calcule 
    la suma de los cuadrados de los N primeros números positivos.
    Ejemplo: si N=4 la suma es 1**2 + 2**2 + 3**2 + 4**2 = 30.
*/



#include <iostream>
#include <cstring>
#include <cctype>
#include <thread>
#include <chrono>
#include <cmath>


using namespace std;



int sumatory_of_squares(int num)
{
    if (num==1)
    {
        return 1;
    }
    return pow(num,2)+sumatory_of_squares(num-1);
}


int main()
{
    int num;
    cout << "Σ i^2 --- INSERT AMOUNT THE LIMIT OF THE SUMATORY: ";
    cin >> num;
    cout << "The Square sumatory of the first "<< num << " numbers is equal to= "<< sumatory_of_squares(num);
    
}