#include <vector>
#include <iostream>
using namespace std;

//bool wincheck() {
//	return true;
//}

void print_board(int){
	vector<string> boardrowA ={"-", "-", "-"};
	vector<string> boardrowB ={"-", "-", "-"};
	vector<string> boardrowC ={"-", "-", "-"};
	cout << "A \t";
	for(auto i : boardrowA){
		cout << i << "\t";
	}
	cout << endl << "B \t";
	for(auto i : boardrowB){
		cout << i << "\t";
	}
	cout << endl << "C \t";
	for(auto i : boardrowC){
		cout << i << "\t";
	}
	cout << endl;

}


int main() {
	vector<string> copyboardrowA ={"-", "-", "-"};
	vector<string> copyboardrowB ={"-", "-", "-"};
	vector<string> copyboardrowC ={"-", "-", "-"};
	printf("Hello! Welcome to the Tic-Tac-Toe Game! \n");
	figlet("Hello");
	print_board(1);
	int counter = 1;
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
