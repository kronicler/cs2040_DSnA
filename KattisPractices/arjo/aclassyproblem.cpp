#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
using namespace std;
int _label2val(char c){
	switch(c){
		case 'u':
			return 0;
		case 'm':
			return 1;
		default:
		return 2;
	}
}

int _class_to_rank(string _class){
	long accum = 0, weight = 59049;
	for(int  i = _class.size()-1; i >= 0; i--){
		if('-' == _class[i]){
			accum += weight *_label2val(_class[i+1]);
			weight/=3;
		}
		else if(i == 0){
			accum += weight *_label2val(_class[0]);
			weight/=3;
		}
	}
	for(; weight > 1; weight/=3){
		accum += weight;
	}
	return accum;
}
void sort_classes(){
	int num_people;
	cin >> num_people;
	vector<pair<int, string> > ppl;
	for(int i = 0; i < num_people; i++){
		string name,_class,tmp;
		cin >> name >> _class >> tmp;
		int rank = _class_to_rank(_class);
		ppl.push_back(pair<int,string>(rank,name));
	}	
	sort(ppl.begin(),ppl.end());
	for(auto v: ppl){
		cout << v.second.substr (0,v.second.size()-1) <<endl;
	}
	cout <<"=============================="<<endl; 
}
int main(int argc, char ** argv){
	int test_cases;
	cin >> test_cases;
	for(int i = 0; i < test_cases; i++){
		sort_classes();
	}	
}
