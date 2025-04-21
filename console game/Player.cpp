#include "player.h"
#include <fstream>
#include <iostream>
using namespace std;
//constructor used to set initial value
Player::Player(): x(1), y(1), score(0), move_count(0) {}
//movement control w/a/s/d
void Player::movement(char input, int rows, int columns)
{
    move_count++;
    if (input == 'w' && y > 1)
    {
        y--;
    }
    else if (input == 's' && y < rows - 2)
    {
       y++;
    }
    else if (input == 'a' && x > 1)
    {
        x--;
    }
    else if (input == 'd' && x < columns - 2)
    {
        x++;
    }
}

void Player::save_to_file(const std::string& filename) const
{
    ofstream out(filename);
    if (!out) {
        cout << "Error opening file for saving: " << filename << endl;
        return;
    }
    out << x << " " << y << " " << score << " " << move_count << endl;
}

void Player::load_from_file(const std::string& filename)
{
    std::ifstream in(filename);
    if (!in) {
        cout<< "Error opening file for loading: " << filename << endl;
        return;
    }
    in >> x >> y >> score >> move_count;
}

int Player::getX() const
{
    return x;
}

int Player::getY() const
{
    return y;
}

int Player::get_score() const
{
    return score;
}

void Player::add_score(int s)
{
    score += s;
}

void Player::reduce_score(int s)
{
    score -= s;
}

void Player::increment_move_count()
{
    move_count++;
}

bool Player::check_collision_enemy(int ex, int ey)
{
    return (x == ex && y == ey);
}

bool Player::check_collision_coll(int cx, int cy)
{
    return (x == cx && y == cy);
}



void Player::set_position(int new_x, int new_y)
{
    x = new_x;
    y = new_y;
}

void Player::set_score(int new_s)
{
    score = new_s;
}


void Player::set_move_count(int new_m)
{
    move_count = new_m;
}

int Player::get_move_count() const
{
    return move_count;
}




