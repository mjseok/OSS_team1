#include <Windows.h>
#include <stdio.h>
#include "declaration.h"
#include "leaderboard.h"
#include "ui.h"
#pragma warning (disable:4996)

void showLeaderBoard(void)
{	
	FILE* leaderboard;
	char player1_name[11] = "\0";
	char player2_name[11] = "\0";
	char result[11] = "\0";
	/* 리더보드의 일관적인 출력을 위해, 기준이 되는 tab의 길이를  상수 선언 */
	const int TAB_SIZE = 8;
	
	system("cls");
	printf("\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("\t\t\t  << LEADERBOARD >>\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("-------------------------------------------------------------------------\n");
	printf("|\tPlayer1\t\t|\tPlayer2\t\t|\tWinner\t\t|\n");
	printf("-------------------------------------------------------------------------\n");

	leaderboard= fopen("leaderboard.txt", "a+");
	checkFile(leaderboard);
	
	fscanf(leaderboard, "%s %s %s", player1_name, player2_name, result);
	while (!feof(leaderboard)) 
	{
		if ((int)(strlen(player1_name)) < TAB_SIZE)
		{
			printf("|\t%s\t\t|", player1_name);
		}
		else
		{
			printf("|\t%s\t|", player1_name);
		}

		if ((int)(strlen(player2_name)) < TAB_SIZE)
		{
			printf("\t%s\t\t|", player2_name);
		}

		else
		{
			printf("\t%s\t|", player2_name);
		}

		if ((int)(strlen(result)) < TAB_SIZE)
		{
			printf("\t%s\t\t|\n", result);
		}

		else
		{
			printf("\t%s\t|\n", result);
		}
		printf("-------------------------------------------------------------------------\n");
		fscanf(leaderboard, "%s %s %s", player1_name, player2_name, result);
	}

	fclose(leaderboard);
	chooseMenu();
}

void checkFile(FILE* file)
{
	if (file == NULL)
	{
		printf("File doesn't linked!\n");
	}
}
