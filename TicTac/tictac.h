#include <iostream>
#include <ctime>
#include <algorithm>

#define COMPUTER 1
#define PLAYER 2
#define BOARD_SIZE 3
#define PLAYER_SYM 'X'
#define COMP_SYM 'O'

using std::cout;
using std::cin;
using std::random_shuffle;

#ifndef TICTAC

// FUNCTIONS

void displayBoard(char board[][BOARD_SIZE]);
void showRules();
void initialize(char board[][BOARD_SIZE], int moves[]);
void isWinner(int turnSwap  );
bool rowWin(char board[][BOARD_SIZE]);
bool columnWin(char board[][BOARD_SIZE]);
bool diagonalWin(char board[][BOARD_SIZE]);
bool gameOver(char board[][BOARD_SIZE]);
void gameLoop(int turnSwap);





#endif