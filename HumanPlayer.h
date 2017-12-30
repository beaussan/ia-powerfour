//
// Created by beaussan on 14/12/17.
//

#ifndef POWERFOUR_HUMANPLAYER_H
#define POWERFOUR_HUMANPLAYER_H


#include "Player.h"

class HumanPlayer : public Player {
public:
    HumanPlayer(int player, string name) : Player(player, name){}


    int getCoup(PowerFour pf);
};


#endif //POWERFOUR_HUMANPLAYER_H
