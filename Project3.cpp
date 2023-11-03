//File: Project3.cpp
//Name: Hamzah Imran
//Date: 04/14/21
//Course: CompSci 1
//Description: This program will play the game of Tic-Tac-Toe where the user plays against the computer opponent.
//             The program will also explain the rules of the game to the user.
//Usage: This program will ask the user to enter a valid input when playing the game.
//Sources: Multi-dimensional arrays (https://www.tutorialspoint.com/cplusplus/cpp_multi_dimensional_arrays.htm)
//         Checking for the same element in an array (https://www.tutorialspoint.com/cplusplus/cpp_multi_dimensional_arrays.htm)

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

//Function that executes the game and its components.
int Game(int x)
{
	int playerTurn = 0, computerTurn = 0, playerInput = 0, playerCounter = 0, tieCounter = 1;
	int playerRow = 0, playerColumn = 0, computerRow = 0, computerColumn = 0;
	const int ROWS = 3, COLS = 3;
	char table[ROWS][COLS] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} }; //Array that stores values for the game.
	srand(time(0));
	bool result = false, tie = false;
	playerTurn = x;

	//Loop that continues the game until someone wins or the game results in a tie.
	while (result == false && tie == false) {
		if (playerTurn == 0) { 
			cout << "The computer is deciding a move...\n";
			Sleep(1000);
			//Loop determines whether the randomly chosen number is a valid input or not.
			while (table[computerRow][computerColumn] == 'X' || table[computerRow][computerColumn] == 'O') {
				computerTurn = rand() % 9 + 1; //If-else converts the entered number to the corresponding element in the array.
				if (computerTurn % 3 == 0) {
					computerRow = (computerTurn / 3) - 1;
					computerColumn = 2;
				}
				else {
					computerRow = computerTurn / 3;
					computerColumn = (computerTurn % 3) - 1;
				}
			}
			table[computerRow][computerColumn] = 'O';
			//Outputs the game board and all available/unavailable spaces.
			cout << "       |       |" << endl;
			cout << "   " << table[0][0] << "   |   " << table[0][1] << "   |   " << table[0][2] << endl;
			cout << "       |       |" << endl;
			cout << "-------|-------|-------" << endl;
			cout << "       |       |" << endl;
			cout << "   " << table[1][0] << "   |   " << table[1][1] << "   |   " << table[1][2] << endl;
			cout << "       |       |" << endl;
			cout << "-------|-------|-------" << endl;
			cout << "       |       |" << endl;
			cout << "   " << table[2][0] << "   |   " << table[2][1] << "   |   " << table[2][2] << endl;
			cout << "       |       |" << endl << endl;

			playerTurn += 1; //Simple counter to switch turns.
		}

		else {
			cout << "It is your turn, please input a number corresponding to an empty square on the table: ";
			cin >> playerInput;
			while (playerInput < 1 || playerInput > 9) {
				cout << "Please input a valid number: ";
				cin >> playerInput;
			}
			//Loop only allows numbers that correspond to empty board spaces as input.
			do {
				if (playerCounter > 0) {
					while (playerInput < 1 || playerInput > 9) {
						cout << "Please input a valid number: ";
						cin >> playerInput;
					}
				}
				if (playerInput % 3 == 0) {
					playerRow = (playerInput / 3) - 1;
					playerColumn = 2;
				}
				else {
					playerRow = playerInput / 3;
					playerColumn = (playerInput % 3) - 1;
				}
				playerCounter += 1; 
				playerInput *= 0;
			} while (table[playerRow][playerColumn] == 'X' || table[playerRow][playerColumn] == 'O');
			
			playerCounter *= 0;
			table[playerRow][playerColumn] = 'X';
			//Outputs the game board and all available/unavailable spaces.
			cout << "       |       |" << endl;
			cout << "   " << table[0][0] << "   |   " << table[0][1] << "   |   " << table[0][2] << endl;
			cout << "       |       |" << endl;
			cout << "-------|-------|-------" << endl;
			cout << "       |       |" << endl;
			cout << "   " << table[1][0] << "   |   " << table[1][1] << "   |   " << table[1][2] << endl;
			cout << "       |       |" << endl;
			cout << "-------|-------|-------" << endl;
			cout << "       |       |" << endl;
			cout << "   " << table[2][0] << "   |   " << table[2][1] << "   |   " << table[2][2] << endl;
			cout << "       |       |" << endl << endl;

			playerTurn -= 1; //Simple counter to switch turns.
		}
		//Checks for any possible winning turns by either player.
		for (int i = 0; i < 3; ++i) {
			if (table[i][0] == table[i][1] && table[i][1] == table[i][2]) {
				result = true;
				if (playerTurn == 1) {
					cout << "The computer won!";
				}
				else {
					cout << "Congratulations, you won!";
				}
			}
			if (table[0][i] == table[1][i] && table[1][i] == table[2][i]) {
				result = true;
				if (playerTurn == 1) {
					cout << "The computer won!";
				}
				else {
					cout << "Congratulations, you won!";
				}
			}
		}
		if (table[0][0] == table[1][1] && table[1][1] == table[2][2]) {
			result = true;
			if (playerTurn == 1) {
				cout << "The computer won!";
			}
			else {
				cout << "Congratulations, you won!";
			}
		}
		if (table[0][2] == table[1][1] && table[1][1] == table[2][0]) {
			result = true;
			if (playerTurn == 1) {
				cout << "The computer won!";
			}
			else {
				cout << "Congratulations, you won!";
			}
		}
		tieCounter += 1; //Counts number of turns that have passed to determine if the game should result in a tie.
		if (tieCounter == 10 && result == false) {
			tie = true;
			cout << "The result of the game is a draw.";
		}
	}

	return x;
} 

int main()
{
	int turnOrder = 0, gameBoard = 0, playerChoice = 0;
	srand(time(0));
	turnOrder = rand() % 2 + 1; //Randomly decides player order.

	//Displays rules of the game.
	cout << "********** TIC-TAC-TOE **********\n\n";
	cout << "Rules:\n";
	cout << "1. To win the game, players attempt to get three of their marks to line up in a stright line.\n";
	cout << "2. One player uses \"X\" and the other player uses \"O\".\n";
	cout << "3. Players take turns placing their mark in an empty, unoccupied square until someone wins.\n";
	cout << "4. If the game reaches a state where there are no more playable moves and a winner has not\n";
	cout << "   yet been decided, the result is a draw.\n\n";
	cout << "       |       |" << endl;
	cout << "   1   |   2   |   3" << endl;
	cout << "       |       |" << endl;
	cout << "-------|-------|-------" << endl;
	cout << "       |       |" << endl;
	cout << "   4   |   5   |   6" << endl;
	cout << "       |       |" << endl;
	cout << "-------|-------|-------" << endl;
	cout << "       |       |" << endl;
	cout << "   7   |   8   |   9" << endl;
	cout << "       |       |" << endl << endl;

	cout << "Now a coin flip to determine who plays first..." << endl;
	Sleep(1000);
	//If-else announces turn order and proceeds the program to the "Game" function.
	if (turnOrder == 1) {
		cout << "The computer plays first, it will use \"O\"." << endl << endl;
		gameBoard = Game(playerChoice);
	}
	else {
		cout << "You play first, you will use \"X\"." << endl << endl;
		playerChoice = 1;
		gameBoard = Game(playerChoice);
	}
	cout << "\n\n******* THANKS FOR PLAYING *******";

	return 0;
}