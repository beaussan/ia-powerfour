//
// Created by beaussan on 14/12/17.
//

#include "Player.h"

Player::Player(int player, string name)
{
    this->player = player;
    this->name = name;
}

int Player::getPlayer() {
    return this->player;
}

void Player::setName(string name) {
    this->name = name;
}

string Player::getName() {
    return this->name;
}

int Player::getCoup(PowerFour pf) {
    return 0;
}
