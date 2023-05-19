#include "graphics.hpp"
#include "Game.hpp"
#include "Gamelogic.hpp"
#include "grafika.hpp"
#include <iostream>

Game::Game(int _XX, int _YY ) : XX(_XX), YY(_YY)
{
    logic = new Gamelogic();
    graf = new Grafika(XX,YY,logic);
    osztokor = true;
};

Game::~Game()
{
    delete logic;
    delete graf;
}

void Game::master()
{
    ablak();
    gameeventloop();
}

void Game::ablak()
{
    genv::gout.open(XX,YY);
    genv::gout<<genv::refresh;
}

void Game::gameeventloop()
{
    graf->jatekrajz(ev);
    genv::gout<<genv::refresh;
    while(genv::gin>>ev && ev.keycode != genv::key_escape)
    {
        //graf->jatekrajz(ev);
        graf->mutatogombboolsettersetter(!osztokor);
        if(graf->grafikagetkiosztogombbool() && osztokor)
        {
            logic->kezboolkivesz();
            logic->leoszt();
            graf->grafikakartyaidsetter();
            logic->zsetonallit(graf->numgettergetter());
            osztokor = false;
        }
        if(graf->grafikagetmutatogombbool() && !osztokor)
        {
            graf->grafcsere();
            graf->grafikakartyaidsetter();
            logic->ellenoriz();
            logic->nyeremeny(graf->numgettergetter());
            osztokor = true;

        }
        graf->jatekrajz(ev);
        genv::gout<<genv::refresh;
    }
}
