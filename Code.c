/*
This code has been compiled in Code::Blocks 16.01 IDE on Windows 10
Author:- Mishal Shah
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#pragma warning (disable:4996)
#define _CRT_SECURE_NO_WARNINGS

 
typedef struct
{
	char symbol;
	char name[50];
}Player_Info;

void chooseMenu();
void showRule(void);
void chooseSymbol();
int checkHorizontal(char game_board[]);
int checkVertical(char game_board[]);
int checkDiagonal(char game_board[]);
int checkDraw(char game_board[]);
void showBoard(char game_board[]);
void playwithFriend();
void playwithComputer();
void showLeaderBoard(FILE *leaderboard);
void quit();

Player_Info player1 = { '\0','\0' };
Player_Info player2 = { '\0','\0' };

int main(void)
{

	int current_player = 1;
	int game_state = 0;
	const int someoneWin = 1;
	const int keepGoing = 0;
	const char* gotoTwoPlayerGame = "1";
	const char* gotoComputerGame = "2";
	const char* gotoLeaderBoard = "3";
	const char* quitGame = "4";

	const int player1_turn = 1;
	const int player2_turn = 2;
	char board_symbol[9] = { '1','2','3','4','5','6','7','8','9' };

 
	system("color 09");
	showRule();
	chooseMenu();

}

 

int checkHorizontal(char game_board[])
{

	const int horizontal_complete = 1;
	const int horizontal_fail = 0;

	if (game_board[0] == game_board[1] && game_board[1] == game_board[2])
		return horizontal_complete;
	else if (game_board[3] == game_board[4] && game_board[4] == game_board[5])
		return horizontal_complete;
	else if (game_board[6] == game_board[7] && game_board[7] == game_board[8])
		return horizontal_complete;
	else
		return horizontal_fail;

}


int checkVertical(char game_board[])
{

	const int vertical_complete = 1;
	const int vertical_fail = 0;

	if (game_board[0] == game_board[3] && game_board[3] == game_board[6])
		return vertical_complete;

	else if (game_board[1] == game_board[4] && game_board[4] == game_board[7])
		return vertical_complete;

	else if (game_board[2] == game_board[5] && game_board[5] == game_board[8])
		return vertical_complete;

	else
		return vertical_fail;

}

 

int checkDiagonal(char game_board[])
{

	const int diagonal_complete = 1;
	const int diagonal_fail = 0;

	if (game_board[0] == game_board[4] && game_board[4] == game_board[8])
		return diagonal_complete;

	else if (game_board[2] == game_board[4] && game_board[4] == game_board[6])
		return diagonal_complete;

	else
		return diagonal_fail;

}

 

int checkDraw(char game_board[])
{

	const int draw_complete = -1;
	const int draw_fail = 0;

	if (game_board[0] != '1' && game_board[1] != '2' && game_board[2] != '3' && game_board[3] != '4' && game_board[4] != '5' && game_board[5] != '6' && game_board[6] != '7' && game_board[7] != '8' && game_board[8] != '9')
		return draw_complete;

	else
		return draw_fail;
 
}

void showLeaderBoard(FILE *leaderboard) {

	char cho[10];
	char c = '\0';
	int insert_error = 1;

	system("cls");
	printf("\n\n");
	printf("\tLEADERBOARD\n\n");
	printf("-------------------------\n");
	printf("Player1\t|Player2|Winner|\n");
	printf("-------------------------\n");

	leaderboard = fopen("leaderboard.txt", "r");

	while (c != EOF)
	{

		c = (char)(getc(leaderboard));
		printf("%c", c);
	}
	fclose(leaderboard);

	chooseMenu(); 

}

void quit() {

	printf("\nBye~~\n");
	exit(1);
}

 

void showBoard(char game_board[])
{

	system("cls");
	printf("\tTic-Tac-Toe\n\n");
	printf("\n\n");
	printf("%s:- (%c)\n%s:-  (%c)\n\n\n", player1.name, player1.symbol, player2.name, player2.symbol);
	printf("  %c |  %c | %c\n", game_board[0], game_board[1], game_board[2]);
	printf("    |    |    \n");
	printf("----|----|----\n");
	printf("    |    |    \n");
	printf("  %c |  %c | %c\n", game_board[3], game_board[4], game_board[5]);

	printf("    |    |    \n");
	printf("----|----|----\n");
	printf("  %c |  %c | %c\n", game_board[6], game_board[7], game_board[8]);
	printf("    |    |    \n");

}

 

void showRule(void)
{

	char link[10];
	printf("\tTic-Tac-Toe\n\n");
	printf("Welcome to the most played 2D game and a sort of fun using X and O\n\n");
	printf("Rules:-\n");

	printf("\n1:Each player will be entering the number to put respective X or O in the desired position");

	printf("\n2:Player who gets a combination of 3 same characters either diagonal or horizontally or \n  vertically will be declared as the winner");

	printf("\n\nEnjoy the game! Be a Winner!\n\n");

	printf("For more clarifications press Y else type any other character:- ");

	scanf("%[^\n]s", link);
	if (strcmp(link, "y") == 0 || strcmp(link, "Y") == 0)
	{
		system("start http://www.wikihow.com/Play-Tic-Tac-Toe");
	}

}

void chooseSymbol()
{

	char dec[10];
	int insert_error = 1;
	printf("\n\nPlayer1 %s choose the X or 0:", player1.name);

	while (insert_error) {
		scanf("%s", dec);
		if (strcmp(dec, "X") == 0 || strcmp(dec, "x") == 0)
		{
			player1.symbol = 'X';
			player2.symbol = '0';
			insert_error = 0;
		}

		else if (strcmp(dec, "O") == 0 || strcmp(dec, "o") == 0)
		{
			player1.symbol = '0';
			player2.symbol = 'X';
			insert_error = 0;
		}

		else
		{
			printf("Please enter either X or O only \n\n");
		}

	}
}

 

void chooseMenu() {

	FILE *leaderboard;
	const char* gotoTwoPlayerGame = "1";
	const char* gotoComputerGame = "2";
	const char* gotoLeaderBoard = "3";
	const char* quitGame = "4";
	int insert_error = 0;
	char menu_option[10];

	leaderboard = fopen("leaderboard.txt", "a+");

	while (!insert_error) {

		printf("\n\nPress 1 to play with friend\nPress 2 to play with computer\nPress 3 to show LeaderBoard\nPress 4 to quit Game\n--> ");
		scanf("%s", menu_option);

		if (strcmp(menu_option, gotoTwoPlayerGame) == 0) {
			playwithFriend();
			break;

		}
		else if (strcmp(menu_option, gotoComputerGame) == 0) {
			playwithComputer();
			break;
		}

		else if (strcmp(menu_option, gotoLeaderBoard) == 0) {
			showLeaderBoard(leaderboard);
			break;
		}

		else if (strcmp(menu_option, quitGame) == 0) {
			quit();
		}

		else {
			printf("\nWrong insert. Press Again!");
		}

	}

}

 

void playwithFriend() {

	printf("play with Friend!\n");

}


void playwithComputer() {

	printf("play with Computer!\n");

}

