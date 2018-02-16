#include <queue>
#include <utility>
#include <iostream>
#include <set>
#include <list>
using namespace std;
char map[1000][1000];
int explored[1000][1000];
int r,c;
int iter;
void flood(int r1,int c1, int color){
	queue<pair<int, int> > unexplored;
	bool found = false;	
	unexplored.push(pair<int,int>(r1,c1));
	char val = map[r1][c1];
	while(!unexplored.empty()){
		auto current = unexplored.front();
		unexplored.pop();
		int y = current.first; int x = current.second;
		if(x < 0 || y < 0 || x >= c || y >= r) 
			continue;
		if(map[y][x] != val || explored[y][x] != -1)
			continue;
		explored[y][x] = color;//Explored
		unexplored.push(pair<int,int>(y-1,x));
		unexplored.push(pair<int,int>(y+1,x));
		unexplored.push(pair<int,int>(y,x+1));
		unexplored.push(pair<int,int>(y,x-1));	
	}
}
int main(int argc, char** argv){
	cin >> r >> c;
	for(int i = 0; i < r; i++){
		cin >> map[i];
	}
	int test_cases;
	cin >> test_cases;
	for(int i = 0; i <1000; i++)
		for(int j=0; j<1000;j++) explored[i][j]=-1;
	//Flood fill
	int color =1;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(explored[i][j]==-1){
				flood(i,j,color++);
			}
		}
	}
	//Test case handling
	for(int i = 0 ; i < test_cases; i++){
		int r1,c1,r2,c2;
		cin >> r1 >> c1 >>r2 >>c2;
		if(explored[r1-1][c1-1] != explored[r2-1][c2-1]){
			cout << "neither" <<endl;
			continue;
		}
		if(map[r1-1][c1-1] == '0') cout << "binary" <<endl;
		else cout << "decimal" <<endl;
	}
}
