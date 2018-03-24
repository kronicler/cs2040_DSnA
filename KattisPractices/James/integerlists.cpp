//#include <iostream>
//#include <vector>
//#include <string>
#include <bits/stdc++.h>
using namespace std;

int main () {
	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		int data, flag, error, size;
		int left = 0, right;
		vector <int> vect(100001);
		char commands[100001] = {0};

		scanf("%s", commands);
		scanf("%d", &data);

		size = right = data;
		flag = error = 0;
		for (int j = 0; j < data; j++) {
			int numbers;
			char dump;
			if (j == 0) {
				scanf(" %c", &dump);
				scanf("%d", &numbers);
				scanf("%c", &dump);
			} else if (j == data-1) {
				scanf("%d", &numbers);
				scanf(" %c", &dump);
			} else {
				scanf("%d", &numbers);
				scanf("%c", &dump);
			}
			vect[j] = numbers;
		}

		if (!data) {
			char dump;
			scanf(" %c", &dump);
			scanf(" %c", &dump);
		}

		for (int j = 0; j < commands[j] != '\0'; j++) {
			if (commands[j] == 'R') {
				if (flag) flag = 0;
				else flag = 1;
			} else {
				if (size <= 0) {
					error = 1;
					cout << "error" << endl;
					break;
				} else {
					if (flag) {
						right--;
						size--;
					} else {
						left++;
						size--;
					}
				}
			}
		}


		if (!error) {
			cout << "[";
			if (flag) {
				for (int j = right-1; j >= left; j--) {
					if (j == left) cout << vect[j];
					else cout << vect[j] << ',';
				}
			} else {
				for (int j = left; j < right; j++) {
					if (j == right-1) cout << vect[j];
					else cout << vect[j] << ',';
				}
			}
			cout << "]\n";
		}
	}

	return 0;
}
