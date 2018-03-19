#include <bits/stdc++.h>

using namespace std;

void ArriveAtHospital(string womanName, int dilation);
void UpdateDilation(string womanName, int increaseDilation);
void GiveBirth(string womanName);
string Query();

priority_queue<tuple<int,int,string>> womanlist;
unordered_map<string,bool> gaveBirthList;
unordered_map<string,int> updatedDilationValues;
unordered_map<string,int> idList;
int id=200000;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i,noCommands;
	cin >> noCommands;
	for (i=0;i<noCommands;i++){
		int command,dilation;
		string womanName;
		cin >> command;

		if (command == 0){
			cin >> womanName >> dilation;
			ArriveAtHospital(womanName,dilation);
		}
		else if (command == 1){
			cin >> womanName >> dilation;
			UpdateDilation(womanName,dilation);
		}
		else if (command == 2){
			cin >> womanName;
			GiveBirth(womanName);
		}
		else if (command == 3){
			cout << Query() << endl;
		}
	}
	return 0;
}

void ArriveAtHospital(string womanName, int dilation){
    // create new entry
	tuple<int,int,string> newEntry = make_tuple(dilation,id,womanName);
	womanlist.push(newEntry);
	gaveBirthList[womanName] = false;
	updatedDilationValues[womanName] = dilation;
	idList[womanName] = id;
	id--;
}
void UpdateDilation(string womanName, int increaseDilation){
    int newdilation = updatedDilationValues[womanName] + increaseDilation;
    updatedDilationValues[womanName] = newdilation;
    int old_id = idList[womanName];
    tuple<int,int,string> newEntry = make_tuple(newdilation,old_id,womanName);
    womanlist.push(newEntry);
}
void GiveBirth(string womanName){
    if (!womanlist.empty()){
        gaveBirthList[womanName] = true;
    }
}
string Query(){
	while (!womanlist.empty() && ((gaveBirthList[get<2>(womanlist.top())] == true) || (updatedDilationValues[get<2>(womanlist.top())] != get<0>(womanlist.top())))){
        womanlist.pop();
	}
    if (!womanlist.empty())
        return get<2>(womanlist.top());
    else
        return "The delivery suite is empty";
}
