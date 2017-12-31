# Power Four

<p align="center">
  <img src="./.github/power.jpg?raw=true" alt="ConnectFour"/>
</p>

[Français en dessus](#Français)

This is a Connect Four implementation in c++ with the ability to play Player vs Player, Ai vs Player or Ai vs Ai.

The point of making this game is to make a MinMax Ai implementation based on a Connect Four.

## Authors

* [Nicolas Beaussart](https://github.com/beaussart)
* [Naël Abou Chahine](https://github.com/NaelFR)

## Instalation

To build this, you have to have the default c++ tooling and Cmake installed.

Once Cmake installed, you have to do the following while beeing in the source folder :

```
mkdir build
cd build
cmake ..
cmake --build .
```

You will then have a `powerFour` executable in this folder. This is the game. Enjoy !

## Difficulties we had during the making of this

The main dificulity we had in the making of this game is the heuristic value of a game, how do you put a value to a game for the minmax algorithm

---

# Français

Ceci est une implémentation en c++ du puissance 4 avec la possibilité de jouer en humain vs humain, Ia vs humain ou Ia vs Ia.

L'objectif de la réalisation de ce jeu est de s'entrainer à faire une Ia MinMax pour le puissance quatre.

## Autheurs

* [Nicolas Beaussart](https://github.com/beaussart)
* [Naël Abou Chahine](https://github.com/NaelFR)

## Installation

Pour compiler, il faut avoir des outils de buils pour le c++ ainsi que Cmake.

Une fois les prérequis installés, il suffit de faire les commandes suivantes en se trouvant dans le dossier des sources :

```
mkdir build
cd build
cmake ..
cmake --build .
```

Une fois fait, vous aurez un exécutable `powerFour` dans ce dossier. Bon jeu !

## Les difficultés rencontrées

La difficulté principale que nous avons rencontré durant le développement est comment mettre une valeur numérique sur un état de partie. Valeur nécessaire pour l'algorithme Min Max