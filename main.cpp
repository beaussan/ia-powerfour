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

Player createPlayer(int color, const string &printedName);

Player createPlayer(int color, const string &printedName) {
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

    // Player p1 = createPlayer(BLUE, "the blue player");
    // Player p2 = createPlayer(RED, "the red player");

    PowerFour gr = PowerFour();

    IaPLayer ia1 = IaPLayer(RED, "toto");
    IaPLayer ia2 = IaPLayer(BLUE, "tata");

    while (!gr.checkIfWin()) {
        gr.play(ia1.getPlayer(),(size_t) ia1.getCoup(gr));
        gr.print();
        gr.play(ia2.getPlayer(),(size_t) ia2.getCoup(gr));
    }

    gr.checkIfWin();


//    cout << gr->get(2, 3) << endl;
//    gr->play(BLUE, 0);
//    gr->play(RED, 0);
//    gr->play(RED, 0);
//    gr->play(BLUE, 0);
//    gr->play(RED, 1);
//    gr->play(RED, 1);
//    gr->play(BLUE, 1);
//    gr->play(RED, 1);
//    gr->play(BLUE, 3);
//    gr->play(BLUE, 5);
//    gr->play(RED, 6);
//    gr->print();
//
//
//    cout << "if win " << gr->checkIfWin() << " (rapel : Blue : " << BLUE << ", Red : " << RED << ")" << endl;
//
//    gr->play(BLUE, 2);
//    gr->play(BLUE, 2);
//    gr->play(BLUE, 2);
//    gr->play(BLUE, 2);
//    cout << "playing mass blue on 2 " << gr->isColumnFull(2) <<  endl;
//    gr->play(BLUE, 2);
//    if (gr->isColumnFull(2)) {
//        cout << "Column is full :D " << endl;
//    }
//
//    cout << "playing mass blue on 2 " << gr->isColumnFull(2) <<  endl;
//    gr->play(BLUE, 2);
//    cout << "playing mass blue on 2 " << gr->isColumnFull(2) <<  endl;
//    if (gr->isColumnFull(2)) {
//        cout << "Column is full :D " << endl;
//    }
//    gr->print();
//    gr->play(BLUE, 4);
//    gr->print();
//
//    cout << "if win " << gr->checkIfWin() << " (rapel : Blue : " << BLUE << ", Red : " << RED << ")" << endl;
//
//    string tmp;
//
//    cin >> tmp;

    return 0;
}