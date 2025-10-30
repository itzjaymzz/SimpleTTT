//James Cole & Isaac Sipma
//October 27, 2025
//Simple Tic Tac Toe Game
#include <vector>
#include <iostream>
#include <stdexcept>
#include <time.h> 
#include <cstdlib>
using namespace std;

//Wincheck function gets passed the game board and determines win based
//on vertical, diagonal, and horizontal, returns A if no winner yet and X/O
//based on the winner
string wincheck(const vector<string> board) {
    //Checks Rows
    for (int i = 0; i < 9; i += 3) {
        if (board[i] != "--" && board[i] == board[i+1] && board[i] == board[i+2]){
        	 return board[i];
        } 
    }
    //Check Collumns
    for (int i = 0; i < 3; ++i) {
        if (board[i] != "--" && board[i] == board[i+3] && board[i] == board[i+6]){ 
        	return board[i];
        }	
    }
    //Check Diagonals
    if (board[0] != "--" && board[0] == board[4] && board[0] == board[8]) {
    	return board[0];
    }	
    if (board[2] != "--" && board[2] == board[4] && board[2] == board[6]) {
    	return board[2];
    }
    return "A";
}

//Translates the player move into numbers and then 
//said numbers into the matching index also handles most "bad" input
int translate_move(string choice) {
	//try block to get runtime errors wihout crashing game
	try {
		//Makes sure it follows A2 or C1 format of 2 characters
		if (choice.length() != 2){
			throw runtime_error("Erm I don't think thats a valid move try again");
		}
		//Makes sure its only A/a B/b or C/c		
		if (choice[0] != 'A' && choice[0] != 'B' && choice[0] != 'C'
		&& choice[0] != 'a' && choice[0] != 'b' && choice[0] != 'c'){
			throw runtime_error("Erm I don't think thats a valid move try again");
		}
		//Makes sure its on the board 1, 2 or 3
		if (choice[1] < '1' || choice [1] > '3'){
			throw runtime_error("Erm I don't think thats a valid move try again");				
		}	 
	}
	//catchs and prints the errors instead of booting you out of the game
	catch(const runtime_error error){ 
		return -1;
	}

	//splits player input into letter and number
	char row = toupper(choice[0]);
	int collumn = choice[1] - '0';
	int index = -1;
	//sets letter to index number
	if(row == 'A'| row == 'a'){
	index = 0;
	}
	else if(row == 'B'|row == 'b'){
		index = 3;
	}
	else if(row == 'C'|row == 'c'){
		index = 6;
	}
	//returns the index number for whatever move player just made
	return index + (collumn -1);
	
}

//Prints the board by just printing every 
//element in the vector + lines for looks
void print_board(vector<string> pos){  
	printf("\t1\t \t2\t \t3\t  \n\n"
	"A\t%s\t| \t%s\t| \t%s\n\n" 
	"  ---------------------------------------------\n"
	"B\t%s\t| \t%s\t| \t%s\n\n" 
	"  ---------------------------------------------\n"
	"C\t%s\t| \t%s\t| \t%s\n\n", 
	pos[0].c_str(), pos[1].c_str(), pos[2].c_str(),  
	pos[3].c_str(), pos[4].c_str(), pos[5].c_str(),  
	pos[6].c_str(), pos[7].c_str(), pos[8].c_str());
}

//main function where everything comes together
int main() {
	//1D vector containing just dashes for now
	vector<string> board{
		"--", "--", "--", 
		"--", "--", "--", 
		"--", "--", "--"
	};
	//some real nasty cout lines that just print TICTACTOE more pretty looking
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
	//initializing most variables
	int counter = 1;
	string userchoice;
	string player = "X";
	int gamechoice = -1;
	cout << "Hello! Would you like to play"
	"with a computer(1) or against a human(2): ";
	cin >> gamechoice;
	if(gamechoice == 2){	
		//While loop that stays active so long as no one won 
		//(A is the default return from wincheck)
		while(wincheck(board) == "A"){
			//call to brint board to print the empty board first
			print_board(board);
			printf("For player %s where would you like to go?(Eg; A1, or c2) ", player.c_str());
			cin >> userchoice;
			int index = translate_move(userchoice);
			//if statement that makes sure the index isnt -1 (default return for movetranslator)
			if (index == -1){
				printf("Erm I don't think thats a valid move try again\n");
				continue;
			//if statement that makessure that a space hasnt been taken already
			}
			if(board[index] != "--"){
				printf("Erm I don't think thats a valid move try again\n");
			//else handles most game input/output
			} else {
				//sets wherever the user pointed to to X or O
				board[index] = player;
				//running counter of moves for draw check
				counter++;			
				//prints updated board after move
				print_board(board);
				printf("\n\n");
				//weird looking if else statement that sets X to O and O to X
		    	player = (player == "X") ? "O" : "X";
				//Draw check that makes sure that the game doesnt last more that 
				//9 moves without the win status changing
				if (counter > 9 && wincheck(board) == "A") {
	            	printf("It's a draw!\n");
					return 0;
				}
			}	
		}
	}


	if(gamechoice == 1){	
		//While loop that stays active so long as no one won 
		//(A is the default return from wincheck)
		while(wincheck(board) == "A"){
			//call to brint board to print the empty board first
			print_board(board);
			printf("Where would you like to go?(Eg; A1, or c2) ");
			cin >> userchoice;
			int index = translate_move(userchoice);
			//if statement that makes sure the index isnt -1 (default return for movetranslator)
			if (index == -1 || board[index] != "--"){
				printf("Erm I don't think thats a valid move try again\n");
				continue;
			}
			//sets an X wherever the user pointed to 
			board[index] = "X";
			counter++;
			print_board(board);
			printf("\n\n");
			// Check for win/draw players move
			if (wincheck(board) != "A") break;
			if (counter >= 9) {
			printf("It's a draw!\n");
			break;
			}
			int comp_move = -1;
			while(board[comp_move] != "--"){
				comp_move = rand() % 9;
			}
			board[comp_move] = "O";
			counter++;
			// Check for win/draw players move
			if (wincheck(board) != "A") break;
			if (counter >= 9) {
			printf("It's a draw!\n");
			break;
			}			
		}	
	}
	//simple if statements that print the winner
	if(wincheck(board) == "X"){
		cout << "===========================================================" << endl;
		cout << "   #     #              #  #  # ####### #     # #######" << endl;
		cout << "    #   #               #  #  #    #    ##    # #      " << endl;
		cout << "     # #                #  #  #    #    # #   # ####### " << endl;
		cout << "    #   #               #  #  #    #    #  #  #       #" << endl;
		cout << "   #     #               ## ##  ####### #   ### #######" << endl;
		cout << "===========================================================" << endl;
	}
	if(wincheck(board) == "O"){
		cout << "===========================================================" << endl;
		cout << "    #####               #  #  # ####### #     # #######" << endl;
		cout << "   #     #              #  #  #    #    ##    # #      " << endl;
		cout << "   #     #              #  #  #    #    # #   # ####### " << endl;
		cout << "   #     #              #  #  #    #    #  #  #       #" << endl;
		cout << "    #####                ## ##  ####### #   ### #######" << endl;
		cout << "===========================================================" << endl;
	}
	if(wincheck(board) == "O"){
		printf("O Won!\n");
	}
	return 0;
}
