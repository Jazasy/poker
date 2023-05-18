#ifndef GOMB_HPP_INCLUDED
#define GOMB_HPP_INCLUDED
#include "widget.hpp"
#include "graphics.hpp"

class Gomb : public Widget
{
    int kurzorx;
    int kurzory;
    std::string szoveg;
    int meghivasszamlalo;
public:
    Gomb(int _x, int _y, int _sx, int _sy, std::string _szoveg);
    void kirajzol(genv::event ev);
    void alap();
    void keret();
    std::string visszaadstring();
    bool visszaadbool();
    void gombszoveg();
    void megnyom(genv::event ev);
    void megnyomva();
};


#endif // GOMB_HPP_INCLUDED
