#include "stdafx.h"
#include <iostream>

using namespace std;

void Init();		// инициализация поля
void Gameplay();	// процесс игры
bool Repeat();		// запускать ли повторно?
void PrintField();	// вывод поля
int WinCheck();		// проверка исхода

char field[3][3];
int turn = 0;


int main()
{
	Init();
	Gameplay();
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
	PrintField();
	while (WinCheck() == 4){
		if (curPlayer == 1) {
			cout << "X turn: ";
		}
		else cout << "O turn: ";
		cin >> row >> column;
		if (curPlayer == 1) field[row - 1][column - 1] = 'X';
		else				field[row - 1][column - 1] = 'O';
		curPlayer *= -1;
		turn++;
		PrintField();
	}
	switch (WinCheck()) {
		case 1: {
			cout << "First player won, repeat? (y/n)\n";
			break;
		}
		case 2: {
			cout << "Second player won, repeat? (y/n)\n";
			break;
		}
		case 3: {
			cout << "Draw, repeat? (y/n)\n";
			break;
		}
	}
	if (Repeat() == true) {
		turn = 0;
		Init();
		Gameplay();
	}
}

void PrintField() {
	cout << "-" << field[0][0] << "-|-" << field[0][1] << "-|-" << field[0][2] << "-\n";
	cout << "-" << field[1][0] << "-|-" << field[1][1] << "-|-" << field[1][2] << "-\n";
	cout << "-" << field[2][0] << "-|-" << field[2][1] << "-|-" << field[2][2] << "-\n";
}

int WinCheck() {
	
	if ((field[0][0] == 'X' && field[0][1] == 'X' && field[0][2] == 'X') ||
		(field[1][0] == 'X' && field[1][1] == 'X' && field[1][2] == 'X') ||
		(field[2][0] == 'X' && field[2][1] == 'X' && field[2][2] == 'X') ||
		(field[0][0] == 'X' && field[1][0] == 'X' && field[2][0] == 'X') ||
		(field[0][1] == 'X' && field[1][1] == 'X' && field[2][1] == 'X') ||
		(field[0][2] == 'X' && field[1][2] == 'X' && field[2][2] == 'X') ||
		(field[0][0] == 'X' && field[1][1] == 'X' && field[2][2] == 'X') ||
		(field[0][2] == 'X' && field[1][1] == 'X' && field[2][0] == 'X')) {
		return 1;
	}
	else if ((field[0][0] == 'O' && field[0][1] == 'O' && field[0][2] == 'O') ||
		(field[1][0] == 'O' && field[1][1] == 'O' && field[1][2] == 'O') ||
		(field[2][0] == 'O' && field[2][1] == 'O' && field[2][2] == 'O') ||
		(field[0][0] == 'O' && field[1][0] == 'O' && field[2][0] == 'O') ||
		(field[0][1] == 'O' && field[1][1] == 'O' && field[2][1] == 'O') ||
		(field[0][2] == 'O' && field[1][2] == 'O' && field[2][2] == 'O') ||
		(field[0][0] == 'O' && field[1][1] == 'O' && field[2][2] == 'O') ||
		(field[0][2] == 'O' && field[1][1] == 'O' && field[2][0] == 'O')) {
		return 2;
	}
	else if (turn == 9){
		return 3;
	}
	else return 4;
}

bool Repeat() {
	char repeat;
	cin >> repeat;
	if (repeat == 'y') {
		return true;
	}
	else return false;
}