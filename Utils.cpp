//
// Created by nicbe on 19/12/2017.
//

#include "Utils.h"

#include <iostream>

using namespace std;

int getChoice(int min, int max) {
    int x = -100;
    cout << "What is your choice ? ( between " << min << " and " << max << ")" << endl;

    do {
        cout << "> ";
        std::cin >> x;
        while (std::cin.fail()) {
            std::cout << "Please enter a number" << std::endl;
            std::cin.clear();
            std::cin.ignore(256, '\n');
            cout << "> ";
            std::cin >> x;
        }

        if (x < min || max < x) {
            cout << "Please enter a number between " << min << " and " << max << endl;
        }

    }while (x < min || max < x);
    return x;
}
