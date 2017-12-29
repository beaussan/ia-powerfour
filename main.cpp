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

    Player p1 = createPlayer(BLUE, "the blue player");
    Player p2 = createPlayer(RED, "the red player");

    int player1Choise = -1;
    int player2Choise = -1;
    bool isPlayValid = false;

    PowerFour *gr = new PowerFour();

    do{

        cout << "--------------" << endl;
        cout << "Player " << p1.getName() << " (BLUE) Turn !" << endl;

        gr->print();

        player1Choise = p1.getCoup(*gr);
        do {
            isPlayValid = gr->play(BLUE, static_cast<size_t>(player1Choise));
            if (!isPlayValid) {
                cout << "The move is not valid ! :( The column is full, try again" << endl;
                player1Choise = p1.getCoup(*gr);
            }
        } while (!isPlayValid);

        if (gr->checkIfWin() != NONE){
            break;
        }

        cout << "--------------" << endl;
        cout << "Player " << p2.getName() << " (RED) Turn !" << endl;

        gr->print();

        player2Choise = p2.getCoup(*gr);
        do {
            isPlayValid = gr->play(BLUE, static_cast<size_t>(player2Choise));
            if (!isPlayValid) {
                cout << "The move is not valid ! :( The column is full, try again" << endl;
                player2Choise = p2.getCoup(*gr);
            }
        } while (!isPlayValid);

    } while (gr->checkIfWin() == NONE);

    return 0;
}