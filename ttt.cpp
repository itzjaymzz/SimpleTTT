//James Cole & Isaac Sipma
//October 27, 2025
//Simple Tic Tac Toe Game
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;


//Returns true or false based on win or not win
//bool wincheck() {
//	return true;
//}

//Prints the board thats all it does rn
void print_board(vector<string> pos){  
	printf("\t1\t2\t3  \n\n"
	"A\t%s \t%s \t%s\n\n" 
	"B\t%s \t%s \t%s\n\n" 
	"C\t%s \t%s \t%s\n\n", 
	pos[0].c_str(), pos[1].c_str(), pos[2].c_str(),  
	pos[3].c_str(), pos[4].c_str(), pos[5].c_str(),  
	pos[6].c_str(), pos[7].c_str(), pos[8].c_str());
}

int translate_move(string choice) {
	if (choice.length() != 2){
		throw runtime_error("Erm I don't think thats a valid move try again");
	}
	if (choice[0] != 'A' && choice[0] != 'B' && choice[0] != 'C'){
		throw runtime_error("Erm I don't think thats a valid move try again");
	}
	if (choice[1] < 1 || choice [1] > 3){
		throw runtime_error("Erm I don't think thats a valid move try again");		
		
	}	 
	char row = toupper(choice[0]);
	int collumn = choice[1] - 0;
	int index = -1;
	if(row == 'A'){
		index = 0;
	}
	else if(row == 'B'){
		index = 3;
	}
	else if(row == 'C'){
		index = 6;
	}
	return index + (collumn -1);
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
	int index = translate_move(userchoice);
	if(board[index] != "--"){
		throw runtime_error("Erm idk if thats a valid move lil bro");
	} else {
		board[index] = "*";
		print_board(board);
	}	
	

	return 0;
}
