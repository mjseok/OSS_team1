#include <Windows.h>
#include <stdio.h>
#include "declaration.h"
#include "playwithcomputer.h"
#include "gameboard.h"
#include "gamesetting.h"
#pragma warning (disable:4996)

extern const int PLAYER1_TURN;
extern Player_Info player1;
extern Player_Info player2;

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
/* 가로, 세로, 대각선을 완성시킬 수 있는 index를 찾아 반환하는 함수 */
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
	/* 보드에서 가로, 세로, 대각선이 완성되는 index의 집합 */
	int winning_case[8][3] = { { 0, 1, 2 },{ 3, 4, 5 },{ 6, 7, 8 },{ 0, 3, 6 },{ 1, 4, 7 },{ 2, 5, 8 },{ 0, 4, 8 },{ 2, 4, 6 } };
	int final_index = 0;
	int i;

	/* 컴퓨터가 이기는 경우의 index값 찾기 */
	for (i = 0; i < 8; i++)
	{
		final_index = checkCaseOnComputer(game_board, winning_case[i][0], winning_case[i][1], winning_case[i][2], computer_symbol);
		if (final_index)
		{
			return final_index;
		}
	}

	/* 컴퓨터가 지는 경우의 index값 찾기 */
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
	const int KEEPGOING = 0;
	const int ANYWHERE = 0;
	int game_state = KEEPGOING;
	int current_player = PLAYER1_TURN;
	int computer;
	char player_symbol;
	char computer_symbol;

	strcpy(player1.name, "Player");
	strcpy(player2.name, "Computer");
	chooseSymbol();
	showBoard(board_symbol);

	player_symbol = player1.symbol;
	computer_symbol = player2.symbol;

	while (game_state == KEEPGOING)
	{
		if (current_player == PLAYER1_TURN)
		{
			checkTurn(current_player);
			scanf("%s", board_position);
			current_player = checkPosition(board_position, board_symbol, player_symbol, current_player);
		}

		else
		{	/* computer: computer가 보드에 놓을 기호의 최적의 위치 */
			computer = checkComputer(board_symbol, computer_symbol, player_symbol);
			if (computer == ANYWHERE)
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
