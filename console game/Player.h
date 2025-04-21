#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
class Player
{
private :
    int x,y,score,move_count;
public:
    Player();
    void movement(char input, int rows, int columns);
    void save_to_file(const std::string& filename) const;
    void load_from_file(const std::string& filename);
    int getX() const;
    int getY() const;
    int get_score() const;
    void add_score(int s);
    void reduce_score(int s);
    void increment_move_count();
    bool check_collision_enemy(int ex, int ey);
    bool check_collision_coll(int cx, int cy);
    void set_position(int new_x, int new_y);
    void set_score(int new_s);
    void set_move_count(int new_m);
    int get_move_count() const;

};

#endif
