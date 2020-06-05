/*
This code has been compiled in Code::Blocks 16.01 IDE on Windows 10
Author:- Mishal Shah
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include "declaration.h"
#include "leaderboard.h"
#include "ui.h"
#include "playwithfriend.h"
#include "playwithcomputer.h"
#include "gameboard.h"
#include "gamesetting.h"
#pragma warning (disable:4996)
#define _CRT_SECURE_NO_WARNINGS

const int player1_turn = 1;
const int player2_turn = 2;
const int success=1;
const int failure=0;
Player_Info player1 = {'\0','\0'};
Player_Info player2 = { '\0','\0' };

int main(void)
{

	startTicTacToe();
}
