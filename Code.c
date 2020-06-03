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
void chooseSymbol(void);
int checkHorizontal(char game_board[]);
int checkVertical(char game_board[]);
int checkDiagonal(char game_board[]);
int checkDraw(char game_board[]);
void showBoard(char game_board[]);
void enterName(void);
int changePlayer(int current_player);
void showResult(FILE* leaderboard, int game_state, int current_player);
int checkSomeoneWin(char game_board[]);
void playWithFriend(void);
void showLeaderBoard(void);


void quit(void);
int checkPosition(char board_position[], char board_symbol[], char symbol, int current_player);
int checkVacancies(int i, char board_symbol[]);
void checkTurn(int current_player);
char checkSymbol(int current_player);
void checkFile(FILE* file);

int checkValueOnComputer(char game_board[], int index1, int index2, int index3, char symbol);
int checkCaseOnComputer(char game_board[], int index1, int index2, int index3, char symbol);
int checkComputer(char game_board[], char computer_symbol, char player_symbol);
int findBlankForComputer(char game_board[], char computer_symbol, char player_symbol);
void playWithComputer(void);
int checkposition2(char board_position[], char board_symbol[], char symbol, int current_player);
int setSymbol(char* player1_symbol);
int isRight(char* player_symbol, char* capital_letter, char* small_letter);
int isIndexValueSame(char game_board[], int index1, int index2, int index3);

