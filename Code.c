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

void chooseMenu(void);
void showRule(void);
void chooseSymbol();
int checkHorizontal(char game_board[]);
int checkVertical(char game_board[]);
int checkDiagonal(char game_board[]);
int checkDraw(char game_board[]);
void showBoard(char game_board[]);
void enterName(void);
int changePlayer(int current_player);
void showResult(FILE *leaderboard, int game_state, int current_player);
int checkSomeoneWin(char game_board[]);
void playWithFriend();
//void playWithComputer();
void showLeaderBoard(void);
void quit(void);
int checkposition(char board_position[], char board_symbol[], char symbol, int current_player);//
int checkVacancies(int i, char board_symbol[]);//
Player_Info player1 = { '\0','\0' };
Player_Info player2 = { '\0','\0' };
int main(void)
{
	system("color 09");
	showRule();
	chooseMenu();
}

void showResult(FILE *leaderboard, int game_state, int current_player)
{
	const int someone_win = 1;
	if (game_state == someone_win)
	{
		if (current_player == 2)
		{
			printf("\n\nPlayer1 %s Wins!\n\n", player1.name);
			fprintf(leaderboard, "%s\t%s\t%s\n", player1.name, player2.name, player1.name);
		}
		else
		{
			printf("\n\nPlayer2 %s Wins!\n\n", player2.name);
			fprintf(leaderboard, "%s\t%s\t%s\n", player1.name, player2.name, player2.name);
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

void showLeaderBoard() {
	char c = '\0';
	int insert_error = 1;

	system("cls");
	printf("\n\n");
	printf("\tLEADERBOARD\n\n");
	printf("-------------------------\n");
	printf("Player1\t|Player2|Winner|\n");
	printf("-------------------------\n");

	FILE *leaderboard = fopen("leaderboard.txt", "r");
	while(c!=EOF)
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

void enterName()
{
	printf("\nEnter name of player1: ");
	scanf("%s", player1.name);
	printf("Enter name of player2: ");
	scanf("%s", player2.name);
	while (!strcmp(player1.name, player2.name))
	{
		printf("Enter names of different players!\n\n");
		printf("\nEnter name of player1: ");
		scanf("%s", player1.name);
		printf("Enter name of player2: ");
		scanf("%s", player2.name);
	}
}

void playWithFriend() {
	const int keepGoing = 0;
	int game_state = 0;
	const int player1_turn = 1;
	const int player2_turn = 2;
	char board_symbol[9] = { '1','2','3','4','5','6','7','8','9' };
	char board_position[100];
	char check_position[9][2] = { "1","2","3","4","5","6","7","8","9" };
	char symbol;
	int current_player = 1;
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
		current_player = checkposition(board_position, board_symbol, symbol, current_player);
		game_state = checkSomeoneWin(board_symbol);
		showBoard(board_symbol);
	}
	showResult(leaderboard, game_state, current_player);
	fclose(leaderboard);
}

int checkposition(char board_position[], char board_symbol[], char symbol, int current_player) {

	char check_position[9][2] = { "1","2","3","4","5","6","7","8","9" };
	int flag = 0;

	for (int i = 0; i < 9; i++)
	{
		if (strcmp(check_position[i], board_position) == 0)
		{
			flag = 1;
			if (checkVacancies(i, board_symbol))
			{
				board_symbol[i] = symbol;
				current_player = changePlayer(current_player);
				break;
			}
			else 
			{
				printf("Wrong Selection\n");
				Sleep(1000);
			}
		}
	}
	if (flag == 0) {
		printf("Wrong Selection\n");
		Sleep(1000);
	}
	return current_player;
}

int checkVacancies(int i, char board_symbol[])
{
	const int vacancy = 1;
	const int not_vacanvy = 0;

	if (board_symbol[i] == i + '1')
       	{
		return vacancy;
	}
	else
	{
		return not_vacancy;
	}
}

int changePlayer(int current_player)
{
	const int player1_turn = 1;
	const int player2_turn = 2;

	if (current_player == player1_turn)
	{
		return player2_turn;
	}
	else
	{
		return player1_turn;
	}
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

void chooseMenu() 
{
	const char* gotoTwoPlayerGame = "1";
	const char* gotoComputerGame = "2";
	const char* gotoLeaderBoard = "3";
	const char* quitGame = "4";
	int insert_error = 0;
	char menu_option[10];

	while (!insert_error)
       	{
		printf("\n\nPress 1 to play with friend\nPress 2 to play with computer\nPress 3 to show LeaderBoard\nPress 4 to quit Game\n--> ");
		scanf("%s", menu_option);
		if (strcmp(menu_option, gotoTwoPlayerGame) == 0) 
		{
			playWithFriend();
			break;
		}
		else if (strcmp(menu_option, gotoComputerGame) == 0) 
		{
			//playWithComputer();
			break;
		}
		else if (strcmp(menu_option, gotoLeaderBoard) == 0) 
		{
			showLeaderBoard();
			break;
		}
		else if (strcmp(menu_option, quitGame) == 0) 
		{
			quit();
		}
		else 
		{
			printf("\nWrong insert. Press Again!");
		}
	}
}
