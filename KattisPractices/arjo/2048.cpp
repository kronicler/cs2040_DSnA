#include <iostream>
using namespace std;
int board[4][4];
void merge_left_row(int* row){
	int sp = 0;
	int scratch[] = {0,0,0,0};
	for(int i = 0; i < 4; i++){
		if(row[i] == 0) continue;
		if(row[i] == scratch[sp]) {
			scratch[sp]*=2;
			sp++;
		}
		else{
			if(scratch[sp] == 0){
				scratch[sp] = row[i];
			}
			else {
				sp++;
				scratch[sp] = row[i];   
			}
		}
	}
	for(int i = 0 ; i < 4; i++) row[i] =scratch[i];
}
void merge_left(){
	for(int i = 0 ; i < 4; i++) merge_left_row(board[i]);
}

void merge_right(){
	for(int i = 0 ; i < 4; i++) {
		int row[4];
		for(int j = 0; j < 4; j++){
			row[j] = board[i][3-j];
		}
		merge_left_row(row);
		for(int j = 0; j < 4; j++){
			board[i][3-j] = row[j];
		}
	}
}

void merge_up(){
	for(int i = 0 ; i < 4; i++) {
		int row[4];
		for(int j = 0; j < 4; j++){
			row[j] = board[j][i];
		}
		merge_left_row(row);
		for(int j = 0; j < 4; j++){
			board[j][i] = row[j];
		}
	}
}

void merge_down(){
	for(int i = 0 ; i < 4; i++) {
		int row[4];
		for(int j = 0; j < 4; j++){
			row[j] = board[3-j][i];
		}
		merge_left_row(row);
		for(int j = 0; j < 4; j++){
			board[3-j][i] = row[j];
		}
	}
}


int main(int argc, char**argv){
	int move;
	for(int i = 0 ; i <  4; i++ ){
		cin >> board[i][0] >> board[i][1] >> board[i][2] >> board[i][3];
	}
	cin >> move;
	switch(move){
		case 0: merge_left();break;
		case 1: merge_up();break;
		case 2: merge_right();break;
		case 3: merge_down();break;
	}
	for(int i = 0 ; i < 4; i++ ) {
		cout << board[i][0] << " " << board[i][1] << " " << board[i][2] << " " << board[i][3] << endl;
	} 
	return 0;
}
