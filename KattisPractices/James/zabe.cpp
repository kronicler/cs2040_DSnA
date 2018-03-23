#include <iostream>
using namespace std;

int main () {
	int elements;

	cin >> elements;
	int start[elements], end[elements];
	for (int i = 0; i < elements; i++)
		scanf("%d", &start[i]);

	for (int i = 0; i < elements; i++)
		scanf("%d", &end[i]);

	return 0;
}