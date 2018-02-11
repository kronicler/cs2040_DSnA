#include <iostream>
#include <queue>
#include <utility>
char grid[500][500];
int _distance[500][500];
int r,c;
class cell {
public:
 int x,y,dist;
 cell(int _x, int _y, int _d): x(_x), y(_y), dist(_d) {}
};
using namespace std;
void search(){
	queue<cell> frontier;
	frontier.push(cell(0,0,0));
	while(frontier.size()){
		cell curr_cell = frontier.front();
		frontier.pop();
		int x = curr_cell.x, y = curr_cell.y, dist = curr_cell.dist;
		if(x >= r || y >= c || x < 0 || y < 0){
			//cout << "Exiting due to OUB" << x <<", " << y <<endl;
			continue;
		}
		if(_distance[x][y] != -1){
			//cout << "Exiting due to already Explored" << x <<", " << y <<endl;
			continue;
		}
		int tmp = grid[x][y] - '0';
		_distance[x][y] = dist;
		dist++;
		frontier.push(cell(x+tmp, y, dist));
		frontier.push(cell(x-tmp, y, dist));
		frontier.push(cell(x, y+tmp,dist));
		frontier.push(cell(x, y-tmp,dist));
	} 
}
int main(int argc, char** argv){
	cin >> r >>c;
	for(int i  = 0; i < r; i++){
		cin >> grid[i];
		for(int j = 0 ; j < c; j++) _distance[i][j] = -1;
	}
	search();
	cout << _distance[r-1][c-1] <<endl;
}
