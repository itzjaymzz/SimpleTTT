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
	printf("\t1  \t2  \t3  \n\n"
	"A\t %s \t%s \t%s\n", 
	"B\t %s \t%s \t%s\n", 
	"C\t %s \t%s \t%s\n", 
	pos[0].c_str(), pos[1].c_str(), pos[2].c_str(),  
	pos[3].c_str(), pos[3].c_str(), pos[5].c_str(),  
	pos[6].c_str(), pos[7].c_str(), pos[8].c_str());
}

//Makes a copy of the board for movs that are made
int main() {
	vector<string> board{
		"--", "--", "--", 
		"--", "--", "--", 
		"--", "--", "--"
	};
	printf("Hello! Welcome to the Tic-Tac-Toe Game! \n");
	print_board(board);
	string userchoice;
	printf("For this move where would you like to go? \n");
	cin >> userchoice;


	return 0;
}
