#include <iostream>

using std::endl;
using std::cout;
using std::cin;
using std::string;

// draw the gameboard...
char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
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

int checkWinner() {

    for (int i = 0; i < 9; i++) {
        if (i == 0 && board[i] == 'O' && board[i + 4] == 'O' && board[i + 8] == 'O') {
            return 2;
        }
        if (i == 0 && board[i] == 'X' && board[i + 4] == 'X' && board[i + 8] == 'X') {
            return 1;
        }
        if (i <= 2 && board[i] == 'O' && board[i + 3] == 'O' && board[i + 6] == 'O') {
            return 2;
        }
        if (i <= 2 && board[i] == 'O' && board[i + 3] == 'O' && board[i + 6] == 'O') {
            return 2;
        }
        if (i <= 2 && board[i] == 'X' && board[i + 3] == 'X' && board[i + 6] == 'X') {
            return 1;
        }
        if (i <= 6 && board[i] == 'O' && board[i + 1] == 'O' && board[i + 2] == 'O') {
            return 2;
        }
        if (i <= 6 && board[i] == 'X' && board[i + 1] == 'X' && board[i + 2] == 'X') {
            return 1;
        }
    }
    return 0;
}

bool isGameOver() {
    
    int count = 0;
    for (int x = 0; x < 9; x++) {
        if (board[x] == 'X' || board[x] == 'O') {
            count++;
        }
        if (count == 8 || checkWinner() == 1 || checkWinner() == 2) {
            return true;
        }
    }
    return false;
}

void the_winner_Is(string p1, string p2) {
    if (checkWinner() == 1) {
        cout << p1 << " Won!" << endl;
    } else if ( checkWinner() == 2 ) {
        cout << p2 << " Won!" << endl;
    } else {
        cout << "   Game is Tie..." << endl;
    }
}

void play() {
    // player1 always goes first...

    string player1 = "Herve ";
    string player2 = "Friend ";
    int count = 0, userInput;
    char player1_play = 'X', player2_play = 'O';

    cout << endl << "   Enter a number between 0 and 8. " << endl;
    while (true) {
        if (count%2 == 0) {
            cout << "   " << player1 << " Your turn! "; cin >> userInput;
            if (board[userInput] == player1_play || board[userInput] == player2_play) {
                cout << "  Not valid. Try again..." << endl;
            } else {
                board[userInput] = player1_play;
                count++;
            }
        } else {
            cout << "   " <<  player2 << " Your turn! "; cin >> userInput;
            if (board[userInput] == player1_play || board[userInput] == player2_play) {
                cout << "   Not valid. Try again..." << endl;
            } else {
                board[userInput] = player2_play;
                count++;
            }
        }
        grid();
        cout << endl << "   Enter a number between 0 and 8. " << endl;
    }
}
int main() {
    cout << " Welcome to my Tic Tac Toe game! " << endl;
    cout << endl << " The board! " << endl; 
    grid();
    play();
    return 0;
}