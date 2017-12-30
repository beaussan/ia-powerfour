//
// Created by beaussan on 14/12/17.
//

#ifndef POWERFOUR_PLAYER_H
#define POWERFOUR_PLAYER_H

#include <string>
#include "PowerFour.h"

using namespace std;

class Player {
protected:
    int player;
    string name;
public:
    explicit Player(int player, string name);

    virtual int getCoup(PowerFour pf) = 0;

    int getPlayer();
    void setName(string name);
    string getName();



};


#endif //POWERFOUR_PLAYER_H
