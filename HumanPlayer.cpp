//
// Created by beaussan on 14/12/17.
//

#include "HumanPlayer.h"
#include "Utils.h"

int HumanPlayer::getCoup(PowerFour pf) {
    return getChoice(1,8)-1;
}
