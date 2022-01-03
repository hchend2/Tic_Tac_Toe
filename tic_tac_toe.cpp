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

void play() {
    // player1 always goes first...
    string player1 = "Herve ";
    string player2 = "Friend ";
    int count = 0, userInput;
    char player1_play = 'X', player2_play = 'O';
    cout << "  Enter a number between 0 and 8. " << endl;
    while (true) {
        if (count%2 == 0) {
            cout << player1 << " Your turn! "; cin >> userInput;
            if (board[userInput] == player1_play || board[userInput] == player2_play) {
                cout << "  Not valid. Try again..." << endl;
            } else {
                board[userInput] = player1_play;
                count++;
            }
        } else {
            cout << player2 << " Your turn! "; cin >> userInput;
            if (board[userInput] == player1_play || board[userInput] == player2_play) {
                cout << "   Not valid. Try again..." << endl;
            } else {
                board[userInput] = player2_play;
                count++;
            }
        }
        grid();
        cout << "  Enter a number between 0 and 8. " << endl;
    }
}
int main() {
    cout << " Welcome to my Tic Tac Toe game! " << endl;
    cout << endl << " The board! " << endl; 
    grid();
    play();
    return 0;
}