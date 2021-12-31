#include <iostream>

using std::endl;
using std::cout;

// draw the gameboard...
void grid() {

    cout << "       ________________________    " << endl;
    cout << "       |      |       |       |    " << endl;
    cout << "       |      |       |       |    " << endl;
    cout << "       |______|_______|_______|    " << endl;
    cout << "       |      |       |       |    " << endl;
    cout << "       |      |       |       |    " << endl;
    cout << "       |______|_______|_______|    " << endl;
    cout << "       |      |       |       |    " << endl;
    cout << "       |      |       |       |    " << endl;
    cout << "       |______|_______|_______|    " << endl;
}

int main() {
    cout << "Welcome to my Tic Tac Toe game!" << endl;
    cout << endl << " The board! " << endl;
    grid();
    return 0;
}