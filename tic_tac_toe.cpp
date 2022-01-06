#include <iostream>

using std::endl;
using std::cout;
using std::cin;
using std::string;

// draw the gameboard...
const int size = 9;
char board[size] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
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


int checkHorrizontal() {

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

bool checkedBoard() {
    for (int i = 0; i < size; i++) {
        if (isdigit(board[i])) {
            return false; // not all checked...
        }
    }
    return true; // all checked...
}

bool isGameOver() {
    
    if (!checkedBoard || checkHorrizontal() == 1 || checkVertical() == 1 || checkDiagonal() == 1 ||
        checkHorrizontal() == 2 || checkVertical() == 2 || checkDiagonal() == 1) {
        return true; // all checked...or there is a winner...
    }
    return false; // no winner... or not all checked...
}


void the_winner_Is(string p1, string p2) {

    if (isGameOver()) {
        cout << endl << "   Game Over" << endl;
        if (checkHorrizontal() == 1 || checkVertical() == 1 || checkDiagonal() == 1) {
            cout <<"    "<< p1 << " Won!" << endl;
        } else if ( checkHorrizontal() == 2 || checkVertical() == 2 || checkDiagonal() == 2) {
            cout <<"     "<<p2 << " Won!" << endl;
        } else {
            cout << "   Game is Tie..." << endl;
        }
    }
    return;
}

void play() {
    // player1 always goes first...

    string player1 = "Herve ";
    string player2 = "Friend ";
    int count = 0, userInput;
    char player1_play = 'X', player2_play = 'O';

    cout << endl << "   Enter a number between 0 and 8. " << endl;
    while (!isGameOver()) {
        if (count%2 == 0) {
            cout << "   " << player1 << " Your turn! "; cin >> userInput;
            if (userInput > 8 || userInput < 0) {
                cout << "    Out of range... Try again" << endl;
            } else if (board[userInput] == player1_play || board[userInput] == player2_play) {
                cout << "    Not valid. Try again..." << endl;
            } else {
                board[userInput] = player1_play;
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
        if (!isGameOver()) {
            cout << endl << "   Enter a number between 0 and 8. " << endl;
        }
    }
}

int main() {
    cout << "   Welcome to my Tic Tac Toe game! " << endl;
    cout << endl << "   The board! " << endl; 
    grid();
    play();
    return 0;
}