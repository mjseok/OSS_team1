#include <Windows.h>
#include <stdio.h>
#include "declaration.h"
#include "playwithcomputer.h"
#pragma warning (disable:4996)

int checkValueOnComputer(char game_board[], int index1, int index2, int index3, char symbol)
{
	if (game_board[index1] == symbol && game_board[index2] == symbol)
	{
		if (game_board[index3] != player1.symbol && game_board[index3] != player2.symbol)
		{
			return index3;
		}
	}
	return 0;
}

int checkCaseOnComputer(char game_board[], int index1, int index2, int index3, char symbol)
{
	int proper_index = 0;
	proper_index = checkValueOnComputer(game_board, index1, index2, index3, symbol);

	if (proper_index)
	{
		return proper_index;
	}

	proper_index = checkValueOnComputer(game_board, index2, index3, index1, symbol);

	if (proper_index)
	{
		return proper_index;
	}
	
	proper_index = checkValueOnComputer(game_board, index1, index3, index2, symbol);
	return proper_index;
}

int findBlankForComputer(char game_board[], char computer_symbol, char player_symbol)
{
	int i;
	int computer_index = 0;
	
	for (i = 0; i < 9; i++)
	{
		if (game_board[i] != computer_symbol && game_board[i] != player_symbol)
		{
			computer_index = i;
			return computer_index;
		}
	}
	return computer_index;

}

int checkComputer(char game_board[], char computer_symbol, char player_symbol)
{
	int winning_case[8][3] = { { 0, 1, 2 },{ 3, 4, 5 },{ 6, 7, 8 },{ 0, 3, 6 },{ 1, 4, 7 },{ 2, 5, 8 },{ 0, 4, 8 },{ 2, 4, 6 } };
	int final_index = 0;
	int i;

	//Find the case that the computer wins
	for (i = 0; i < 8; i++)
	{
		final_index = checkCaseOnComputer(game_board, winning_case[i][0], winning_case[i][1], winning_case[i][2], computer_symbol);
		if (final_index)
		{
			return final_index;
		}
	}

	//Find the case that computer loses
	for (i = 0; i < 8; i++)
	{
		final_index = checkCaseOnComputer(game_board, winning_case[i][0], winning_case[i][1], winning_case[i][2], player_symbol);
		if (final_index)
		{
			return final_index;
		}

	}
	return final_index;

}

void playWithComputer(void)
{
	char board_symbol[9] = { '1','2','3','4','5','6','7','8','9' };
	char board_position[10];
	const int keepGoing = 0;
	int game_state = 0;
	int current_player = 1;
	int computer;
	char player_symbol;
	char computer_symbol;

	strcpy(player1.name, "Player");
	strcpy(player2.name, "Computer");
	chooseSymbol();
	showBoard(board_symbol);

	player_symbol = player1.symbol;
	computer_symbol = player2.symbol;

	while (game_state == keepGoing)
	{
		if (current_player == player1_turn)
		{
			checkTurn(current_player);
			scanf("%s", board_position);
			current_player = checkPosition(board_position, board_symbol, player_symbol, current_player);
		}

		else
		{
			computer = checkComputer(board_symbol, computer_symbol, player_symbol);
			if (computer == 0)
			{
				computer = findBlankForComputer(board_symbol, computer_symbol, player_symbol);
			}

			board_symbol[computer] = computer_symbol;
			printf("Computer select %d\n", computer + 1);
			Sleep(1000);
			current_player = changePlayer(current_player);
		}
		game_state = checkSomeoneWin(board_symbol);
		showBoard(board_symbol);
	}
	showResult(game_state, current_player);
}
