#include "Game.hpp"

int main()
{
    const int XX = 5*(72+10)+10;
    const int YY = 600;
    Game* game = new Game(XX,YY);
    game->master();
    delete game;
}
