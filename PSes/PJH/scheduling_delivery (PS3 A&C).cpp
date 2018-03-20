#include <bits/stdc++.h>
using namespace std;
typedef tuple <int,int,string> info;
priority_queue<info> data;
unordered_map <string,info> data2;
unordered_map <string,int> flag;
long long int order = 200000;

void ArriveAtHospital(string womanName,int dilation){
	info a;
	a = info(dilation,order,womanName);
	data.push(a);
	data2[womanName]=a;
	flag[womanName]=0;
	order--;
}

void UpdateDilation(string womanName, int increasedilation){
    get<0>(data2[womanName]) += increasedilation; //change the first element of the tuple
    data.push(data2[womanName]);
}

void GiveBirth(string womanName){
	info temp;
	if (data.empty())
        cout<<"The delivery suite is empty"<<endl;
	else if (get<2>(data.top())== womanName){
		data.pop();
		flag[womanName]++;
	}
	else
	    flag[womanName]++;
}

string Query () {
	string name;
    name = get<2>(data.top());
    while((flag[name]!=0) && (!data.empty())) {
        data.pop();
        name = get<2>(data.top());
    }
	if (data.empty())
        name = "The delivery suite is empty";

	return name;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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
    else if(command==1){
        cin>>name>>incdilation;
        UpdateDilation(name,incdilation);
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
