#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
#include <limits>
using namespace std;

void debugSet(set<int> t){
	for(auto i : t){
		cout << i << "\t";
	}
	cout << endl;
}
void solve(unordered_map<string, set<int> >& contents,vector<string>&  path){
	int largest_store = 0;
	for(int i = 0; i < path.size(); i++){
		//cout << "increasing i" <<endl;
		auto lower_b = contents[path[i]].lower_bound(largest_store);
		//cout << "Increasing run:" << *lower_b <<"\t"<< largest_store << endl;
		//cout << "initial: " ; debugSet(contents[path[i]]);
		if(lower_b != contents[path[i]].begin() && contents[path[i]].size() !=0)
		contents[path[i]].erase(contents[path[i]].begin(), lower_b);
		//cout << "final: " ; debugSet(contents[path[i]]);
		if(contents[path[i]].size() > 0) {
           	  	largest_store = max(*contents[path[i]].begin(), largest_store);
        	} 
	}
	int smallest_store = numeric_limits<int>::max();
	for(int i = path.size()-1; i >= 0; i--){
		//cout << "decreaing i"<<endl;
		auto lower_b = contents[path[i]].upper_bound(smallest_store);
		//cout << "Decreasing run:" << *lower_b <<"\t"<< largest_store <<endl;
		//cout << "initial: " ; debugSet(contents[path[i]]);
		if(lower_b != contents[path[i]].end() && contents[path[i]].size() !=0)	
		contents[path[i]].erase(lower_b, contents[path[i]].end());
		//cout << "final: " ; debugSet(contents[path[i]]);
		if(contents[path[i]].size() > 0) {
           	  	smallest_store = min(*(contents[path[i]].rbegin()), smallest_store);
        	} 
	}
	bool no_answer = false, ambiguous = false;
	for(auto i: path){
		//cout << "checking "<< i <<"\t" << contents[i].size() << endl;
		if(contents[i].size() == 0)
			no_answer = true;	
		else if(contents[i].size() > 1) ambiguous = true;
	}
	if(no_answer) cout << "impossible" <<endl;
	else if(ambiguous) cout << "ambiguous" << endl;
	else cout << "unique" << endl;
}

int main(int argc, char **argv){
	int super_markets,items;
	cin >> super_markets >> items;
	unordered_map<string, set<int> >  store_contents;
	for(int i = 0; i < items; i++){
		int store_id; string item;
		cin >> store_id >> item;
		store_contents[item].insert(store_id);
	}
	vector<string> sisters_path;
	int n;
	cin >> n;
	for(int i = 0 ; i < n; i++){
		string item;
		cin >> item;
		sisters_path.push_back(item);
	}
	solve(store_contents, sisters_path);

}
