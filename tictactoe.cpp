#include <vector>
#include <iostream>
using namespace std;

//bool wincheck() {
//	return true;
//}

void print_board(int){
	string board[3][3] = {
	{--, --, --}, 
	{--, --, --}, 
	{--, --, --}}; 
	cout << "A \t";
	for(auto i : board[0]){
		cout << i << "\t";
	}
	cout << endl << "B \t";
	for(auto i : board[1]){
		cout << i << "\t";
	}
	cout << endl << "C \t";
	for(auto i : board[2]){
		cout << i << "\t";
	}
	cout << endl;

}


int main() {
	string copyboard[3][3]{
	{--, --, --},
	{--, --, --},
	{--, --, --}};	
	printf("Hello! Welcome to the Tic-Tac-Toe Game! \n");
	print_board(1);
	string choicerow;
	int choicecollumn;
	printf("For Move #%d what row would you like to go?(Capital Letters) \n", counter);
	cin >> choicerow;
	printf("For Move #%d what collumn would you like to go? \n", counter);
	cin >> choicecollumn;
	if(choicerow == "A"){
		print_board(1);
		}
	return 0;
}
