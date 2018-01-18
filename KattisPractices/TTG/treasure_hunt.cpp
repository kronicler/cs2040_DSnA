#include <iostream>

using namespace std;
int traverse(int,int,char[200][200]);
bool check(int,int,int,int);

int main(){
    int i,j,col,row,counter=0,x=0,y=0;
    char dir,matrix[200][200];
    cin >> row >> col;

    for (i=0;i<row;i++){
        for (j=0;j<col;j++){
            cin >> matrix[i][j];
        }
    }

    counter = traverse(row,col,matrix);
    if (counter == -99){
        cout << "Out";
    }
    else if (counter == -100){
        cout << "Lost";
    }
    else{
        cout << counter;
    }
    return 0;
}
int traverse(int row,int col,char matrix[200][200]){
    int r = 0,c = 0,counter = 0;
    int arr[200][200] = {{0}};
    char dir = matrix[r][c];

    while (true){
        if (dir == 'T') {
            return counter;
        }
        else if (dir == 'N'){
            r -= 1;
        }
        else if (dir == 'S'){
            r += 1;
        }
        else if (dir == 'W'){
            c -= 1;
        }
        else if (dir == 'E'){
            c += 1;
        }
        counter += 1;

        if (!(c >= 0 && c < col && r >= 0 && r < row)){
            return -99;
        }
        if (arr[r][c] == 1){
            return -100;
        }
        arr[r][c] = 1;
        dir = matrix[r][c];
    }
}
