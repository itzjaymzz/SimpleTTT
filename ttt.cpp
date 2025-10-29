//James Cole & Isaac Sipma
//October 27, 2025
//Simple Tic Tac Toe Game
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;


string wincheck(const vector<string> board) {
    // 1. Check Rows
    for (int i = 0; i < 9; i += 3) {
        if (board[i] != "--" && board[i] == board[i+1] && board[i] == board[i+2]){
        	 return board[i];
        } 
    }
    // 2. Check Columns
    for (int i = 0; i < 3; ++i) {
        if (board[i] != "--" && board[i] == board[i+3] && board[i] == board[i+6]){ 
        	return board[i];
        }	
    }
    // 3. Check Diagonals
    if (board[0] != "--" && board[0] == board[4] && board[0] == board[8]) {
    	return board[0];
    }	
    if (board[2] != "--" && board[2] == board[4] && board[2] == board[6]) {
    	return board[2];
    }
    return "A";
}

int translate_move(string choice) {
	try {
		if (choice.length() != 2){
			throw runtime_error("Erm I don't think thats a valid move try again");
		}
		if (choice[0] != 'A' && choice[0] != 'B' && choice[0] != 'C'){
			throw runtime_error("Erm I don't think thats a valid move try again");
		}
		if (choice[1] < '1' || choice [1] > '3'){
			throw runtime_error("Erm I don't think thats a valid move try again");				
		}	 
	}
	catch(const runtime_error error){
		return -1;
	}
	char row = toupper(choice[0]);
	int collumn = choice[1] - '0';
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


//Makes a copy of the board for movs that are made
int main() {
	vector<string> board{
		"--", "--", "--", 
		"--", "--", "--", 
		"--", "--", "--"
	};
	cout << "========================"
	"===============================================" << endl;
	cout << "####### #######  ###### "
	"####### #######  ###### ####### ####### #######" << endl;
	cout << "   #       #    #       "
	"   #    #     # #          #    #     # #      " << endl;
	cout << "   #       #    #       "
	"   #    ####### #          #    #     # #######" << endl;
	cout << "   #       #    #       "
	"   #    #     # #          #    #     # #      " << endl;
	cout << "   #    #######  ###### "
	"   #    #     #  ######    #    ####### #######" << endl;
	cout << "========================"
	"===============================================" << endl;
	print_board(board);
	int counter = 1;
	string userchoice;
	int index = -1;
	while(wincheck(board) == "A"){
		printf("For player - where would you like to go? ");
		cin >> userchoice;
		if (translate_move(userchoice) != -1){
			int index = translate_move(userchoice);
		}
		if(board[index] != "--"){
			printf("Erm I don't think thats a valid move try again\n");
		} else {
			board[index] = "*";
			counter++;
		print_board(board);
		}	
	}
	cout << wincheck(board)<< endl;
	if(wincheck(board) == "X"){
		printf("O lost!\n");
	}
	if(wincheck(board) == "O"){
		printf("X lost!\n");
	}

	return 0;
}
