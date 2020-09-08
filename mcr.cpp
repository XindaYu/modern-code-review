#include<iostream>
using namespace std;
int isWin(char game[3][3]){
	int win = 0;
	for (int line = 0; line < 3; line++)
	{
		if (game[line][0] == game[line][1] && game[line][1] == game[line][2] && (game[line][0] == 'X')) win = 1;
		if (game[0][line] == game[1][line] && game[1][line] == game[2][line] && (game[0][line] == 'X')) win = 1;
		if (game[line][0] == game[line][1] && game[line][1] == game[line][2] && (game[line][0] == 'O')) win = 2;
		if (game[0][line] == game[1][line] && game[1][line] == game[2][line] && (game[0][line] == 'O')) win = 2;

	}
	if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && (game[0][0] == 'X')) win = 1;
	if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && (game[0][2] == 'X')) win = 1;
	if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && (game[0][0] == 'O')) win = 2;
	if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && (game[0][2] == 'O')) win = 2;
   return win;
}
int main(){
	int i, j;
	int flag = 1;
	char game[3][3] = {' '}; // Tic-tac-toe
	char player1 = 'X';
	char player2 = 'O';
	bool turn = true; // false for player 1F's turn, true for player 2's turn. Player 1 first.
	while (flag)
	{
		char game[3][3] = { ' ' };
		cout << "X = Player 1" << endl << "O = Player 2" << endl << "input 3 for Tie" <<endl;
		for (int n=0; n<9; n++){
		turn = !turn; // use the not-operator to change true to false or false to true.
		if (turn == false)
			cout << "Player 1: ";
		else
			cout << "Player 2: ";
		cout << "Which cell to mark? i:[0..2], j:[0..2]: \n";
		cin >> i >> j;
		if (i >= 0 && i <= 2 && j >= 0 && j <= 2) {
				if (game[i][j] == player1 || game[i][j] == player2 ){
					cout << "It is not empty.And we will start a new game" << endl;
					turn = true;
					break;
				}
				else {if (turn == false)
						game[i][j] = player1;
					else
						game[i][j] = player2;
					cout << game[0][0] << " " << game[0][1] << " " << game[0][2] << endl;
					cout << game[1][0] << " " << game[1][1] << " " << game[1][2] << endl;
					cout << game[2][0] << " " << game[2][1] << " " << game[2][2] << endl;
					//-------------------change here
					if (isWin(game) == 1) {
						cout << "player 1 Win!" << endl;
						break; // need to terminate the problem
					}
					else if (isWin(game) == 2) {
						cout << "player 2 Win!" << endl;
						break; // need to terminate the problem
					}
				}
			}
		else{
			if (i == 3) // all celles with i=0 to 2 have been inputted above but no winner yet
			{
				cout << "Tie!" << endl;
			}
			else{
				cout << "You select the wrong value,so we will start a new game." << endl;
			}
				turn = true;
				break;
		}
		}
	// show the game to console
		cout << game[0][0] << " " << game[0][1] << " " << game[0][2] << endl;
		cout << game[1][0] << " " << game[1][1] << " " << game[1][2] << endl;
		cout << game[2][0] << " " << game[2][1] << " " << game[2][2] << endl;
		cout << "if you want to exit,plz input 0 or we will continue" << endl;
		cin >> flag;
	}
	if (flag == 0)
	{
		cout << "happy game!";
		exit(0);
	}
	return 0;
}
