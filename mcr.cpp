#include<iostream>
using namespace std;
int isWin(char game[3][3]){
	int win = 0;
	if (game[0][0] == game[0][1] && game[0][1] == game[0][2] && (game[0][0] == 'X' )) win = 1; 
	if (game[1][0] == game[1][1] && game[1][1] == game[1][2] && (game[1][0] == 'X' )) win = 1; 
	if (game[2][0] == game[2][1] && game[2][1] == game[2][2] && (game[2][0] == 'X' )) win = 1; // column
	if (game[0][0] == game[1][0] && game[1][0] == game[2][0] && (game[0][0] == 'X' )) win = 1; 
	if (game[0][1] == game[1][1] && game[1][1] == game[2][1] && (game[0][1] == 'X' )) win = 1; 
	if (game[0][2] == game[1][2] && game[1][2] == game[2][2] && (game[0][2] == 'X' )) win = 1; // diagonal
	if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && (game[0][0] == 'X' )) win = 1; 
	if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && (game[0][2] == 'X' )) win = 1; 
	if (game[0][0] == game[0][1] && game[0][1] == game[0][2] && ( game[0][0] == 'O')) win = 2; 
	if (game[1][0] == game[1][1] && game[1][1] == game[1][2] && ( game[1][0] == 'O')) win = 2; 
	if (game[2][0] == game[2][1] && game[2][1] == game[2][2] && ( game[2][0] == 'O')) win = 2; // column
	if (game[0][0] == game[1][0] && game[1][0] == game[2][0] && ( game[0][0] == 'O')) win = 2; 
	if (game[0][1] == game[1][1] && game[1][1] == game[2][1] && ( game[0][1] == 'O')) win = 2; 
	if (game[0][2] == game[1][2] && game[1][2] == game[2][2] && ( game[0][2] == 'O')) win = 2; // diagonal
	if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && ( game[0][0] == 'O')) win = 2; 
	if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && ( game[0][2] == 'O')) win = 2; 
   return win;
}
int main(){
	int i, j;
	char game[3][3] = {' '}; // Tic-tac-toe
//	char player1 = 'X';
//	char player2 = 'O';
	bool turn = true; // false for player 1F's turn, true for player 2's turn. Player 1 first.
//	cout << "X = Player 1" << endl << "O = Player 2" << endl;
	for (int n=0; n<9; n++){
		turn = !turn; // use the not-operator to change true to false or false to true.
		if (turn == false)
			cout << "X: ";
		else
			cout << "O: ";
		cout << "Which cell to mark? i:[0..2], j:[0..2]: \n";
		cin >> i >> j;
		if (turn == false)
			game[i][j] = 'X';
		else
			game[i][j] = 'O';
		//-------------------change here
		if (isWin(game)==1){
				cout << "X Win!" << endl;
			break; // need to terminate the problem
		} else if(isWin(game)==2){
			cout << "O Win!" << endl;
			break; // need to terminate the problem
		}
		//------------------------------
	}
	if (i==3) // all celles with i=0 to 2 have been inputted above but no winner yet
		cout << "Tie!" << endl;
	// show the game to console
	cout << game[0][0] << " " << game[0][1] << " " << game[0][2] << endl;
	cout << game[1][0] << " " << game[1][1] << " " << game[1][2] << endl;
	cout << game[2][0] << " " << game[2][1] << " " << game[2][2] << endl;
	return 0; 
}
