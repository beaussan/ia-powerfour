//
// Created by beaussan on 21/10/17.
//

#ifndef POWERFOUR_GRID_H
#define POWERFOUR_GRID_H


#include <vector>

class Grid {
    typedef std::vector<int> storage;
    storage grid_;
    size_t size_;

    size_t position(size_t c, size_t l) const;

public:

    Grid(size_t size, int def);

    void reset(int v);

    size_t size() const;

    int operator()(size_t c, size_t l) const;

    int &operator()(size_t c, size_t l);

};


#endif //POWERFOUR_GRID_H
