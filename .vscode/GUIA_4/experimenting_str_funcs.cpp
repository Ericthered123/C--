

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

int main()
{
    string word;
    string inverse_w="";
    int w_len=word.length()-1;
    cout << "INSERT WORD: ";
    getline(cin>>ws,word);
    cout << "Inverted word: "<< inversion(word);
    cout << endl<< word.substr(0,word.find(" "));


}