// XO.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void ResultCheck();
void Init();
void Gameplay();
char field[3][3];
void PrintField();
int WinCheck();
int turn = 0;
int main()
{
	Init();
	Gameplay();
	system("pause");
    return 0;
}

void Init(){
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			field[i][j] = ' ';
		}
	}
}

void Gameplay() {
	int curPlayer = 1;
	int row, column;
	cout << "First player - X, second player - O\n";
	cout << "Input rows and columns with space, like 1 2\n";
	while (WinCheck() == 4){
		cin >> row >> column;
		if (curPlayer == 1) field[row - 1][column - 1] = 'X';
		else				field[row - 1][column - 1] = 'O';
		curPlayer *= -1;
		turn++;
		PrintField();
	}
	switch (WinCheck()) {
		case 1: cout << "First player won";
		case 2: cout << "Second player won";
		case 3: cout << "Draw";
	}
}

void PrintField() {
	cout << field[0][0] << " | " << field[0][1] << " | " << field[0][2] << "\n";
	cout << field[1][0] << " | " << field[1][1] << " | " << field[1][2] << "\n";
	cout << field[2][0] << " | " << field[2][1] << " | " << field[2][2] << "\n";
}

int WinCheck() {
	if (('X' == field[0][0] == field[0][1] == field[0][2]) ||
		('X' == field[1][0] == field[1][1] == field[1][2]) ||
		('X' == field[2][0] == field[2][1] == field[2][2]) ||
		('X' == field[0][0] == field[1][0] == field[2][0]) ||
		('X' == field[0][1] == field[1][1] == field[2][1]) ||
		('X' == field[0][2] == field[1][2] == field[2][2]) ||
		('X' == field[0][0] == field[1][1] == field[2][2]) ||
		('X' == field[0][2] == field[1][1] == field[2][0])) {
		return 1;
	}
	else if (('O' == field[0][0] == field[0][1] == field[0][2]) ||
		('O' == field[1][0] == field[1][1] == field[1][2]) ||
		('O' == field[2][0] == field[2][1] == field[2][2]) ||
		('O' == field[0][0] == field[1][0] == field[2][0]) ||
		('O' == field[0][1] == field[1][1] == field[2][1]) ||
		('O' == field[0][2] == field[1][2] == field[2][2]) ||
		('O' == field[0][0] == field[1][1] == field[2][2]) ||
		('O' == field[0][2] == field[1][1] == field[2][0])) {
		return 2;
	}
	else if (turn == 9){
		return 3;
	}
	else return 4;
}
