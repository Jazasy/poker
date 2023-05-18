#include "Game.hpp"

int main()
{
    Game* game = new Game(5*(72+10)+10,600);
    game->master();
    delete game;
}
