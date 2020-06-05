#include <Windows.h>
#include <stdio.h>
#include "ui.h"
#pragma warning (disable:4996)
void startInterface(void) 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("\t|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("-----------------------------------------------------------");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("| \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("\t|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("-----------------------------------------------------------");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("| \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("\t|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	printf("-----------------------------------------------------------");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("| \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("\t|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	printf("======================");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("TIc - Tac - Toe");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	printf("======================");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("| \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("\t|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	printf("-----------------------------------------------------------");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("| \n");
	printf("\t|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("-----------------------------------------------------------");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("| \n"); printf("\t|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("-----------------------------------------------------------");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("| \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("\t|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("------------------------------------------DESIGNED BY TEAM1");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("|\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("\t - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");

	printf("\n\n\n\t☆★☆★☆★☆★☆★☆★☆Game Rule☆★☆★☆★☆★☆★☆★☆\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void chooseMenu(void)
{
	const char* gotoTwoPlayerGame = "1";
	const char* gotoComputerGame = "2";
	const char* gotoLeaderBoard = "3";
	const char* quitGame = "4";
	const int correct = 1;
	const int incorrect = 0;
	int menu_input = 0;
	char menu_option[10];

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf("\n\t〓〓〓〓〓〓MENU〓〓〓〓〓〓");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	while (menu_input == incorrect)
	{
		printf("\n\n\tPress 1 to play with friend\n\tPress 2 to play with computer\n\tPress 3 to show LeaderBoard\n\tPress 4 to quit Game\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		printf("\tMenu_option: ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		scanf("%s", menu_option);
		menu_input = correct;

		if (strcmp(menu_option, gotoTwoPlayerGame) == 0)
		{
			playWithFriend();
		}
		else if (strcmp(menu_option, gotoComputerGame) == 0)
		{
			playWithComputer();
		}
		else if (strcmp(menu_option, gotoLeaderBoard) == 0)
		{
			showLeaderBoard();
		}
		else if (strcmp(menu_option, quitGame) == 0)
		{
			quit();
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			printf("\n\tWrong insert. Press Again!");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			menu_input = incorrect;
		}
	}
}

void showRule(void)
{
	char more_rule[10];
	int is_input_yes;

	printf("\tWelcome to the most played 2D game and a sort of fun using X and O\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	printf("\n\tFirst:Each player will be entering the number to put respective X or O in the desired position\n");
	printf("\n\tSecond:Player who gets a combination of 3 same characters either diagonal or horizontally or vertically\n\t       will be declared as the winner");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

	printf("\n\n\tEnjoy the game! Be a Winner!\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("\tFor more clarifications press Y else type any other character: ");
	scanf("%[^\n]s", more_rule);
	is_input_yes = isRightInput(more_rule, "Y", "y");

	if (is_input_yes)
	{
		system("start http://www.wikihow.com/Play-Tic-Tac-Toe");
	}
	system("cls");
	
}

void startTicTacToe(void)
{
	startInterface();
	showRule();
	chooseMenu();
}

void quit(void) 
{
	printf("\n\tBye~~\n");
	exit(1);
}
