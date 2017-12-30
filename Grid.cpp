//
// Created by beaussan on 21/10/17.
//

#include "Grid.h"
#include <cassert>
#include <iostream>


int Grid::operator()(size_t c, size_t l) const {
    return grid_[position(c, l)];
}

int &Grid::operator()(size_t c, size_t l) {
    return grid_[position(c, l)];
}

size_t Grid::position(size_t c, size_t l) const {
    if (!(c < size_ && l < size_)) {
        std::cout << "Error : " << c << " : " << l << std::endl;
    }
    assert(c < size_ && l < size_);

    return c * size_ + l;
}

Grid::Grid(size_t size, int def) : grid_(size * size, def), size_(size) {}

void Grid::reset(int v) { std::fill(grid_.begin(), grid_.end(), v); }

size_t Grid::size() const { return size_; }
