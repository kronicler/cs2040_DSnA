#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int tasks[50] , n,T;
	cin  >> n >> T;
	for(int i = 0 ; i < n; i++) cin >> tasks[i] ;
	int sum = 0;
	int i = 0;
	while(sum < T && i < n){
		sum += tasks[i];
		i++;
	}
	cout << i-1<<endl;
	return 0;	
}
