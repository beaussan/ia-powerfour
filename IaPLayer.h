//
// Created by beaussan on 14/12/17.
//

#ifndef POWERFOUR_IAPLAYER_H
#define POWERFOUR_IAPLAYER_H


#include "Player.h"
#include "PowerFour.h"

class IaPLayer : public Player {
public:
    IaPLayer(int player, string name) : Player(player, name){}
    int min(PowerFour powerFour, int profondeur);
    int max(PowerFour powerFour, int profondeur);
    int eval(PowerFour powerFour);


};


#endif //POWERFOUR_IAPLAYER_H
