#ifndef GRAFIKA_HPP_INCLUDED
#define GRAFIKA_HPP_INCLUDED
#include "graphics.hpp"
#include "Gamelogic.hpp"
#include "numdisp.hpp"
#include "gomb.hpp"
#include "kartya.hpp"
#include "menu.hpp"
#include <vector>

class Grafika
{
    std::vector<Widget*> widgetek;
    Numdisp* tet;
    Gamelogic* logiccop;
    Gomb* kiosztogomb;
    Gomb* mutatogomb;
    Gomb* startgomb;
    Kartya* kartya;
    Kartya* kartya1;
    Kartya* kartya2;
    Kartya* kartya3;
    Kartya* kartya4;
    std::vector<bool> kartyamegtartindex;
    Menu* nyeremenytablazatszoveg;
    Menu* nyeremenytablazatszam;
    Menu* zsetonok;
    Menu* valoszinusegtablazat;
    int XX;
    int YY;
public:
    Grafika(int _XX, int _YY, Gamelogic* _logic);
    ~Grafika();
    void jatekrajz(genv::event ev, bool ih);
    void hatter();
    void zsetonszoveg();
    bool grafikagetkiosztogombbool();
    bool grafikagetmutatogombbool();
    bool grafikagetstartgombool();
    void grafikakartyaidsetter();
    int numgettergetter();
    void grafcsere();
    void kartyafokuszkivesz();
    void nyeremenyfelirat();
    void nyeremenyek();
    bool mutatogombboolsettersetter(bool ih);
    void allin();
    void startkepernyo(genv::event ev);
    void meghaltalfelirat();
};

#endif // GRAFIKA_HPP_INCLUDED
