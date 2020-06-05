#include <Windows.h>
#include <stdio.h>
#include "declaration.h"
#include "leaderboard.h"
#pragma warning (disable:4996)

void showLeaderBoard(void)
{
	char player1_name[50] = "\0", player2_name[50] = "\0", result[100] = "\0";
	const int tab_size = 8;
	
	system("cls");
	printf("\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("\t\t\t  << LEADERBOARD >>\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("-------------------------------------------------------------------------\n");
	printf("|\tPlayer1\t\t|\tPlayer2\t\t|\tWinner\t\t|\n");
	printf("-------------------------------------------------------------------------\n");

	FILE* leaderboard = fopen("leaderboard.txt", "r");
	checkFile(leaderboard);

	while (!feof(leaderboard)) 
	{
		fscanf(leaderboard, "%s %s %s", player1_name, player2_name, result);
		
		if ((int)(strlen(player1_name)) < tab_size)
		{
			printf("|\t%s\t\t|", player1_name);
		}
		else
		{
			printf("|\t%s\t|", player1_name);
		}

		if ((int)(strlen(player2_name)) < tab_size)
		{
			printf("\t%s\t\t|", player2_name);
		}

		else
		{
			printf("\t%s\t|", player2_name);
		}

		if ((int)(strlen(result)) < tab_size)
		{
			printf("\t%s\t\t|\n", result);
		}

		else
		{
			printf("\t%s\t|\n", result);
		}
		printf("-------------------------------------------------------------------------\n");
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
