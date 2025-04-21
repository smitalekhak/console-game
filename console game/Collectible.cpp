#include <iostream>
#include "Collectible.h"

 Collectible::Collectible(int startX, int startY) : x(startX), y(startY) {}

void Collectible::spawn_collectibles(int columns, int rows) {
    x = rand() % (columns - 2) + 1;
    y = rand() % (rows - 2) + 1;
}


int Collectible::getX() const {
    return x;
}

int Collectible::getY() const {
    return y;
}
