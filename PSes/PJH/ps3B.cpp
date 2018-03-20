#include <bits/stdc++.h>
using namespace std;
typedef tuple <int,int,string> info;
priority_queue<info> data;
unordered_map <string,info> data2;
long long int order = 200000;


void ArriveAtHospital(string womanName,int dilation){
	info a;
	a = info(dilation,order,womanName);
	data.push(a);
	order--;
	data2[womanName]=a;
}

void GiveBirth(string womanName){
	info temp;
	if (data.empty())
        cout<<"The delivery suite is empty"<<endl;
	else if (get<2>(data.top())== womanName){
		data.pop();
}
}

string Query () {
	string name;
    name = get<2>(data.top());
	if (data.empty())
        name = "The delivery suite is empty";

	return name;
}

int main () {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);


	long long int n ;
	string name;

    for(cin>>n;n!=0;n--){

    int command,dilation,incdilation;
    string name;

    cin >> command;

    if (command==0){
        cin>>name>>dilation;
        ArriveAtHospital(name,dilation);
    }
    else if(command==2){
        cin>>name;
        GiveBirth(name);
    }
    else {
        name = Query();
        cout << name << endl;
    }
        }
        return 0;
}
