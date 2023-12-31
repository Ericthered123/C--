/*Escribir una función recursiva que reciba una palabra y retorne true si es palíndromo,
 false si no lo es
(diferenciando mayúsculas y minúsculas).
Ejemplo: si la palabra es "radar" retorna true.
Nota 1: Un palíndromo es una palabra que se lee igual en un sentido que en otro.
Nota 2: Podría ser útil la función substr que obtiene un substring a partir de un string.*/



#include <iostream>
#include <cstring>
#include <cctype>
#include <thread>
#include <chrono>
#include <cmath>

using namespace std;




string inversion(string word)
{
    string inverted_word;
    for (int i = word.length(); i >0; i--)
    {
        inverted_word+=word[i-1];
    }
    return inverted_word;


}

bool palindrome_verification(string word,int w_len,string inverted)
{     
    if (word[w_len]!=inverted[w_len])
    {
        return false;
    }
    if (w_len==0)
    {
        return true;
    } 
    if (word[w_len]==inverted[w_len])
    {
        return  palindrome_verification(word,w_len-1,inverted);
    }
        
}
    






int main()
{
    string word,inverted;
    cout << "INSERT ONE WORD: ";
    cin >> word;
    inverted=inversion(word);
    if (palindrome_verification(word,word.length()-1,inverted))
    {
        cout << '\t'<< "THE WORD "<< word << " IS A PALINDROME";
    }
    else
    {
        cout << '\t'<< "THE WORD "<< word << " IS NOT A PALINDROME";
    }




}