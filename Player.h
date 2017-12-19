//
// Created by beaussan on 14/12/17.
//

#ifndef POWERFOUR_PLAYER_H
#define POWERFOUR_PLAYER_H

#include <string>

using namespace std;

class Player {
protected:
    int player;
    string name;
public:
    Player(){};
    Player(int player);


    int getPlayer();
    void setName(string name);
    string getName();



};


#endif //POWERFOUR_PLAYER_H
