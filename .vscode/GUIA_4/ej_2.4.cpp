/*Graficar la pila de llamadas (colocando parámetros y valores de retorno):
int sumatoria(int num) {
 if (num == 0)
 return 0;
 return sumatoria(num-1) + num;
}
int main() {
 cout << sumatoria(5);
 return 0;
}*/





#include <iostream>
#include <cstring>
#include <cctype>
#include <thread>
#include <chrono>

using namespace std;



int sumatoria(int num, int multi) {
 if (multi == 0){ 
 return 0;
}
 return sumatoria(num,multi-1) + num;// 
}
int main() {
 cout << sumatoria(5,5);
 return 0;
}