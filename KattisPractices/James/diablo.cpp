#include <iostream>
#include <cmath>
using namespace std;

const long double pi = 3.14159265358979328;
int main () {
	long double area, fencing;
	cin >> area >> fencing;
	long double radius = fencing/(2*pi);
	long double a = radius*radius*pi;
	(area <= a)? cout << "Diablo is happy!" << endl : cout << "Need more materials!" << endl;
	return 0;
}