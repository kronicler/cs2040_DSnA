#include <iostream>
#include <string>
using namespace std;
	
int main () {
	int i = 0;
	string str, str1;

	getline(cin, str);
	
	while (str[i] != '\0') {
		if(isupper(str[i])) str1 += str[i];
		i++;
	}
	
	str1 += '\0';
	cout << str1 << endl;
	return 0;
}
