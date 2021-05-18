#include "tictac.h"

/**
 * @brief displays the board for the game
 * 
 * @param board 
 */
void displayBoard(char board[][BOARD_SIZE])
{
    printf("\n\n");
      
    printf("\t\t\t  %c | %c  | %c  \n", board[0][0],
                             board[0][1], board[0][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n", board[1][0],
                             board[1][1], board[1][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n\n", board[2][0],
                             board[2][1], board[2][2]);
}

/**
 * @brief displays the rules
 * 
 */
void showRules()
{
    cout << "\t\t\t Tic-Tac-Toe\n\n";
    cout << "Choose a number on the board from 1 - 9 to play\n";
    cout << "\t\t\t 1 | 2 | 3 \n";
    cout << "\t\t\t-----------\n";
    cout << "\t\t\t 4 | 5 | 6 \n";
    cout << "\t\t\t-----------\n";
    cout << "\t\t\t 7 | 8 | 9 \n\n";
    cout << "-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n";
}

/**
 * @brief prepares the game board to be played
 * 
 * @param board 
 */
void initialize(char board[][BOARD_SIZE], int moves[])
{
    srand(time(NULL));

    // intialize board as empty
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = ' ';
        }
    }

    // fill each move with the numbers
    for (int i = 0; i< BOARD_SIZE * BOARD_SIZE; i++)
    {
        moves[i] = i;
    }

    // randomize all moves
    random_shuffle(moves, moves + BOARD_SIZE * BOARD_SIZE);
}

/**
 * @brief checks to see if a win conditions is met by either the player or CPU.
 * 
 * @param turnSwap 
 */
void isWinner(int turnSwap)
{
    if (turnSwap == COMPUTER)
        cout << " YOU LOSE!\n";
    else
        cout << " YOU WIN!\n";
}

/**
 * @brief checks to see if there is a win based on the row
 * 
 * @param board 
 * @return true 
 * @return false 
 */
bool rowWin(char board[][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if(board[i][0] == board[i][1] && 
           board[i][1] == board[i][2] &&
           board[i][0] != ' ')
           return(true);
    }
    return(false);
}

/**
 * @brief checks for a column win 
 * 
 * @param board 
 * @return true 
 * @return false 
 */
bool columnWin(char board[][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i] && 
            board[0][i] != ' ')
            return (true);
    }
    return(false);
}

/**
 * @brief checks for a diagonal win
 * 
 * @param board 
 * @return true 
 * @return false 
 */
bool diagonalWin(char board[][BOARD_SIZE])
{
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2] &&
        board[0][0] != ' ')
        return (true);

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0] &&
        board[0][2] != ' ')
        return (true);

    return (false);
}

/**
 * @brief checks to see if the game is over
 * 
 * @param board 
 * @param moves 
 * @return true 
 * @return false 
 */
bool gameOver(char board[][BOARD_SIZE])
{
    return(diagonalWin(board) || columnWin(board) 
        || rowWin(board));
}

/**
 * @brief handles the game loop and the interaction between the CPU and Player for a win or loss
 * 
 * @param turnSwap 
 */
void gameLoop(int turnSwap)
{
    // A 3*3 Tic-Tac-Toe board for playing 
    char board[BOARD_SIZE][BOARD_SIZE];
      
    int moves[BOARD_SIZE*BOARD_SIZE];
      
    // Initialise the game
    initialize(board, moves);
      
    // Show the instructions before playing
    showRules();
      
    int moveIndex = 0, x, y;
      
    // Keep playing till the game is over or it is a draw
    while (gameOver(board) == false && 
            moveIndex != BOARD_SIZE*BOARD_SIZE)
    {
        if (turnSwap == COMPUTER)
        {
            x = moves[moveIndex] / BOARD_SIZE;
            y = moves[moveIndex] % BOARD_SIZE;
            board[x][y] = COMP_SYM;
            printf(" COMPUTER has put a %c in cell %d\n",
                    COMP_SYM, moves[moveIndex]+1);
            displayBoard(board);
            moveIndex ++;
            turnSwap = PLAYER;
        }
          
        else if (turnSwap == PLAYER)
        {
            x = moves[moveIndex] / BOARD_SIZE;
            y = moves[moveIndex] % BOARD_SIZE;
            board[x][y] = PLAYER_SYM;
            printf (" PLAYER has put a %c in cell %d\n",
                    PLAYER_SYM, moves[moveIndex]+1);
            displayBoard(board);
            moveIndex ++;
            turnSwap = COMPUTER;
        }
    }
  
    // If the game has drawn
    if (gameOver(board) == false && 
            moveIndex == BOARD_SIZE * BOARD_SIZE)
        printf(" It's a draw\n");
    else
    {
        // Toggling the user to declare the actual
        // winner
        if (turnSwap == COMPUTER)
            turnSwap = PLAYER;
        else if (turnSwap == PLAYER)
            turnSwap = COMPUTER;
          
        // Declare the winner
        isWinner(turnSwap);
    }
    return;
}