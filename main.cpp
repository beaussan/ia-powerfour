#include <iostream>
#include <string>
#include "Grid.h"
#include "PowerFour.h"
#include "Colors.h"
#include "Utils.h"
#include "IaPLayer.h"
#include "Player.h"
#include "HumanPlayer.h"

using namespace std;

Player createPlayer(int color, string printedName);

Player createPlayer(int color, string printedName) {
    cout << "What do you want " << printedName << "to be ?" << endl;
    cout << "1) A human player" << endl;
    cout << "2) IA with MinMax algoritm" << endl;
    int choice = getChoice(1,2);

    string name;

    cout << "What name should it be called ?" << endl << "> ";
    cin >> name;

    if (choice == 1) {
        cout << "You created a human player called " << name << "!" << endl;
        return HumanPlayer(color, name);
    } else {
        cout << "You created an IA player  called " << name << "!" << endl;
        return IaPLayer(color, name);
    }
}

int main() {

    Player p1 = createPlayer(BLUE, "the blue player");
    Player p2 = createPlayer(RED, "the red player");

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

    int choiseInit = getChoice(1,3);

    cout << "Choise int : " << choiseInit << endl;

    cout << "if win " << gr->checkIfWin() << " (rapel : Blue : " << BLUE << ", Red : " << RED << ")" << endl;

    gr->play(BLUE, 2);
    gr->print();
    gr->play(BLUE, 4);
    gr->print();

    cout << "if win " << gr->checkIfWin() << " (rapel : Blue : " << BLUE << ", Red : " << RED << ")" << endl;


    return 0;
}