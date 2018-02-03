/*
 11988 - Broken Keyboard (a.k.a. Beiju Text)
 UVa Online Judge
 Ramon Hossein
 */

#include <iostream>
#include <list>
using namespace std;


int main() {
    string phrase;
    list<char> line;
    list<char>::iterator character;
    
    while(getline(cin , phrase)) {
        line.clear();
        character = line.begin();
        
        for(int i=0; i < phrase.size(); i++) {
            if(phrase[i]=='[')
                character = line.begin();
            if(phrase[i]==']')
                character = line.end();
            if(phrase[i]!='[' && phrase[i]!=']')
                line.insert(character,phrase[i]);
        }
        
        for(character = line.begin(); character != line.end(); character++) {
            cout << *character;
        }
        
        cout << endl;
    }
    return 0;
}
