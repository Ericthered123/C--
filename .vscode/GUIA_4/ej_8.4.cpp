/*Escribir una función recursiva que reciba un string y lo retorne con sus caracteres invertidos.
Nota: Podría ser útil la función substr que obtiene un substring a partir de un string.*/



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
    for (int i = word.length()-1; i >0; i--)
    {
        inverted_word+=word[i];
    }
    return inverted_word;


}


string invert(string word, int word_ws)
{
    

    if (word_ws==0)
    {
        return "";
    }
    return inversion(word.substr(0,word.find(" ")))+invert(word,word_ws-1);



}

int amount_of_ws(string word)//TODO
{
bool verifier=true;
int amount=0;
while (verifier)
{
    if (word.find())
    {
        amount++;
    }
    
}
return amount+1;

}


int main()
{
    string word;
    string inverse_w="";
    int w_ws;
    cout << "INSERT WORD: ";
    getline(cin>>ws,word);
    w_ws=amount_of_ws(word);
    cout << w_ws;
    cout << "Your word "<< word<< " inverted is equal to: "<< invert(word,w_ws);
    

}