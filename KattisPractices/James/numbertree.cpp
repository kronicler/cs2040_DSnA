#include <iostream>
using namespace std;

void traverse (int* num, char direction, int root) {
	*num = root - (((root - *num)*2) + (direction == 'R'? 1 : 0));
}

int main() {
	int num;
	cin >> num;
	char str[num+1];
	num = (1 << (num+1)) -1;
	
	if (scanf("%s", str) == EOF) cout << num << endl;
	else {
		int root = num+1;
		int len = strlen(str);
		for (int i = 0; i < len; i++) {
			traverse(&num, str[i], root);
		}
		cout << num << endl;
	}
	return 0;
}