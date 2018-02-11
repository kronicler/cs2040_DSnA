#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
class Square {
	public:
		int x, y, moves;
		Square(int x1, int y1, int m): x(x1), y(y1), moves(m){}; 
};

int gridx, gridy;

int get_dist(Square a, Square b){
	int dx = abs(a.x-b.x), dy = abs(a.y-b.y);
	if(dx > dy){
		//swap
		int c = dx;
		dx = dy;
		dy = c;
	}
	if(dx <= dy>>1){
		if(dy&1) return -1;
		if((dx+dy/2)&1) return -1; 
		return dy >> 1; 
	}
	else{
		if(((dy+dx)%3)==0){ return (dy+dx)/3;}
		return -1;
	}
}

void search(int x, int y, int moves, vector<Square> &sq){
	if( x < 0 || y < 0 || x >= gridx || y >= gridy ) return;
	sq.push_back(Square(x,y,moves));
	if(moves > 1) return;
	search(x+2,y+1,++moves,sq);
	search(x+2,y-1,moves,sq);
	search(x-2,y+1,moves,sq);
	search(x-2,y-1,moves,sq);
	search(x+1,y+2,moves,sq);
	search(x+1,y-2,moves,sq);
	search(x-1,y+2,moves,sq);
	search(x-1,y-2,moves,sq);
}

int main(int argc, char** argv){   
	int startx, starty;
	int endx, endy;
	cin >> gridx >> gridy >> startx >> starty >> endx >> endy;
	vector<Square> capital, origin;
	search(endx,endy,0,capital);
	search(startx,starty,0,origin);
	int mindistance = 1e9;
	for(int i = 0 ; i < capital.size(); i++){
		for(int  j = 0; j < origin.size(); j++) {
			Square& a = capital[i], b = origin[j];
			int dist = get_dist(a,b);           
			if(dist < 0) continue;
			dist += a.moves + b.moves;
			mindistance = dist < mindistance ? dist : mindistance; 
		}
	}
	cout << mindistance << endl;  
}
