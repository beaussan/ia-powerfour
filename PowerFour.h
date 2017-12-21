//
// Created by beaussan on 21/10/17.
//

#ifndef POWERFOUR_POWERFOUR_H
#define POWERFOUR_POWERFOUR_H

#include "Grid.h"

#define BLUE (-1)
#define RED 1
#define NONE 0
#define HEIGHT 6
#define WIDTH 7

class PowerFour {
    Grid *grid_;
    int checkColumn();
    int checkLines();
    int checkDiagonals();

public:
    PowerFour();
    ~PowerFour();

    int get(size_t c, size_t l);

    bool play(int player, size_t column);

    bool isColumnFull(size_t column);

    void print();

    int checkIfWin();


};

#endif //POWERFOUR_POWERFOUR_H
