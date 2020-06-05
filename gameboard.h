#ifndef __GAMEBOARD_H__
#define __GAMEBOARD_H__

int checkHorizontal(char game_board[]);
int checkVertical(char game_board[]);
int checkDiagonal(char game_board[]);
int checkDraw(char game_board[]);
int checkVacancies(int i, char game_board[]);
int checkPosition(char board_position[], char game_board[], char symbol, int current_player);
int checkSomeoneWin(char game_board[]);
int isIndexValueSame(char game_board[], int index1, int index2, int index3);
void showBoard(char game_board[]);
void showResult(int game_state, int current_player);

#endif
