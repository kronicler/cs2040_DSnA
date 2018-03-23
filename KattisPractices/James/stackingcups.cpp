#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

int main () {
	int num, i, j, arr[20], tempInt;
	string str1[20], str2[20], temp;

	cin >> num;

	for (i = 0; i < num; i++) {
		cin >> str1[i] >> str2[i];
		if (isdigit(str2[i][0])) {
			stringstream geek(str2[i]);
			geek >> arr[i];
			arr[i] *= 2;
		} else {
			stringstream geek(str1[i]);
			geek >> arr[i];
			str1[i] = str2[i];
		}
	}

	for (i = 0; i < num-1; i++) {
		for (j = 0; j < num-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				tempInt = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tempInt;
				temp = str1[j];
				str1[j] = str1[j+1];
				str1[j+1]= temp;
			}
		}
	}

	for (i = 0; i < num ; i++) {
		cout << str1[i] << endl;

	}

	return 0;
}