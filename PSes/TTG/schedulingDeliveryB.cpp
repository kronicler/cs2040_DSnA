#include <bits/stdc++.h>

using namespace std;

void ArriveAtHospital(string womanName, int dilation);
void UpdateDilation(string womanName, int increaseDilation);
void GiveBirth(string womanName);
string Query();

queue<string> womanlist[101];
int id=200000,noPatients=0;

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
    womanlist[dilation].push(womanName);
}
void GiveBirth(string womanName){
    int i = 100;
	for (i;i>=30;i--){
        if (womanlist[i].empty())
            continue;
        break;
	}
	womanlist[i].pop();
}
string Query(){
	int i = 100;
	for (i;i>=30;i--){
        if (womanlist[i].empty())
            continue;
        return womanlist[i].front();
	}
	return "The delivery suite is empty";
}
