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
        cin >> x;
        while (cin.fail()) {
            cout << "Please enter a number" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cout << "> ";
            cin >> x;
        }

        if (x < min || max < x) {
            cout << "Please enter a number between " << min << " and " << max << endl;
        }

    }while (x < min || max < x);
    return x;
}
