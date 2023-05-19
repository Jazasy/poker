#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED
#include "graphics.hpp"
#include "Gamelogic.hpp"
#include "grafika.hpp"

class Game
{
    genv::event ev;
    Gamelogic* logic;
    Grafika* graf;
    int XX;
    int YY;
    bool osztokor;
    bool alive;
public:
    Game(int _XX, int _YY);
    ~Game();
    void master();
    void ablak();
    void gameeventloop();
};

#endif // GAME_HPP_INCLUDED
