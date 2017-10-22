//
// Created by beaussan on 21/10/17.
//

#include "PowerFour.h"
#include "Colors.h"
#include <cassert>
#include <iostream>

using namespace std;

PowerFour::PowerFour() {
    this->grid_ = new Grid(WIDTH+1, NONE);
}

PowerFour::~PowerFour() {
    delete grid_;
}

int PowerFour::get(size_t c, size_t l) {
    return grid_->operator()(c, l);
}

/**
 * Play a step of the game
 * @param player the value to set
 * @param column the column to play (0 to WITH -1)
 * @return 0 if everything is ok, 1 if the move was wrong
 */
int PowerFour::play(int player, size_t column) {
    assert(0 <= column && column < WIDTH);

    for (size_t l = 0; l <= HEIGHT; ++l) {
        if (this->get(column, l) == NONE) {
            this->grid_->operator()(column, l) = player;
            return 0;
        }
    }
    return 1;
}

void PowerFour::print() {
    for (size_t line = HEIGHT; line > 0; line--) {
        cout << "|";
        for (size_t column = 0; column < WIDTH; ++column) {
            int val = this->grid_->operator()(column, line-1);
            if (val == NONE) {
                cout << " ";
            } else if (val == BLUE) {
                cout << BLUE_TEXT << 'o' << RESET_TEXT;
            } else if (val == RED) {
                cout << RED_TEXT << 'o' << RESET_TEXT;
            }
            cout << "|";
        }
        cout << endl;
    }
    cout << "+-+-+-+-+-+-+-+" << endl;
    cout << " 1 2 3 4 5 6 7 " << endl << endl;

}

/**
 * Check if somebody win the game
 * @return 0 if none win, else return BLUE or RED
 */
int PowerFour::checkIfWin() {
    int result;

    result = this->checkColumn();
    if (result != NONE) {
        return result;
    }

    result = this->checkLines();
    if (result != NONE) {
        return result;
    }

    result = this->checkDiagonals();
    if (result != NONE) {
        return result;
    }

    return NONE;
}

int PowerFour::checkColumn() {

    return NONE;
}

int PowerFour::checkLines() {
    for (size_t line = HEIGHT; line > 0; line--) {
        for (size_t column = 0; column < WIDTH-4; ++column) {
            int somme = this->grid_->operator()(column, line-1)
            + this->grid_->operator()(column+1, line-1)
            + this->grid_->operator()(column+2, line-1)
            + this->grid_->operator()(column+3, line-1);

            if (somme == RED*4) {
                return RED;
            } else if (somme == BLUE*4) {
                return BLUE;
            }
        }
    }
    return NONE;
}

int PowerFour::checkDiagonals() {
    return NONE;
}


