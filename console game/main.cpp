#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Enemy.h"
#include "Collectible.h"

//game row column and exit set
const int rows = 40;
const int columns = 40;
const char exit_symbol = 'E';

//grid
char grid[rows][columns];

//game objects
Player player;
vector<Enemy> enemies;
vector<Collectible> collectibles;
bool game_running = true;
int level=1;

//solve display issues here :
//place text at specified coord
void setcursor(int xpos , int ypos)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    cout.flush();
    COORD coord = { (SHORT)xpos, (SHORT)ypos };
    SetConsoleCursorPosition(hOut, coord);

}
//hide blinnking
void hidecursor()
{
    auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor_info;
    GetConsoleCursorInfo(handle, &cursor_info);
    cursor_info.bVisible = false;
    SetConsoleCursorInfo(handle, &cursor_info);
}

//setup for enemies and collectible according to level
void initgame()
{
    enemies.clear();
    collectibles.clear();
    srand(time(0));

    //CHECK FOR LEVEL
    if (level == 1)
    {
    // seetup for enemies
    for (int i = 2; i< rows - 1 ; i+=6)
    {
        enemies.push_back(Enemy(columns - 2 , i , 6));
    }
    //setup for collectibles
    for (int i = 0; i<10;i++)
    {
        Collectible coins (1,1);
        coins.spawn_collectibles(columns,rows);
        collectibles.push_back(coins);

    }

    }

    //check for level
    if (level == 2)
    {
    //setup more enemy this time
    for (int i= 2; i< rows- 1; i+=2)
    {
         enemies.emplace_back(columns - 2, i, 10);
    }

    //same setup for collectible resuse
    for (int i = 0; i<10;i+=3)
    {
        Collectible coins (1,1);
        coins.spawn_collectibles(columns,rows);
        collectibles.push_back(coins);

    }

    }


}

//make the grid where everything appears
void draw_grid()

{
    system("cls");
    //spaces in the grid
      for(int i = 0; i < rows; i++)
      {
        for(int j = 0; j < columns; j++)
            {
            grid[i][j] = ' ';
            }
      }
    //border
      for(int i = 0; i < 40; i++)
    {
        grid[i][0] = '|';
        grid[i][39] = '|';
        grid[0][i] = '-';
        grid[39][i] = '-';
    }
    // set where the exit will appear
    grid[38][38]= exit_symbol;
    //put enemies on the grid

    for (Enemy& enemy : enemies)
        enemy.stream_draw(grid);


    //put collectibles on the grid
    for (const Collectible& c : collectibles)
    grid[c.getY()][c.getX()] = '$';
    //now player
    grid[player.getY()][player.getX()] = 'P';
    //
    setcursor(0,0); //redraw grid
    //print grid
     for(int i = 0; i < 40; i++) {
        for(int j = 0; j < 40; j++)
            cout << grid[i][j];
        cout << "\n";
    }

    //display score
    cout << "Score: " << player.get_score() << " | WASD = move | Q = quit\n";
}

// now check if there is collsion between elements
void forcollisions()
{
    //to check for enemy hits
    for (const Enemy& whoop : enemies)
    {
        for (int i=0; i < whoop.getLength(); i++)
        {
            if (player.check_collision_enemy(whoop.getX() + i, whoop.getY()))
            {
                player.reduce_score(5);
                Sleep(100);
                return;
            }

        }


    //collision with collectible
        for (auto it = collectibles.begin(); it != collectibles.end(); ) {
            if (player.check_collision_coll(it->getX(), it->getY())) {
                player.add_score(15);
                it = collectibles.erase(it);
            } else {
                ++it;
            }
        }
    }



}

// game end and level up
bool gameendcondition()
{
    if (player.getY() == 38 && player.getX() == 38)
        {
        level++;
        if (level > 2)
        {
            cout << "ALL LEVEL CLEARED";
            return true;

        }

        player.set_position(1,1);
        initgame();
        return false;
        }

    if (player.get_score() < 0 )
    {
        cout<< "GAME OVER TRY AGAIN"<<endl;
        return true;
    }

    return false;


}


//loop set
void game_loop()
{
    char input;

    hidecursor();
    initgame();

    while (game_running)
    {
        draw_grid();

        //for which key was pressed and their outcome put here
        if (_kbhit())
        {
            input = _getch();

            if (input == 'q') {
                break;
            }
            else if (input == 'o') {
                player.save_to_file("savefile.txt");
            }
            else if (input == 'l') {
                player.load_from_file("savefile.txt");
            }
            else {
                player.movement(input, rows, columns);
            }
        }

        for (Enemy& enemy : enemies) {
            enemy.stream_movement();   // enemy movement
        }

        forcollisions();  //collision check

        if (gameendcondition()) {
            break;
        }

        Sleep(80);
    }
}

//main to run
int main()
{
    game_loop();
    return 0;


}

