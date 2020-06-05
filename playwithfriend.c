#include <Windows.h>
#include <stdio.h>
#include "declaration.h"
#include "playwithfriend.h"
#pragma warning (disable:4996)

void playWithFriend(void) 
{
	const int keepGoing = 0;
	int game_state = 0;
	int current_player = 1;
	char board_symbol[9] = { '1','2','3','4','5','6','7','8','9' };
	char board_position[100];
	char symbol;
	
	inputName();
	chooseSymbol();
	showBoard(board_symbol);

	while (game_state == keepGoing)
	{
		checkTurn(current_player);
		scanf("%s", board_position);
		symbol = checkSymbol(current_player);
		current_player = checkPosition(board_position, board_symbol, symbol, current_player);
		game_state = checkSomeoneWin(board_symbol);
		showBoard(board_symbol);
	}
	showResult(game_state, current_player);
}

int checkLongName(void) 
{
	const int max_length = 10;
	int length_player1Name = strlen(player1.name);
	int length_player2Name = strlen(player2.name);

	if (length_player1Name > max_length)
	{
		return success;
	}
	else if (length_player2Name > max_length)
	{
		return success;
	}
	else
	{
		return failure;
	}
}

int isNameSame(void) 
{
	if (strcmp(player1.name, player2.name) == 0)
	{
		return success;
	}
	else
	{
		return failure;
	}
}

void inputName(void) 
{
	enterName();
	while (isNameSame())
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("\n\tEnter names of different players!\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		enterName();
	}
	
	while (checkLongName())
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("\n\tPlease enter name within 10 characters!\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		enterName();
	}
}

void enterName(void)
{
	printf("\n\tEnter name of player1: ");
	scanf("%s", player1.name);
	printf("\tEnter name of player2: ");
	scanf("%s", player2.name);
}
