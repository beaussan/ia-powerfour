//
// Created by beaussan on 14/12/17.
//

#ifndef POWERFOUR_IAPLAYER_H
#define POWERFOUR_IAPLAYER_H

#define DEPTH 4
#define NULL_VALUE 12345678

#include "Player.h"
#include "PowerFour.h"

class IaPLayer : public Player {
protected:
    int totalCoups;
public:
    IaPLayer(int player, string name) : Player(player, name){ this->totalCoups = 0;};
//    vector<int> min(PowerFour powerFour, int profondeur);
//    vector<int> max(PowerFour powerFour, int profondeur);
    vector<int> minmax(PowerFour pf, int profondeur, int alpha, int beta, int joueur);
    vector<int> eval(PowerFour powerFour);

    int getCoup(PowerFour pf);


};


#endif //POWERFOUR_IAPLAYER_H
