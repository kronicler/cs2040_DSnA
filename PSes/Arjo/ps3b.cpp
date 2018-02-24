#include <bits/stdc++.h>
using namespace std;
queue<string> pq[110];
//unordered_map<string, int> arrival_index; 
//vector<string> women_by_arrival;
int num_women=0;
int arrival = 0;
int curr_max = 0;

void ArriveAtHospital(string& womanName, int dilation){
	//women_by_arrival.push_back(womanName);
	//cout << "adding women" <<womanName <<dilation<<endl;
	pq[dilation].push(womanName);
	curr_max = (dilation > curr_max)? dilation: curr_max;
	//arrival++;
	num_women++;
}
int getMaximaQueue(){
	for(int i = curr_max; i >=0 ;i--){
		if(!pq[i].empty()){ 
			return i;
		}
	} 
	return -1;
}
void GiveBirth(string& womanName){
	num_women--;
	int k = getMaximaQueue();
	pq[k].pop();
	if(pq[k].empty()) curr_max--;
}
void Query() {
	if(num_women>0){
		//cout << "getting dilation"<<maxima.top() <<endl;
		cout << pq[getMaximaQueue()].front() <<endl;
	} else{
		cout << "The delivery suite is empty"<<endl;
	}
}


int main(int argc, char** argv) {
	int commands;
	cin >> commands;
	for(int i = 0 ; i < commands; i++){
		int j, dil;
		string name;
		cin >> j;
		switch(j){
			case 0:
				cin >> name >> dil;
				ArriveAtHospital(name,dil);
				break;
			case 2: 
				cin >> name;
				GiveBirth(name);
				break;
			case 3:
				Query();
				break;	
		}
	}
}
