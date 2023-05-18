#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED
#include "widget.hpp"
#include "graphics.hpp"

class Menu : public Widget
{
private:
    std::vector<std::string> opciok;
    int kezdoindex;
    int elozokijeloltindex;
    int kijeloltindex;
    bool felette;
public:
    Menu(int _x, int _y, int _sx, int _sy,  std::vector<std::string> _opciok);
    void kirajzol(genv::event ev);
    int sxmeghat();
    int symeghat();
    void keret();
    void vonalak();
    void szovegkiir();
    void gorget(genv::event);
    void szovegkijelol(int i);
    void kivalaszt(genv::event ev);
    void alap();
    std::string visszaadstring();
    void valtozasf();
    int betumeretmeghat();
    void szovegsetter(std::vector<std::string> _opciok);
};


#endif // MENU_HPP_INCLUDED
