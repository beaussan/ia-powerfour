#include <iostream>
#include "Grid.h"
#include "PowerFour.h"
#include "Colors.h"

using namespace std;

int main() {
    Grid g(6, 0);
    cout << g(2, 3) << endl;
    g(2, 3) = -1;
    cout << g(2, 3) << endl;
    cout << "Hello, World!" << endl;

    PowerFour *gr = new PowerFour();
    cout << gr->get(2, 3) << endl;
    gr->play(BLUE, 0);
    gr->play(RED, 0);
    gr->play(RED, 0);
    gr->play(BLUE, 0);
    gr->play(RED, 1);
    gr->play(RED, 1);
    gr->play(BLUE, 1);
    gr->play(RED, 1);
    gr->play(BLUE, 3);
    gr->play(BLUE, 5);
    gr->play(RED, 6);
    gr->print();

    cout << "if win " << gr->checkIfWin() << " (rapel : Blue : " << BLUE << ", Red : " << RED << ")" << endl;

    gr->play(BLUE, 2);
    gr->print();
    gr->play(BLUE, 4);
    gr->print();

    cout << "if win " << gr->checkIfWin() << " (rapel : Blue : " << BLUE << ", Red : " << RED << ")" << endl;


    return 0;
}