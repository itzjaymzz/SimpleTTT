//James Cole & Isaac Sipma
//October 27, 2025
//Simple Tic Tac Toe Game
#include <vector>
#include <iostream>
using namespace std;


//Returns true or false based on win or not win
//bool wincheck() {
//	return true;
//}

//Prints the board thats all it does rn
void print_board(vector<string> pos){  
	printf("\t1 \t2 \t3 \n"
	"A\t %s \t%s \t%s\n", (string)pos[0], (string)pos[1], (string)pos[2], 
	(string)pos[3], (string)pos[4], (string)pos[5], 
	(string)pos[6], (string)pos[7], (string)pos[8], );
}

//Makes a copy of the board for movs that are made
int main() {
	vector<string> board{
		"--", "--", "--", "--", "--", "--", "--",
	};
	printf("Hello! Welcome to the Tic-Tac-Toe Game! \n");
	print_board(board);
	string userchoice;
	printf("For this move where would you like to go? \n");
	cin >> userchoice;


	return 0;
}
