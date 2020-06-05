#ifndef __GAMESETTING_H__
#define __GAMESETTING_H__

void checkTurn(int current_player);
char checkSymbol(int current_player);
int changePlayer(int current_player);
void chooseSymbol(void);
int isRightInput(char* player_symbol, char* capital_letter, char* small_letter);
int setSymbol(char* player1_symbol);

#endif
