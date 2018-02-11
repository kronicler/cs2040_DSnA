#include <iostream>
#include <queue>
using namespace std;
int main(int argc, char** argv){
	deque<char> text;
	char c;
	while(cin >> c){
		if(c!='<') text.push_back(c);
		else{
			if(text.size() > 0) text.pop_back();
		}
	}
	for(int i = 0; i < text.size(); i++) cout << text[i];
        if(text.size() > 0) cout <<endl;	
}
