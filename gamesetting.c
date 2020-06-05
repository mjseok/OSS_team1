#include <Windows.h>
#include <stdio.h>
#include "declaration.h"
#include "gamesetting.h"
#pragma warning (disable:4996)

extern const int player1_turn;
extern const int player2_turn;
extern const int success;
extern const int failure;
extern Player_Info player1;
extern Player_Info player2;

char checkSymbol(int current_player) 
{
	if (current_player == player1_turn)
	{
		return player1.symbol;
	}
	else
	{
		return player2.symbol;
	}
}

void checkTurn(int current_player) 
{
	if (current_player == player1_turn)
	{
		printf("%s Type any digit from 1-9 to fill your response:- ", player1.name);
	}
	else
	{
		printf("%s Type any digit from 1-9 to fill your response:- ", player2.name);
	}
}

void chooseSymbol(void)
{
	const int correct = 1;
	const int incorrect = 0;
	char get_symbol[10];
	int menu_input = incorrect;
	int right_input;

	while (menu_input == incorrect)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		printf("\n\n\t%s choose the X or O:", player1.name);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		scanf("%s", get_symbol);
		right_input = setSymbol(get_symbol);
		if (right_input)
		{
			menu_input = correct;
		}

		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			printf("\n\tPlease enter either X or O only \n\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			menu_input = incorrect;
		}
	}
}

int isRightInput(char* player_symbol, char* capital_letter, char* small_letter)
{
	int string_same;
	string_same = strcmp(player_symbol, capital_letter);
	if (string_same == 0)
	{
		return success;
	}

	string_same = strcmp(player_symbol, small_letter);
	if (string_same == 0)
	{
		return success;
	}
	return failure;
}

int setSymbol(char* player1_symbol)
{
	int is_player_symbol;
	is_player_symbol = isRightInput(player1_symbol, "X", "x");

	if (is_player_symbol)
	{
		player1.symbol = 'X';
		player2.symbol = 'O';
		return success;
	}

	is_player_symbol = isRightInput(player1_symbol, "O", "o");
	if (is_player_symbol)
	{
		player1.symbol = 'O';
		player2.symbol = 'X';
		return success;
	}
	return failure;

}

int changePlayer(int current_player)
{
	if (current_player == player1_turn)
	{
		return player2_turn;
	}

	else
	{
		return player1_turn;
	}
}
