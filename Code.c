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

typedef struct player_information
{
	char symbol;
	char name[50];
}Player_Info;

void chooseMenu(void);
void showRule(void);
void chooseSymbol(void);
int checkHorizontal(char game_board[]);
int checkVertical(char game_board[]);
int checkDiagonal(char game_board[]);
int checkDraw(char game_board[]);
void showBoard(char game_board[]);
void enterName(void);
int changePlayer(int current_player);
void showResult(int game_state, int current_player);
int checkSomeoneWin(char game_board[]);
void playWithFriend(void);
void showLeaderBoard(void);

void quit(void);
int checkPosition(char board_position[], char game_board[], char symbol, int current_player);
int checkVacancies(int i, char game_board[]);
void checkTurn(int current_player);
char checkSymbol(int current_player);
void checkFile(FILE* file);

int checkValueOnComputer(char game_board[], int index1, int index2, int index3, char symbol);
int checkCaseOnComputer(char game_board[], int index1, int index2, int index3, char symbol);
int checkComputer(char game_board[], char computer_symbol, char player_symbol);
int findBlankForComputer(char game_board[], char computer_symbol, char player_symbol);
void playWithComputer(void);
int setSymbol(char* player1_symbol);
int isRightInput(char* player_symbol, char* capital_letter, char* small_letter);
int isIndexValueSame(char game_board[], int index1, int index2, int index3);

Player_Info player1 = { '\0','\0' };
Player_Info player2 = { '\0','\0' };
const int player1_turn = 1;
const int player2_turn = 2;
const int success =1;
const int failure = 0;


int main(void)
{
	system("color 09");
	showRule();
	chooseMenu();
}

void checkFile(FILE* file) {
	if (file == NULL)
	{
		printf("File doesn't linked!\n");
	}
}

char checkSymbol(int current_player) {
	if (current_player == player1_turn)
	{
		return player1.symbol;
	}
	else
	{
		return player2.symbol;
	}
}

void checkTurn(int current_player) {

	if (current_player == player1_turn)
	{
		printf("%s Type any digit from 1-9 to fill your response:- ", player1.name);
	}
	else
	{
		printf("%s Type any digit from 1-9 to fill your response:- ", player2.name);
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
			printf("\n\n %s Wins!\n\n", player1.name);
			fprintf(leaderboard, "%s\n", player1.name);
		}
		else
		{
			printf("\n\n %s Wins!\n\n", player2.name);
			fprintf(leaderboard, "%s\n", player2.name);
		}
	}
	else
	{
		printf("\n\nGame Draws!\n\n");
		fprintf(leaderboard, "%s\n", "DRAW");
	}
	fclose(leaderboard);
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
		return failure;
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
		return failure;
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
		return failure;
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

void showLeaderBoard(void) {
	char c = '\0';

	system("cls");
	printf("\n\n");
	printf("\tLEADERBOARD\n\n");
	printf("-------------------------\n");
	printf("Player1\t|Player2|Winner|\n");
	printf("-------------------------\n");

	FILE* leaderboard = fopen("leaderboard.txt", "r");
	checkFile(leaderboard);
	while (c != EOF)
	{
		c = (char)(getc(leaderboard));
		printf("%c", c);
	}
	fclose(leaderboard);
	chooseMenu();
}

void quit(void) {
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
	char more_rule[10];
	printf("\tTic-Tac-Toe\n\n");
	printf("Welcome to the most played 2D game and a sort of fun using X and O\n\n");
	printf("Rules:-\n");
	printf("\n1:Each player will be entering the number to put respective X or O in the desired position");
	printf("\n2:Player who gets a combination of 3 same characters either diagonal or horizontally or \n  vertically will be declared as the winner");
	printf("\n\nEnjoy the game! Be a Winner!\n\n");
	printf("For more clarifications press Y else type any other character:- ");
	scanf("%[^\n]s", more_rule);
	if (strcmp(more_rule, "y") == 0 || strcmp(more_rule, "Y") == 0)
	{
		system("start http://www.wikihow.com/Play-Tic-Tac-Toe");
	}
}

