#ifndef __PLAYWITHCOMPUTER_H__
#define __PLAYWITHCOMPUTER_H__

int checkValueOnComputer(char game_board[], int index1, int index2, int index3, char symbol);
int checkCaseOnComputer(char game_board[], int index1, int index2, int index3, char symbol);
int checkComputer(char game_board[], char computer_symbol, char player_symbol);
int findBlankForComputer(char game_board[], char computer_symbol, char player_symbol);
void playWithComputer(void);

#endif
