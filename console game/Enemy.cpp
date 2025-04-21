#include "Enemy.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

Enemy::Enemy(int startX, int startY, int stream_length)
    : x(startX), y(startY), length(stream_length) {}


void Enemy::stream_movement()
{
    if (x > 1)
    {
        x--;
    }
    else
    {
        x = 38;
    }

}
void Enemy::stream_draw(char grid[40][40])
 {
    for (int i = 0; i < length; i++) {
        int draw_x = x + i;
        if (draw_x>= 1 && draw_x < 38) {
            char pattern = (rand() % 2 == 0) ? '.' : ' ';
            grid[y][draw_x] = pattern;
        }
    }
}

int Enemy::getX() const {
    return x;
}

int Enemy::getY() const {
    return y;
}

int Enemy::getLength() const {
    return length;
}





