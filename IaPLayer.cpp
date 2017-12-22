//
// Created by beaussan on 14/12/17.
//
#include "IaPLayer.h"
#include "PowerFour.h"
#include <vector>

vector<int> IaPLayer::min(PowerFour powerFour, int profondeur) {
    PowerFour copy = powerFour;

    if(profondeur == 0 || powerFour.checkIfWin()!=0)
    {
        return eval(powerFour);
    }

    vector<int> min = {NULL, 1000};
    vector<int> coup;
    for (int i = 0; i < WIDTH; ++i) {
        if (!copy.isColumnFull((size_t) i)) {
            copy.play(this->player, (size_t) i);
            coup = this->max(copy, profondeur-1);
            if (min[0] == NULL || coup[1] < min[1]) {
                min[0] = i;
                min[1] = coup[1];
            }
        };
    }


    return coup;
}

vector<int> IaPLayer::max(PowerFour powerFour, int profondeur) {
    PowerFour copy = powerFour;

    if(profondeur == 0 || powerFour.checkIfWin()!=0) {
        return eval(powerFour);
    }


    vector<int> max = {NULL, -1000};
    vector<int> coup;
    for(int i = 0 ; i < WIDTH ; ++i) {
        if (!copy.isColumnFull((size_t) i)) {
            copy.play(this->player, (size_t) i);
            coup = this->min(copy, profondeur-1);
            if (max[0] == NULL || coup[1] > max[1]) {
                max[0] = i;
                max[1] = coup[1];
            }
        }
    }

    return max;
}

vector<int> IaPLayer::eval(PowerFour powerFour) {
    int vainqueur = powerFour.checkIfWin();
    vector<int> coup = {NULL, 0};
    if (vainqueur == this->player) {
        coup = {NULL, 1000};
        return coup;
    } else if (vainqueur == (-1) * this->player) {
        coup = {NULL, -1000};
        return coup;
    } else {
        return coup;
    }
}

int IaPLayer::getCoup(PowerFour pf) {
    return this->max(pf, DEPTH)[0];
}
