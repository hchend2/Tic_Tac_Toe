#include <iostream>

using std::endl;
using std::cout;

// draw the gameboard...
void grid() {

    int board[9] = {1,2,3,4,5,6,7,8,9};
    cout << "      "<<"________________________    " << endl;
    cout << "      "<<"|      |       |       |    " << endl;
    cout << "      "<<"|  "<<board[0]<<"   |   "<<board[1] << "   |   " << board[2] << "   |   " << endl;
    cout << "      "<<"|______|_______|_______|    " << endl;
    cout << "      "<<"|      |       |       |    " << endl;
    cout << "      "<<"|  "<<board[3]<<"   |   "<<board[4] << "   |   " << board[5] << "   |   " << endl;
    cout << "      "<<"|______|_______|_______|    " << endl;
    cout << "      "<<"|      |       |       |    " << endl;
    cout << "      "<<"|  "<<board[6]<<"   |   "<<board[7] << "   |   " << board[8] << "   |   " << endl;
    cout << "      "<<"|______|_______|_______|    " << endl;
}

void playGame() {
    
}

int main() {
    cout << "Welcome to my Tic Tac Toe game!" << endl;
    cout << endl << " The board! " << endl;
    grid();
    return 0;
}