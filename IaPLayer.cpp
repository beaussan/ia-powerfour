//
// Created by beaussan on 14/12/17.
//

#include "IaPLayer.h"
#include "PowerFour.h"

int Player::getCoup(PowerFour grid) {

}

int IaPLayer::min(PowerFour powerFour, int profondeur) {
    PowerFour copy = powerFour;

    if(profondeur == 0 || powerFour.checkIfWin()!=0)
    {
        return eval(powerFour);
    }

    int tmp;
    int min = 1000;


    return 0;
}

int IaPLayer::max(PowerFour powerFour, int profondeur) {
    PowerFour copy = powerFour;

    if(profondeur == 0 || powerFour.checkIfWin()!=0)
    {
        return eval(powerFour);
    }

    int tmp;
    int max = -1000;

    for(int i = 0 ; i < WIDTH ; i++) {
        
    }

    return 0;
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
