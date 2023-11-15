/*Dado el siguiente programa, analizarlo (sin ejecutarlo en la máquina) e indicar qué calcula. ¿Cuál es el caso
base de este algoritmo? ¿Y el caso recursivo?
#include <iostream>
using namespace std;
int funcion(int m, int n) {
 if (n == 0) {
 return 0;
 }
 return m + funcion(m, n-1);
}
int main() {
 cout << funcion(20, 3);
 return 0;
}      */





#include <iostream>
#include <cstring>
#include <cctype>
#include <thread>
#include <chrono>

using namespace std;


int funcion(int m, int n) {
 if (n == 0) { // CASO BASE cuando N=0
 return 0;
 }
 return m + funcion(m, n-1); //Caso recursivo 20+20+20
}
int main() {
 cout << funcion(20, 3);
 return 0;
}   