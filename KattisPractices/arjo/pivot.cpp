#include <iostream>
#include <limits.h>

using namespace std;
int array[100000];
short minmask[100000],maxmask[100000];
int n;
int main(int argc, char** argv){
	cin >> n;
	int max = INT_MIN;
	for(int i = 0; i < n; i++){
		cin >> array[i];
		if(array[i] > max){
			maxmask[i] = 1;
			max =array[i];
		}
		else{ 
			maxmask[i] = 0; 
		}		
	}
	int min = INT_MAX;
	for(int i=n-1; i >= 0; i--){
		if(array[i] < min){
			minmask[i] = 1;
			min = array[i];
		}
		else{
			minmask[i] = 0;
		}
	}
	int cnt = 0;
	for(int i=0; i < n; i++){
		if(minmask[i] & maxmask[i]) cnt++;
	}
	cout << cnt;
}
