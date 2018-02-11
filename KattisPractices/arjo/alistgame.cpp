#include <iostream>
using namespace std;
int primeFactors(int n){
	int count = 0;
	int x = 2;
	while(x*x <= n){
		if(n%x == 0){
			count++;
			n/=x;
		}
		else{
			x++;
		}
	}
	return count+1;
}

int main(){
	int len;
	cin >> len;
	cout << primeFactors(len) << std::endl;
	return 0;
}
