#include <iostream>
#include <string>
#include <queue>
using namespace std;
char relation_map[26][26];
char size;


void extract_relation(string a, string b){
	int i, length = (a.size() < b.size())? a.size() : b.size();
	for(i = 0 ;i < length && a[i] == b[i]; i++ ) ;
	if(i != length){
		//cout << a[i] << " < "<<b[i]<<endl;
		//cout << a[i] - 'a' << ","<< b[i] - 'b' <<endl; 
		relation_map[a[i] - 'a'][b[i]-'a'] = 1;
	}
}
void debugAdjMat() {
	for(char i = 0; i < size; i++){
		for(char j = 0 ; j < size; j++)
			cout << (int)relation_map[i][j];
		cout << endl;
	}
}
void resolve_conflict(){
	//Topological sort 
	string result="";
	queue<char> unexplored;
	//Identify all nodes which have no incoming edges
	//(Maximal Nodes)
	for(char i = 0; i < size; i++){
		int count = 0;
		for(char j =0; j < size; j++){
			if(relation_map[j][i] != 0) count++; 
		}
		if(count == 0) unexplored.push(i);
	}
	//cout << "got starting point: " << (char)(unexplored.front()+'a') << endl;
	while(!unexplored.empty()){
		char n = unexplored.front();
		unexplored.pop();
		result += (n+'a');
		for(int i = 0 ; i < size; i++){
			if(relation_map[n][i] == 1){ 
				relation_map[n][i] = 0;
				int count = 0;
				for(int j = 0; j < size; j++)
					if(relation_map[j][i] != 0) count++;
				if(!count) unexplored.push(i);
			}
		}
		if(unexplored.size() > 1){
			cout << "AMBIGUOUS"<<endl;
			return;
		}	
	}
	int excess_edge = 0 ;
	for(int i = 0 ; i < size; i++)
		for(int  j = 0; j < size; j++)
			excess_edge+=relation_map[i][j];
	if(excess_edge != 0){
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	cout << result <<endl;
}
int main(int argc, char** argv){
	for(int i = 0; i < 26; i++)
		for(int j = 0; j < 26; j++)
			relation_map[i][j] = 0;
	int test_cases;
	cin >> size >> test_cases;
	size -= 'a';
	size++;
	string prev, curr;
	cin >> prev;
	for(int i = 1; i < test_cases; i++){
		cin >> curr;
		extract_relation(prev,curr);
		prev = curr;
	}
	//	debugAdjMat();
	resolve_conflict();
	//debugAdjMat(); 	 
}