void chooseSymbol(void)
{
	const int correct=1;
	const int incorrect=0;
	char get_symbol[10];
	int menu_input = incorrect;
	int right_input;

	while (menu_input==incorrect) 
	{
		printf("\n\n %s choose the X or O:", player1.name);
		scanf("%s", get_symbol);
		right_input = setSymbol(get_symbol);
		if(right_input)
		{
			menu_input=correct;
		}
		else
		{
			printf("Please enter either X or O only \n\n");
			menu_input=incorrect;
		}
	}
}

int isRightInput(char* player_symbol, char* capital_letter, char* small_letter)
{
	int string_same;

	string_same = strcmp(player_symbol, capital_letter);
	if (string_same == 0)
	{
		return success;
	}

	string_same = strcmp(player_symbol, small_letter);
	if (string_same == 0)
	{
		return success;
	}

	return failure;
}

int setSymbol(char* player1_symbol)
{
	int is_player_symbol;
	
	is_player_symbol = isRightInput(player1_symbol, "X", "x");
	if(is_player_symbol)
	{
		player1.symbol = 'X';
		player2.symbol = 'O';
		return success;
	}

	is_player_symbol = isRightInput(player1_symbol, "O", "o");
	if (is_player_symbol)
	{
		player1.symbol = 'O';
		player2.symbol = 'X';
		return success;
	}

	return failure;
}

void enterName(void)
{
	printf("\nEnter name of player1: ");
	scanf("%s", player1.name);
	printf("Enter name of player2: ");
	scanf("%s", player2.name);
	while (strcmp(player1.name, player2.name) == 0)
	{
		printf("Enter names of different players!\n\n");
		printf("\nEnter name of player1: ");
		scanf("%s", player1.name);
		printf("Enter name of player2: ");
		scanf("%s", player2.name);
	}
}

void playWithFriend(void) {
	const int keepGoing = 0;
	int game_state = 0;

	char board_symbol[9] = { '1','2','3','4','5','6','7','8','9' };
	char board_position[100];
	char symbol;
	int current_player = 1;

	enterName();
	chooseSymbol();
	system("color fc");
	showBoard(board_symbol);

	while (game_state == keepGoing)
	{
		checkTurn(current_player);
		scanf("%s", board_position);
		symbol = checkSymbol(current_player);

		current_player = checkPosition(board_position, board_symbol, symbol, current_player);
		game_state = checkSomeoneWin(board_symbol);
		showBoard(board_symbol);
	}
	showResult(game_state, current_player);
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

int changePlayer(int current_player)
{

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

void chooseMenu(void)
{
	const char* gotoTwoPlayerGame = "1";
	const char* gotoComputerGame = "2";
	const char* gotoLeaderBoard = "3";
	const char* quitGame = "4";
	const int correct=1;
	const int incorrect=0;
	
	int menu_input= 0;
	char menu_option[10];

	while (menu_input==incorrect)
	{
		printf("\n\nPress 1 to play with friend\nPress 2 to play with computer\nPress 3 to show LeaderBoard\nPress 4 to quit Game\n--> ");
		scanf("%s", menu_option);
		menu_input=correct;

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
			printf("\nWrong insert. Press Again!");
			menu_input=incorrect;
		}
	}
}


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
		return proper_index;

	proper_index = checkValueOnComputer(game_board, index2, index3, index1, symbol);
	if (proper_index)
		return proper_index;

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
			return final_index;
	}

	//Find the case that computer loses
	for (i = 0; i < 8; i++)
	{
		final_index = checkCaseOnComputer(game_board, winning_case[i][0], winning_case[i][1], winning_case[i][2], player_symbol);
		if (final_index)
			return final_index;
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
   char symbol;
   const int someoneWin = 1;
   int computer;
   char player_symbol;
   char computer_symbol;

   strcpy(player1.name, "Player");
   strcpy(player2.name, "Computer");
   chooseSymbol();
   system("color fc");
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

int checkPosition(char board_position[], char game_board[], char symbol, int current_player) {
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
      printf("Wrong Selection\n");
      Sleep(1000);
   }
   return current_player;
}
