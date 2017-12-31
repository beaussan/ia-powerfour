#include <iostream>
#include <string>
#include "Grid.h"
#include "PowerFour.h"
#include "Colors.h"
#include "Utils.h"
#include "IaPLayer.h"
#include "Player.h"
#include "HumanPlayer.h"

#include <typeinfo>  //for 'typeid' to work

using namespace std;

Player* createPlayer(int color, const string &printedName);

Player* createPlayer(int color, const string &printedName) {
    cout << "What do you want " << printedName << "to be ?" << endl;
    cout << "1) A human player" << endl;
    cout << "2) IA with MinMax algoritm" << endl;
    int choice = getChoice(1, 2);

    string name;

    cout << "What name should it be called ?" << endl << "> ";
    cin >> name;

    if (choice == 1) {
        cout << "You created a human player called " << name << "!" << endl;
        HumanPlayer* human = new HumanPlayer(color, name);
        return human;
    } else {
        cout << "You created an IA player  called " << name << "!" << endl;
        IaPLayer *ia = new IaPLayer(color, name);
        return ia;
    }
}

int main() {

    Player* p1 = createPlayer(BLUE, "the blue player");
    Player* p2 = createPlayer(RED, "the red player");

    int player1Choise = -1;
    int player2Choise = -1;
    int tryes = 0;
    bool isPlayValid = false;

    PowerFour pf;

    do {

        cout << "--------------" << endl;
        cout << "Player " << p1->getName() << " (BLUE) Turn !" << endl << endl;

        pf.print();

        player1Choise = p1->getCoup(pf);
        tryes = 0;
        do {
            tryes++;
            isPlayValid = pf.play(BLUE, player1Choise);
            if (!isPlayValid) {
                cout << "The move is not valid ! :( The column is full, try again" << endl;
                player1Choise = p1->getCoup(pf);
                if (tryes > 5) {
                    cout << "The player " << p2->getName() << " won ! Because the player 1 was dumb." << endl;
                    return 0;
                }
            }
        } while (!isPlayValid);

        if (pf.checkIfWin() != NONE) {
            break;
        }

        cout << "--------------" << endl;
        cout << "Player " << p2->getName() << " (RED) Turn !" << endl;

        pf.print();

        player2Choise = p2->getCoup(pf);
        tryes = 0;
        do {
            tryes++;
            isPlayValid = pf.play(RED, player2Choise);
            if (!isPlayValid) {
                cout << "The move is not valid ! :( The column is full, try again" << endl;
                player2Choise = p2->getCoup(pf);
                if (tryes > 5) {
                    cout << "The player " << p1->getName() << " won ! Because the player 2 was dumb." << endl;
                    return 0;
                }
            }
        } while (!isPlayValid);

    } while (pf.checkIfWin() == NONE);

    return 0;
}