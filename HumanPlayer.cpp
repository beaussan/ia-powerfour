//
// Created by beaussan on 14/12/17.
//

#include <iostream>
#include "HumanPlayer.h"
#include "Utils.h"

int HumanPlayer::getCoup(PowerFour pf) {
    std::cout << "Get play human !" << std::endl;
    return getChoice(1,8)-1;
}
