#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
class Enemy
{
private:
    int x;
    int y;
    int length;
    char pattern = '.';
public:
    Enemy(int startX, int startY, int stream_length);
    void stream_movement();
    void stream_draw(char grid [40][40]);
    int getX() const;
    int getY() const;
    int getLength() const;

};


#endif
