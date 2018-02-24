#include <bits/stdc++.h>
using namespace std;
class Hospital { 
private:
	map<int, set<int> >dilation_q;
	unordered_map<string, int> arrival_index; 
	unordered_map<string, int> get_woman_by_name;
	vector<string> women_by_arrival;
	int num_women=0;
	int arrival = 0;
public:
	void ArriveAtHospital(string womanName, int dilation){
		get_woman_by_name[womanName] = dilation;
		dilation_q[dilation].insert(arrival);
		num_women++;
		arrival_index[womanName] = arrival;
		arrival++;
		women_by_arrival.push_back(womanName);
	}
	void UpdateDilation(string womanName, int increaseDilation){
		int dil = get_woman_by_name[womanName];
		get_woman_by_name[womanName] = increaseDilation + dil;
		dilation_q[dil].erase(arrival_index[womanName]);
		if(dilation_q[dil].empty()) dilation_q.erase(dil);
		dilation_q[increaseDilation +dil].insert(arrival_index[womanName]);	
	}
	void GiveBirth(string womanName){
		int dil = get_woman_by_name[womanName];
		//cout << "erasing from dilation_q" <<endl;
		dilation_q[dil].erase(arrival_index[womanName]);
		if(dilation_q[dil].empty()) dilation_q.erase(dil);
		//cout << "erasing from woman_by_name" <<endl;
		get_woman_by_name.erase(womanName);
		num_women--;
	}
	void Query() {
		if(num_women>0){
			//cout << "getting dilation" <<endl;
			auto it = dilation_q.rbegin();
			//cout << it->first <<endl;
			//cout << "looking up name" <<endl;
			cout << women_by_arrival[*(it->second.begin())]<<endl;
		} else{
			cout << "The delivery suite is empty"<<endl;
		}
	}
};

int main(int argc, char** argv) {
	int commands;
	Hospital h;
	cin >> commands;
	for(int i = 0 ; i < commands; i++){
		int j, dil;
		string name;
		cin >> j;
		switch(j){
			case 0:
				cin >> name >> dil;
				h.ArriveAtHospital(name,dil);
				break;
			case 1:
				cin >> name >> dil;
				h.UpdateDilation(name,dil);
				break;
			case 2: 
				cin >> name;
				h.GiveBirth(name);
				break;
			case 3:
				h.Query();
				break;	
		}
	}
}
