#include <iostream>
using namespace std;

void insertionsort (int arr[], int size) {
	int i, j, x;
	
	for (i = 1; i < size; i++) {
		x = arr[i];
		for (j = i-1; j >= 0 && arr[j] > x; j--) {
			arr[j+1] = arr[j];
		}
		arr[j+1] = x;
	}
}

void print (int arr[], int size) {
	int i;
	
	for (i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	
	cout << endl;
}
	

int main () {
	int arr[10000], size, i;
	
	cin >> size;
	
	for (i = 0; i < size; i++) {
		cin >> arr[i];
	}
	
	insertionsort(arr, size);
	print(arr,size);
	
	return 0;
}
