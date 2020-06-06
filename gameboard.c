#include <Windows.h>
#include <stdio.h>
#include "declaration.h"
#include "leaderboard.h"
#include "gameboard.h"
#include "gamesetting.h"
#pragma warning (disable:4996)

extern const int PLAYER2_TURN;
extern const int SUCCESS;
extern const int FAILURE;
extern Player_Info player1;
extern Player_Info player2;

/* checkHorizontal, checkVertical, checkDiagonal, checkDraw의 반환값은 checkSomeOneWin 의 조건문에서 쓰인다 */
int checkHorizontal(char game_board[])
{
	if (isIndexValueSame(game_board, 0, 1, 2))
	{
		return SUCCESS;
	}
	else if (isIndexValueSame(game_board, 3, 4, 5))
	{
		return SUCCESS;
	}

	else if (isIndexValueSame(game_board, 6, 7, 8))
	{
		return SUCCESS;
	}

	else
	{
		return FAILURE;
	}

}

 
int checkVertical(char game_board[])
{
	if (isIndexValueSame(game_board, 0, 3, 6))
	{
		return SUCCESS;
	}
	else if (isIndexValueSame(game_board, 1, 4, 7))
	{
		return SUCCESS;
	}

	else if (isIndexValueSame(game_board, 2, 5, 8))
	{
		return SUCCESS;
	}

	else
	{
		return FAILURE;
	}
}

 

int checkDiagonal(char game_board[])
{
	if (isIndexValueSame(game_board, 0, 4, 8))
	{
		return SUCCESS;
	}

	else if (isIndexValueSame(game_board, 2, 4, 6))
	{
		return SUCCESS;
	}

	else
	{
		return FAILURE;
	}	

}
/* 무승부 확인 : 보드가 모두 기호로 변경되었는지 확인한다. */
int checkDraw(char game_board[])
{
	for (int i = 0; i < 9; i++)
	{
		if (game_board[i] == i + '1')
		{
			return FAILURE;
		}
	}
	return SUCCESS;
}

int checkVacancies(int i, char game_board[])
{
	if (game_board[i] == i + '1')
	{
		return SUCCESS;
	}
	else
	{
		return FAILURE;
	}
}

int isIndexValueSame(char game_board[], int index1, int index2, int index3)
{
	const int SAME_VALUES = 1;
	const int DIFFER_VALUES = 0;

	if (game_board[index1] == game_board[index2])
	{
		if (game_board[index2] == game_board[index3])
		{
			return SAME_VALUES;
		}
	}
	return DIFFER_VALUES;

}

int checkPosition(char board_position[], char game_board[], char symbol, int current_player) 
{
	char check_position[9][2] = { "1","2","3","4","5","6","7","8","9" };
	const int PROPER_POSITION = 1;
	const int IMPROPER_POSITION = 0;
	int check_proper_position = IMPROPER_POSITION;

	for (int i = 0; i < 9; i++)
	{
		if (strcmp(check_position[i], board_position) == 0)
		{
			if (checkVacancies(i, game_board))
			{
				check_proper_position = PROPER_POSITION;
				game_board[i] = symbol;
				current_player = changePlayer(current_player);
				break;
			}

		}

	}
 
	if (check_proper_position == IMPROPER_POSITION) 
	{
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
	const int SOMEONE_WIN = 1;
	const int DRAW = -1;
	const int GAME_CONTINUE = 0;

	if (checkHorizontal(game_board))
	{
		return SOMEONE_WIN;
	}

	else if (checkVertical(game_board))
	{
		return SOMEONE_WIN;
	}

	else if (checkDiagonal(game_board))
	{
		return SOMEONE_WIN;
	}

	else if (checkDraw(game_board))
	{
		return DRAW;
	}

	else
	{
		return GAME_CONTINUE;
	}

}

void showResult(int game_state, int current_player)
{
	const int SOMEONE_WIN = 1;
	FILE* leaderboard = fopen("leaderboard.txt", "a+");
	checkFile(leaderboard);

	fprintf(leaderboard, "%s\t%s\t", player1.name, player2.name);

	if (game_state == SOMEONE_WIN)
	{
		if (current_player == PLAYER2_TURN)
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
