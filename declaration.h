#ifndef __DECLARATION_H__
#define __DECLARATION_H__

typedef struct player_information
{
	char symbol;
	char name[11];
}Player_Info;

extern Player_Info player1;
extern Player_Info player2;

extern const int success;
extern const int failure;
extern const int player1_turn;
extern const int player2_turn;

#endif
