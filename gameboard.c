#include <Windows.h>
#include <stdio.h>
#include "declaration.h"
#include "leaderboard.h"
#include "gameboard.h"
#include "gamesetting.h"
#pragma warning (disable:4996)

extern const int player2_turn;
extern const int success;
extern const int failure;
extern Player_Info player1;
extern Player_Info player2;

int checkHorizontal(char game_board[])
{
	if (isIndexValueSame(game_board, 0, 1, 2))
	{
		return success;
	}
	else if (isIndexValueSame(game_board, 3, 4, 5))
	{
		return success;
	}

	else if (isIndexValueSame(game_board, 6, 7, 8))
	{
		return success;
	}

	else
	{
		return failure;
	}

}

 
int checkVertical(char game_board[])
{
	if (isIndexValueSame(game_board, 0, 3, 6))
	{
		return success;
	}
	else if (isIndexValueSame(game_board, 1, 4, 7))
	{
		return success;
	}

	else if (isIndexValueSame(game_board, 2, 5, 8))
	{
		return success;
	}

	else
	{
		return failure;
	}
}

 

int checkDiagonal(char game_board[])
{
	if (isIndexValueSame(game_board, 0, 4, 8))
	{
		return success;
	}

	else if (isIndexValueSame(game_board, 2, 4, 6))
	{
		return success;
	}

	else
	{
		return failure;
	}	

}

int checkDraw(char game_board[])
{
	for (int i = 0; i < 9; i++)
	{
		if (game_board[i] == i + '1')
		{
			return failure;
		}
	}
	return success;
}

int checkVacancies(int i, char game_board[])
{
	if (game_board[i] == i + '1')
	{
		return success;
	}
	else
	{
		return failure;
	}
}

int isIndexValueSame(char game_board[], int index1, int index2, int index3)
{
	const int same_values = 1;
	const int differ_values = 0;

	if (game_board[index1] == game_board[index2])
	{
		if (game_board[index2] == game_board[index3])
		{
			return same_values;
		}
	}
	return differ_values;

}

int checkPosition(char board_position[], char game_board[], char symbol, int current_player) 
{
	char check_position[9][2] = { "1","2","3","4","5","6","7","8","9" };
	int check_proper_position = 0;
	const int proper_position = 1;
	const int improper_position = 0;
	for (int i = 0; i < 9; i++)
	{
		if (strcmp(check_position[i], board_position) == 0)
		{
			if (checkVacancies(i, game_board))
			{
				check_proper_position = proper_position;
				game_board[i] = symbol;
				current_player = changePlayer(current_player);
				break;
			}

		}

	}
 
	if (check_proper_position == improper_position) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("Wrong Selection\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		Sleep(1000);
	}
	return current_player;

}

void showBoard(char game_board[])
{

	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("==========================\n");
	printf("\tTic-Tac-Toe \n");
	printf("==========================\n");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	if (strcmp(player1.name, "\0") == 0)
	{
		printf("Player:- (0)\nComputer:-  (X)\n\n\n");
	}
	else
	{
		printf(" Player %s Symbol is (%c)\n Player %s Symbol is (%c)\n\n", player1.name, player1.symbol, player2.name, player2.symbol);
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("==========================\n");
	printf("||      ||      ||      ||\n");
	printf("||      ||      ||      ||\n");
	printf("||");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("   %c", game_board[0]);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("  ||");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("   %c", game_board[1]);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("  ||");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("   %c", game_board[2]);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("  ||\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("||      ||      ||      ||\n");
	printf("||      ||      ||      ||\n");
	printf("==========================\n");
	printf("||      ||      ||      ||\n");
	printf("||      ||      ||      ||\n");
	printf("||");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("   %c", game_board[3]);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("  ||");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("   %c", game_board[4]);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("  ||");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("   %c", game_board[5]);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("  ||\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("||      ||      ||      ||\n");
	printf("||      ||      ||      ||\n");
	printf("==========================\n");
	printf("||      ||      ||      ||\n");
	printf("||      ||      ||      ||\n");
	printf("||");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("   %c", game_board[6]);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("  ||");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("   %c", game_board[7]);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("  ||");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("   %c", game_board[8]);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("  ||\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("||      ||      ||      ||\n");
	printf("||      ||      ||      ||\n");
	printf("==========================\n");
}

int checkSomeoneWin(char game_board[])
{
	const int someone_win = 1;
	const int draw = -1;
	const int game_continue = 0;

	if (checkHorizontal(game_board))
	{
		return someone_win;
	}

	else if (checkVertical(game_board))
	{
		return someone_win;
	}

	else if (checkDiagonal(game_board))
	{
		return someone_win;
	}

	else if (checkDraw(game_board))
	{
		return draw;
	}

	else
	{
		return game_continue;
	}

}

void showResult(int game_state, int current_player)
{
	const int someone_win = 1;
	FILE* leaderboard = fopen("leaderboard.txt", "a+");
	checkFile(leaderboard);

	fprintf(leaderboard, "%s\t%s\t", player1.name, player2.name);

	if (game_state == someone_win)
	{
		if (current_player == player2_turn)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			printf("\n******* %s Wins *******\n\n", player1.name);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			fprintf(leaderboard, "%s\n", player1.name);
		}

		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			printf("\n******* %s Wins *******\n\n", player2.name);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			fprintf(leaderboard, "%s\n", player2.name);
		}
	}

	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		printf("\n*****Game Draws!*****\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		fprintf(leaderboard, "%s\n", "DRAW");
	}
	fclose(leaderboard);
 
}
