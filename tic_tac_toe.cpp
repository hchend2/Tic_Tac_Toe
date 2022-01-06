/* ***************Herve Chendjou**************** */

#include <iostream>

using std::endl;
using std::cout;
using std::cin;
using std::string;

/* draw the gameboard of size 9... */
const int size = 9;
char board[size] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
void grid() {
    cout << "      " << "________________________    " << endl;
    cout << "      " << "|      |       |       |    " << endl;
    cout << "      " << "|  " << board[0] << "   |   " << board[1] << "   |   " << board[2] << "   |   " << endl;
    cout << "      " << "|______|_______|_______|    " << endl;
    cout << "      " << "|      |       |       |    " << endl;
    cout << "      " << "|  " << board[3] << "   |   " << board[4] << "   |   " << board[5] << "   |   " << endl;
    cout << "      " << "|______|_______|_______|    " << endl;
    cout << "      " << "|      |       |       |    " << endl;
    cout << "      " << "|  " << board[6] << "   |   " << board[7] << "   |   " << board[8] << "   |   " << endl;
    cout << "      " << "|______|_______|_______|    " << endl;
}

/* check for matches on the horizontal */
int checkHorizontal() {

    if (board[0] == 'O' && board[1] == 'O' && board[2] == 'O') {
            return 2;
    }
    if (board[0] == 'X' && board[1] == 'X' && board[2] == 'X') {
        return 1;
    }
    if (board[3] == 'O' && board[4] == 'O' && board[5] == 'O') {
            return 2;
    }
    if (board[3] == 'X' && board[4] == 'X' && board[5] == 'X') {
        return 1;
    }
    if (board[6] == 'O' && board[7] == 'O' && board[8] == 'O') {
            return 2;
    }
    if (board[6] == 'X' && board[7] == 'X' && board[8] == 'X') {
        return 1;
    }
    return 0;
}

/* check for matches on the vertical */
int checkVertical() {
    if (board[0] == 'O' && board[3] == 'O' && board[6] == 'O') {
            return 2;
    }
    if (board[0] == 'X' && board[3] == 'X' && board[6] == 'X') {
        return 1;
    }
    if (board[1] == 'O' && board[4] == 'O' && board[7] == 'O') {
            return 2;
    }
    if (board[1] == 'X' && board[4] == 'X' && board[7] == 'X') {
        return 1;
    }
    if (board[2] == 'O' && board[5] == 'O' && board[8] == 'O') {
            return 2;
    }
    if (board[2] == 'X' && board[5] == 'X' && board[8] == 'X') {
        return 1;
    }
    return 0;
}

/* chek if there are matches on the left and right diagonal */
int checkDiagonal() {
    if (board[0] == 'O' && board[4] == 'O' && board[8] == 'O') {
            return 2;
    }
    if (board[0] == 'X' && board[4] == 'X' && board[8] == 'X') {
        return 1;
    }
    if (board[2] == 'O' && board[4] == 'O' && board[6] == 'O') {
            return 2;
    }
    if (board[2] == 'X' && board[4] == 'X' && board[6] == 'X') {
        return 1;
    }
    return 0;
}

/* check if the board cells are all checked */
bool checkedBoard() {
    for (int i = 0; i < size; i++) {
        if (isdigit(board[i])) {
            return false; // not all checked...
        }
    }
    return true; // all checked...
}

/* if there is a winner, then game is over and return the winner... */
int isGameOver() {
    
    if (checkHorizontal() == 1 || checkVertical() == 1 || checkDiagonal() == 1) {
        return 1; // there is a winner...
    } else if (checkHorizontal() == 2 || checkVertical() == 2 || checkDiagonal() == 2) {
        return 2; // there is a winner...
    }
    return 0; //
}

/* display who won the game when it is over...or game is tie... */
void the_winner_Is(string p1, string p2) {

    if (isGameOver() == 1) {
        cout << endl << "   Game Over" << endl;
        cout <<"    "<< p1 << " Won!" << endl;
    } else if ( isGameOver() == 2) {
        cout << endl << "   Game Over" << endl;
        cout <<"     "<<p2 << " Won!" << endl;
    } 
}

/* this function allows us to play the game */
void play() {

    string player1 = "Herve ";
    string player2 = "Friend ";
    int count = 0, userInput;
    char player1_play = 'X', player2_play = 'O';

    cout << endl << "   Enter a number between 1 and 9. " << endl;
    while (!isGameOver()) {
        if (count%2 == 0) {
            cout << "   " << player1 << " Your turn! "; cin >> userInput;
            if (userInput > 8 || userInput < 0) {
                cout << "    Out of range... Try again" << endl;
            } else if (board[userInput] == player1_play || board[userInput] == player2_play) {
                cout << "    Not valid. Try again..." << endl;
            } else {
                board[userInput] = player1_play; // player1 always goes first...
                count++;
            }
        } else {
            cout << "   " <<  player2 << " Your turn! "; cin >> userInput;
            if (userInput > 8 || userInput < 0) {
                cout << "    Out of range... Try again" << endl;
            } else if (board[userInput] == player1_play || board[userInput] == player2_play) {
                cout << "    Not valid. Try again..." << endl;
            } else {
                board[userInput] = player2_play;
                count++;
            }
        }
        grid();
        the_winner_Is(player1, player2);
        if (checkedBoard()) {
            cout << endl << "   Game Over" << endl;
            cout << "    Game is Tie" << endl;
            break;
        }
        if (isGameOver() == 0) {
            cout << endl << "   Enter a number between 1 and 9. " << endl;
        }
    }
}

int main() {
    cout << endl << "   Welcome to my Tic Tac Toe game! " << endl;
    cout << endl << "   The board! " << endl; 
    grid();
    play();
    return 0;
}
/* ********************************END HERE******************************** */