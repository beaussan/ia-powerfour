//
// Created by beaussan on 14/12/17.
//
#include "IaPLayer.h"
#include <iostream>
#include "PowerFour.h"
#include <vector>

//vector<int> IaPLayer::min(PowerFour powerFour, int profondeur) {
//    PowerFour copy = powerFour;
//
//    if(profondeur == 0 || powerFour.checkIfWin()!=0)
//    {
//        return eval(powerFour);
//    }
//
//    vector<int> min = {NULL_VALUE, 1000};
//    vector<int> coup;
//    for (int i = 0; i < WIDTH; ++i) {
//        if (!copy.isColumnFull((size_t) i)) {
//            copy.play(this->player, (size_t) i);
//            coup = this->max(copy, profondeur-1);
//            if (min[0] == NULL_VALUE || coup[1] < min[1]) {
//                min[0] = i;
//                min[1] = coup[1];
//            }
//        };
//    }
//
//
//    return coup;
//}
//
//vector<int> IaPLayer::max(PowerFour powerFour, int profondeur) {
//    PowerFour copy = powerFour;
//
//    if(profondeur == 0 || powerFour.checkIfWin()!=0) {
//        return eval(powerFour);
//    }
//
//
//    vector<int> max = {NULL_VALUE, -1000};
//    vector<int> coup;
//    for(int i = 0 ; i < WIDTH ; ++i) {
//        if (!copy.isColumnFull((size_t) i)) {
//            copy.play(this->player, (size_t) i);
//            coup = this->min(copy, profondeur-1);
//            if (max[0] == NULL_VALUE || coup[1] > max[1]) {
//                max[0] = i;
//                max[1] = coup[1];
//            }
//        }
//    }
//
//    return max;
//}

vector<int> IaPLayer::minmax(PowerFour grille, int profondeur, int alpha, int beta, int joueur) {
    vector<int> meilleurScore = {NULL_VALUE, -std::numeric_limits<int>::max()};
    int joueurAdverse;
    if (joueur == 1)
        joueurAdverse = 2;
    else
        joueurAdverse = 1;
    if (grille.checkIfWin() != 0 || profondeur == 0)
        meilleurScore = eval(grille);
    else {
        vector<int> score;
        PowerFour copy;
        copy = grille;

        for (int i = 0; i < WIDTH; ++i) {
            if (!grille.isColumnFull((size_t) i)) {
                copy.play(this->player, i);
                totalCoups++;
                score = minmax(copy, profondeur - 1, -beta, -alpha, joueurAdverse);
                score[1] = -score[1];
                totalCoups--;
                if (score[1] > meilleurScore[1]) {
                    meilleurScore[1] = score[1];
                    meilleurScore[0] = i;
                }
                if (score[1] > alpha) {
                    alpha = meilleurScore[1];
                    meilleurScore[0] = i;
                    if (alpha > beta) {
                        break;
                    }
                }

            }
        }
    }
    std::cout << meilleurScore[0] << " coup " << meilleurScore[1] << " score" << endl;
    return meilleurScore;
}


vector<int> IaPLayer::eval(PowerFour powerFour) {
    int vainqueur = powerFour.checkIfWin();
    vector<int> coup = {NULL_VALUE, 0};
    if (vainqueur == this->player) {
        coup = {NULL_VALUE, 1000 - totalCoups};
        return coup;
    } else if (vainqueur == (-1) * this->player) {
        coup = {NULL_VALUE, -1000 + totalCoups};
        return coup;
    } else {
        return {NULL_VALUE, rand() % 10000 + 10000};
    }
}

int IaPLayer::getCoup(PowerFour pf) {
    return this->minmax(pf, DEPTH, -9999999, 9999999, this->player)[0];
}
