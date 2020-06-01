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
void showRule(void);
void chooseSymbol();
int checkHorizontal(char game_board[]);
int checkVertical(char game_board[]);
int checkDiagonal(char game_board[]);
int checkDraw(char game_board[]);
void showBoard(char game_board[]);
void enterName();
int changePlayer(int current_player);
int checksomeoneWin(char game_board[]);
void playwithFriend();

Player_Info player1 = { '\0','\0' };
Player_Info player2 = { '\0','\0' };

int main(void)
{
	FILE *leaderboard;
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
	char menu_option[10];
 
	system("color 09");
	showRule();
	printf("\n\nPress 1 to play with friend\nPress 2 to play with computer\nPress 3 to show LeaderBoard\nPress 4 to quit Game\n--> ");
	scanf("%s", menu_option);
	if (strcmp(menu_option, gotoTwoPlayerGame) == 0)
	{
		playwithFriend();
	}
	else if (strcmp(menu_option, gotoLeaderBoard) == 0)
	{
		char cho[10];
		char c = '\0';
		int insert_error = 1;
	menu2:
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
		while(insert_error)
		{
			printf("\n\nPress 1 to start the game with friends, Press 2 to start the game_with_computer, Press 4 to quit game : ");
			scanf("%s", cho);
			if (strcmp(cho, gotoTwoPlayerGame) == 0)
			{
				playwithFriend();
			}
			else if (strcmp(cho, quitGame) == 0)
			{
				printf("\n\nBye~\n");
				break;
			}
			else
			{
				printf("\nPress again!");
				getchar();
			}
		}
	}
	else
	{
	menu3:
		printf("잘못된 입력입니다!");
		printf("2인용게임을 시작하려면 1을, 컴퓨터게임을 시작하려면 2를, 리더보드를 보려면 3를 입력하세요");
		scanf("%s", menu_option);
		if (strcmp(menu_option, gotoTwoPlayerGame) == 0)
		{
			playwithFriend();
		}
		else if (strcmp(menu_option, gotoLeaderBoard) == 0)
		{
			goto menu2;
		}
		else
		{
			goto menu3;
		}
	}
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

void enterName()
{
	printf("\nEnter name of player1: ");
	scanf("%s", player1.name);
	printf("Enter name of player2: ");
	scanf("%s", player2.name);
	while (!strcmp(player1.name, player2.name)) {
		printf("Enter names of different players!\n\n");
		printf("\nEnter name of player1: ");
		scanf("%s", player1.name);
		printf("Enter name of player2: ");
		scanf("%s", player2.name);
	}

}
void playwithFriend()
{
	const int keepGoing = 0;
	int game_state = 0;
	const int player1_turn = 1;
	const int player2_turn = 2;
	char board_symbol[9] = { '1','2','3','4','5','6','7','8','9' };
	char board_position[100];
	char symbol;
	int current_player = 1;
	const int someoneWin = 1;
	FILE *leaderboard = fopen("leaderboard.txt", "a+");
	
	enterName();
	chooseSymbol();
	system("color fc");

	showBoard(board_symbol);
	while (game_state == keepGoing)
	{
		if (current_player == player1_turn)
			printf("%s Type any digit from 1-9 to fill your response:- ", player1.name);
		else
			printf("%s Type any digit from 1-9 to fill your response:- ", player2.name);
		scanf("%s", board_position);
		if (current_player == player1_turn)
		{
			symbol = player1.symbol;
		}
		else
		{
			symbol = player2.symbol;
		}
		if (strcmp(board_position, "1") == 0 && board_symbol[0] == '1')
		{
			board_symbol[0] = symbol;
			current_player = changePlayer(current_player);
		}
		else if (strcmp(board_position, "2") == 0 && board_symbol[1] == '2')
		{
			board_symbol[1] = symbol;
			current_player = changePlayer(current_player);
		}
		else if (strcmp(board_position, "3") == 0 && board_symbol[2] == '3')
		{

			board_symbol[2] = symbol;
			current_player = changePlayer(current_player);
		}
		else if (strcmp(board_position, "4") == 0 && board_symbol[3] == '4')
		{
			board_symbol[3] = symbol;
			current_player = changePlayer(current_player);
		}
		else if (strcmp(board_position, "5") == 0 && board_symbol[4] == '5')
		{
			board_symbol[4] = symbol;
			current_player = changePlayer(current_player);
		}
		else if (strcmp(board_position, "6") == 0 && board_symbol[5] == '6')
		{
			board_symbol[5] = symbol;
			current_player = changePlayer(current_player);
		}
		else if (strcmp(board_position, "7") == 0 && board_symbol[6] == '7')
		{
			board_symbol[6] = symbol;
			current_player = changePlayer(current_player);
		}
		else if (strcmp(board_position, "8") == 0 && board_symbol[7] == '8')
		{
			board_symbol[7] = symbol;
			current_player = changePlayer(current_player);
		}
		else if (strcmp(board_position, "9") == 0 && board_symbol[8] == '9')
		{
 
			board_symbol[8] = symbol;
			current_player = changePlayer(current_player);
		}
		else
		{
			printf("Wrong Selection\n");
			Sleep(1000);
		}
		game_state = checksomeoneWin(board_symbol);
		showBoard(board_symbol);
		leaderboard = fopen("leaderboard.txt", "a+");
		if (game_state == someoneWin)
		{
			if (current_player == 2)
			{
				printf("\n\nPlayer1 %s Wins!\n\n", player1.name);
				fprintf(leaderboard, "\t%s", player1.name);
			}
			else
			{
				printf("\n\nPlayer2 %s Wins!\n\n", player2.name);
				fprintf(leaderboard, "\t%s", player2.name);
			}
			fclose(leaderboard);
		}
		else
		{
			printf("\n\nGame Draws!\n\n");
			fprintf(leaderboard, "\t%s", "DRAW");
			fclose(leaderboard);
		}
	}
}

int changePlayer(int current_player) {
	const int player1_turn = 1;
	const int player2_turn = 2;

	if (current_player == player1_turn) {
		return player2_turn;
	}
	else
	{
		return player1_turn;
	}
}

int checksomeoneWin(char game_board[]) {
	if (checkHorizontal(game_board)) {
		return 1;
	}
	else if (checkVertical(game_board)) {
		return 1;
	}
	else if (checkDiagonal(game_board)) {
		return 1;
	}
	else if (checkDraw(game_board)) {
		return -1;
	}
	else {
		return 0;
	}
}
