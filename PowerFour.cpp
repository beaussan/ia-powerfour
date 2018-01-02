//
// Created by beaussan on 21/10/17.
//

#include "PowerFour.h"
#include "Colors.h"
#include <cassert>
#include <iostream>
#include <stdlib.h>

using namespace std;

PowerFour::PowerFour() : grid_(WIDTH + 1, NONE) {
}

PowerFour::~PowerFour() {
}

int PowerFour::get(size_t c, size_t l) {
    int res = grid_(c, l);
    return res;
}

/**
 * Play a step of the game
 * @param player the value to set
 * @param column the column to play (0 to WITH -1)
 * @return true if everything is ok, false if the move was wrong
 */
bool PowerFour::play(int player, int column) {

    assert(0 <= column && column < WIDTH);

    for (size_t l = 0; l < HEIGHT; ++l) {
        if (this->get((size_t) column, l) == NONE) {
            this->grid_((size_t) column, l) = player;
            return true;
        }
    }
    return false;
}

#ifdef _WIN32
void PowerFour::print() {
    cout << "Where X is Red and O is Blue" << endl;
    for (size_t line = HEIGHT; line > 0; line--) {
        cout << "|";
        for (size_t column = 0; column < WIDTH; ++column) {
            int val = this->grid_(column, line-1);
            if (val == NONE) {
                cout << " ";
            } else if (val == BLUE) {
                cout << 'O';
            } else if (val == RED) {
                cout << 'X';
            }
            cout << "|";
        }
        cout << endl;
    }
    cout << "+-+-+-+-+-+-+-+" << endl;
    cout << " 1 2 3 4 5 6 7 " << endl << endl;

}
#else

void PowerFour::print() {
    for (size_t line = HEIGHT; line > 0; line--) {
        cout << "|";
        for (size_t column = 0; column < WIDTH; ++column) {
            int val = this->grid_(column, line - 1);
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

#endif

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
    for (size_t column = 0; column < WIDTH; ++column) {
        for (size_t line = 0; line < 3; line++) {
            int somme = this->grid_(column, line)
                        + this->grid_(column, line + 1)
                        + this->grid_(column, line + 2)
                        + this->grid_(column, line + 3);

            if (somme == RED * 4) {
                return RED;
            } else if (somme == BLUE * 4) {
                return BLUE;
            }
        }
    }


    return NONE;
}

int PowerFour::checkLines() {
    for (size_t line = HEIGHT; line > 0; line--) {
        for (size_t column = 0; column <= WIDTH - 4; ++column) {
            int somme = this->grid_(column, line - 1)
                        + this->grid_(column + 1, line - 1)
                        + this->grid_(column + 2, line - 1)
                        + this->grid_(column + 3, line - 1);

            if (somme == RED * 4) {
                return RED;
            } else if (somme == BLUE * 4) {
                return BLUE;
            }
        }
    }
    return NONE;
}

int PowerFour::checkDiagonals() {

    // check right diagonals

    for (size_t line = 0; line < HEIGHT - 3; ++line) {
        for (size_t column = 0; column < WIDTH - 3; ++column) {
            int somme = this->grid_(column, line)
                        + this->grid_(column + 1, line + 1)
                        + this->grid_(column + 2, line + 2)
                        + this->grid_(column + 3, line + 3);

            if (somme == RED * 4) {
                return RED;
            } else if (somme == BLUE * 4) {
                return BLUE;
            }
        }
    }

    // check left diagonals

    for (size_t line = 0; line < HEIGHT - 3; ++line) {
        for (size_t column = 3; column < WIDTH; ++column) {
            int somme = this->grid_(column, line)
                        + this->grid_(column - 1, line + 1)
                        + this->grid_(column - 2, line + 2)
                        + this->grid_(column - 3, line + 3);

            if (somme == RED * 4) {
                return RED;
            } else if (somme == BLUE * 4) {
                return BLUE;
            }
        }
    }


    return NONE;
}

bool PowerFour::isColumnFull(size_t column) {
    return this->grid_(column, WIDTH - 2) != NONE;
}

bool PowerFour::isGameTie() {
    return isColumnFull(0)
           && isColumnFull(1)
           && isColumnFull(2)
           && isColumnFull(3)
           && isColumnFull(4)
           && isColumnFull(5)
           && isColumnFull(6)
           && isColumnFull(7);
}


int PowerFour::score(int player, PowerFour grille) {
    int points, vertical_points, horizontal_points, diagonal_points1, diagonal_points2;

    // vertical points

    vertical_points = 0;
    for (size_t column = 0; column < WIDTH; ++column) {
        int count = 0;
        int score = 0;
        while (this->checkIfWin() != player || count < 4) {
            grille.play(player, (int) column);
            count++;
        }

        if (this->checkIfWin() == player) {
            if (count == 1) {
                score += 1000;
            } else if (count == 2) {
                score += 100;
            } else if (count == 3) {
                score += 10;
            }
        }
        vertical_points += score;
    }

    // horizontal points

//    horizontal_points = 0;
//    for (size_t column = 0; column < WIDTH; ++column) {
//        int count = 0;
//        int score = 0;
//        while (this->checkIfWin() != player || count < 4) {
//            this->play(player, (int) column);
//            count++;
//        }
//
//        if (this->checkIfWin() == player) {
//            if (count == 1) {
//                score += 1000;
//            } else if (count == 2) {
//                score += 100;
//            } else if (count == 3) {
//                score += 10;
//            }
//        }
//        vertical_points += score;
//    }


    points = vertical_points + rand();

    return points;

}


