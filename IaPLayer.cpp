//
// Created by beaussan on 14/12/17.
//

#include "IaPLayer.h"
#include "PowerFour.h"

int Player::getCoup(PowerFour grid) {
    return
}

int IaPLayer::min(PowerFour powerFour, int profondeur) {
    PowerFour copy = powerFour;

    if(profondeur == 0 || powerFour.checkIfWin()!=0)
    {
        return eval(powerFour);
    }

    int tmp = 1001;
    int min = 1000;

    for (size_t i = 0; i < WIDTH; ++i) {
        if (!copy.isColumnFull(i)) {
            copy.play(this->player, i);
            tmp = this->max(copy, profondeur-1);
            if (tmp < min) {
                tmp = min;
            }
        };
    }


    return tmp;
}

int IaPLayer::max(PowerFour powerFour, int profondeur) {
    PowerFour copy = powerFour;

    if(profondeur == 0 || powerFour.checkIfWin()!=0)
    {
        return eval(powerFour);
    }

    int tmp = -1001;
    size_t * colonne;
    int max = -1000;

    for(size_t i = 0 ; i < WIDTH ; ++i) {
        if (!copy.isColumnFull(i)) {
            copy.play(this->player, i);
            tmp = this->min(copy, profondeur-1);
            if (tmp > max) {
                tmp = max;
            }
        }

    }

    return tmp;
}

int IaPLayer::eval(PowerFour powerFour) {
    int vainqueur = powerFour.checkIfWin();

    if (vainqueur == this->player) {
        return 1000;
    } else if (vainqueur == (-1) * this->player) {
        return -1000;
    } else {
        return 0;
    }

    return 0;
}

int IaPLayer::getCoup(PowerFour pf) {
    return this->max(pf, DEPTH);
}
