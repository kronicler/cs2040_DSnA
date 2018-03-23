#include <bits/stdc++.h>
#define MAX 100
using namespace std;

void sidewaySort(char cmp[][MAX], char str[][MAX], int r, int c) {
	char temp[MAX];
	for (int i = 0; i < c-1; i++) {
		for (int j = i+1; j < c; j++) {
				if (strcmp((cmp[i]), (cmp[j]))>0) {
					strcpy(temp, str[j]);
					strcpy(str[j], str[i]);
					strcpy(str[i], temp);
					strcpy(temp, cmp[j]);
					strcpy(cmp[j], cmp[i]);
					strcpy(cmp[i], temp);
				}
		}
	}
}

void printArr(char arr[][MAX], int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << arr[j][i];
		}
		cout << endl;
	}

	cout << endl;
}

int main(int argc, char const *argv[]) {
	int r, c;
	char arr[MAX][MAX], arrtemp[MAX][MAX];

	while (1) {
		cin >> r >> c;

		if (r+c == 0) break;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> arr[j][i];
				arrtemp[j][i] = tolower(arr[j][i]);
			}
		}
		cout << endl;
		sidewaySort(arrtemp, arr, r, c);
		printArr(arr, r, c);
	}


	return 0;
}
