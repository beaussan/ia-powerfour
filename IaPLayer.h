//
// Created by beaussan on 14/12/17.
//

#ifndef POWERFOUR_IAPLAYER_H
#define POWERFOUR_IAPLAYER_H

#define DEPTH 4

#include "Player.h"
#include "PowerFour.h"

class IaPLayer : public Player {
public:
    IaPLayer(int player, string name) : Player(player, name){}
    vector<int> min(PowerFour powerFour, int profondeur);
    vector<int> max(PowerFour powerFour, int profondeur);
    vector<int> eval(PowerFour powerFour);

    int getCoup(PowerFour pf) override;


};


#endif //POWERFOUR_IAPLAYER_H
