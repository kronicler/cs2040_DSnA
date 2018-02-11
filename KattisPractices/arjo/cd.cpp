#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool process () {
	int M, N;
	cin >> M >> N;
	if( M == 0 && N == 0) return false;
	vector<int> jack,jill;
	//cout << M <<endl;
	for(int i = 0 ; i < M; i++){
		int k;
		cin >> k;
		jack.push_back(k);
	}
	for(int i = 0 ; i < N; i++){
		int k;
		cin >> k;
		jill.push_back(k);
	}
	vector<int> res(M+N);
	vector<int>::iterator it = set_intersection(jack.begin(),jack.end(), jill.begin(),jill.end(),res.begin());
	cout << it-res.begin() << endl;
	return true;
}

int main(int argc, char** agv) {
	while(process());
	return 0;
} 
