#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

int main(int argc, char** argv) {
	int day = 0;
	vector<string> text_per_day[7];
	while(!cin.eof()){
		string heading;
		cin >> heading;
		if(heading == "<text>"){
			text_per_day[day].clear();			
			string word;
			cin >> word;
			while(word != "</text>"){
				if(word.size() >= 4) text_per_day[day].push_back(word);
				cin >> word;
			}
			//cout << "procesing day" <<day <<endl;
			day = (day+1)%7;
		}
		else if(heading == "<top"){
			map<string, int> dict;
			map<int, set<string> > order;
			int N;
			cin >> N;
			string _;
			cin >> _;
			for(int i = 0; i < 7; i++){
				for( auto word : text_per_day[i]){
					//cout << "inserting" << word <<endl;
					auto it = dict.find(word);
					if(it!=dict.end()) it->second++;
					else dict[word] = 1;
				}
			}
			for(auto it : dict){
				//cout << "-: "<< it.second <<" "  <<it.first;
				order[it.second].insert(it.first);
			}
			cout << "<top "<<N<<">"<<endl;
			int cnt = 0;
			for(auto it = order.rbegin();  cnt < N && it != order.rend(); it++) {
				for(auto s : it->second){
					cout << s << " " << it->first <<endl;
					cnt++;
				}
			}
			cout << "</top>" <<endl;
		}
	}
}
