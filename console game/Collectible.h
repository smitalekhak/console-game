#ifndef COLLECTIBLE_H
#define COLLECTIBLE_H

class Collectible {
public:
    int x, y;

    Collectible(int startX, int startY);
    void spawn_collectibles(int columns, int rows);
    int getX() const;
    int getY() const;

};

#endif