Player_Info player1 = { '\0','\0' };
Player_Info player2 = { '\0','\0' };
const int player1_turn = 1;
const int player2_turn = 2;

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
void showResult(FILE* leaderboard, int game_state, int current_player)
{
	const int someone_win = 1;
	if (game_state == someone_win)
	{
		if (current_player == player2_turn)
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
		fprintf(leaderboard, "%s\t%s\t%s\n", player1.name, player2.name, "DRAW");
		fclose(leaderboard);
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

int checkHorizontal(char game_board[])
{
	const int horizontal_complete = 1;
	const int horizontal_fail = 0;

	if (isIndexValueSame(game_board, 0, 1, 2))
	{
		return horizontal_complete;
	}
	else if (isIndexValueSame(game_board, 3, 4, 5))
	{
		return horizontal_complete;
	}
	else if (isIndexValueSame(game_board, 6, 7, 8))
	{
		return horizontal_complete;
	}
	else
		return horizontal_fail;
}

int checkVertical(char game_board[])
{
	const int vertical_complete = 1;
	const int vertical_fail = 0;

	if (isIndexValueSame(game_board, 0, 3, 6))
	{
		return vertical_complete;
	}
	else if (isIndexValueSame(game_board, 1, 4, 7))
	{
		return vertical_complete;
	}
	else if (isIndexValueSame(game_board, 2, 5, 8))
	{
		return vertical_complete;
	}
	else
		return vertical_fail;
}

int checkDiagonal(char game_board[])
{
	const int diagonal_complete = 1;
	const int diagonal_fail = 0;

	if (isIndexValueSame(game_board, 0, 4, 8))
	{
		return diagonal_complete;
	}
	else if (isIndexValueSame(game_board, 2, 4, 6))
	{
		return diagonal_complete;
	}
	else
		return diagonal_fail;
}

int checkDraw(char game_board[])
{
	const int draw_complete = 1;
	const int draw_fail = 0;
	for (int i = 0; i < 9; i++)
	{
		if (game_board[i] == i + '1')
		{
			return draw_fail;
		}
	}
	return draw_complete;

}

void showLeaderBoard(void) {
	char c = '\0';
	int insert_error = 1;

	system("cls");
	printf("\n\n");
	printf("\tLEADERBOARD\n\n");
	printf("-------------------------\n");
	printf("Player1\t|Player2|Winner|\n");
	printf("-------------------------\n");

	FILE* leaderboard = fopen("leaderboard.txt", "r");
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
	if (strcmp(player1.name, "\0") == 0)
		printf("Player:- (0)\nComputer:-  (X)\n\n\n");
	else
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

void chooseSymbol(void)
{
	char dec[10];
	int insert_error = 1;
	int right_input;
	
	printf("\n\nPlayer1 %s choose the X or O:", player1.name);

	while (insert_error) {
		scanf("%s", dec);
		right_input = setSymbol(dec);
		if(right_input)
		{
			insert_error = 0;
		}
		else
		{
			printf("Please enter either X or O only \n\n");
		}
	}
}

int isRight(char* player_symbol, char* capital_letter, char* small_letter)
{
	int string_same;

	string_same = strcmp(player_symbol, capital_letter);
	if (string_same == 0)
	{
		return 1;
	}

	string_same = strcmp(player_symbol, small_letter);
	if (string_same == 0)
	{
		return 1;
	}

	return 0;
}

int setSymbol(char* player1_symbol)
{
	int is_player_symbol;
	const int complete = 1;
	const int fail = 0;
	
	is_player_symbol = isRight(player1_symbol, "X", "x");
	if(is_player_symbol)
	{
		player1.symbol = 'X';
		player2.symbol = 'O';
		return complete;
	}

	is_player_symbol = isRight(player1_symbol, "O", "o");
	if (is_player_symbol)
	{
		player1.symbol = 'O';
		player2.symbol = 'X';
		return complete;
	}

	return fail;
}

void enterName(void)
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

void playWithFriend(void) {
	const int keepGoing = 0;
	int game_state = 0;

	char board_symbol[9] = { '1','2','3','4','5','6','7','8','9' };
	char board_position[100];
	char check_position[9][2] = { "1","2","3","4","5","6","7","8","9" };
	char symbol;
	int current_player = 1;
	FILE* leaderboard = fopen("leaderboard.txt", "a+");

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
	showResult(leaderboard, game_state, current_player);
	fclose(leaderboard);
}

int checkPosition(char board_position[], char board_symbol[], char symbol, int current_player) {

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
	const int not_vacancy = 0;

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
			playWithComputer();
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


int checkValueOnComputer(char game_board[], int index1, int index2, int index3, char symbol)
{
	if (game_board[index1] == symbol && game_board[index2] == symbol)
	{
		//\BEƷ\A1\C0\C7 'o'\BF\CD 'x'\B8\A6 \C4\C4ǻ\C5\CD\C0\C7 \B1\E2ȣ\BF\CD \C7÷\B9\C0̾\EE\C0\C7 \B1\E2ȣ\B7\CE \B9ٲ\E3\C1ּ\BC\BF\E4
		if (game_board[index3] != 'o' && game_board[index3] != 'x')
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
	char player_symbol = 'o';
	char computer_symbol = 'x';


	system("color fc");

	showBoard(board_symbol);
	while (game_state == keepGoing)
	{

		if (current_player == player1_turn)
		{
			symbol = player_symbol;
		}
		else
		{
			symbol = computer_symbol;
		}

		if (current_player == player1_turn)
		{
			printf("Type any digit from 1-9 to fill your response:- ");
			scanf("%s", board_position);
			current_player = checkposition2(board_position, board_symbol, player_symbol, current_player);

		}
		else
		{
			computer = checkComputer(board_symbol, computer_symbol, player_symbol);
			if (!computer)
			{
				computer = findBlankForComputer(board_symbol, computer_symbol, player_symbol);
			}
			board_symbol[computer] = symbol;
			printf("Computer select %d\n", computer + 1);
			Sleep(1000);
			current_player = checkposition2(board_position, board_symbol, player_symbol, current_player);

		}

		game_state = checkSomeoneWin(board_symbol);
		//current_player++;
		showBoard(board_symbol);
	}
	//showResult(leaderboard, game_state, current_player);
	if (game_state == someoneWin)
	{
		printf("\n\nSomeone Wins!\n\n");
	}
	else
	{
		printf("\n\nGame Draws!\n\n");
	}

	//fclose(leaderboard);
}

int checkposition2(char board_position[], char board_symbol[], char symbol, int current_player) {

	char check_position[9][2] = { "1","2","3","4","5","6","7","8","9" };
	int flag = 1;

	if (current_player == 2)
		return flag;

	for (int i = 0; i < 9; i++)
	{
		if (strcmp(check_position[i], board_position) == 0)
		{
			flag = 2;
			if (checkVacancies(i, board_symbol))
			{
				board_symbol[i] = symbol;
				//current_player = changePlayer(current_player);
				break;
			}
			else
			{
				printf("Wrong Selection\n");
				Sleep(1000);
			}
		}
	}
	if (flag == 1) {
		printf("Wrong Selection\n");
		Sleep(1000);
	}
	return flag;

}
