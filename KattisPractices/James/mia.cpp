#include <iostream>
using namespace std;

int roll(int, int);

int main () {
	int s1, s2, r1, r2;
	int player1, player2;

	while(1) {
		cin >> s1 >> s2 >> r1 >> r2;		
		if (!s1 && !s1 && !r1 && !r2) break;
		player1 = roll(s1,s2);
		player2 = roll(r1,r2);
			if (player1==player2)	cout << "Tie.\n";	
		else	if (player1>player2) 	cout << "Player 1 wins.\n";
		else 				cout << "Player 2 wins.\n";
	}

	return 0;
}

int roll(int dice1, int dice2) {
	if (dice1+dice2 == 3)
		return 1000;
	if (dice1 == dice2)
		return dice1*100;
	if (dice1 > dice2) {
		return 10*dice1+dice2;
	} else {
		return 10*dice2+dice1;
	}
}
