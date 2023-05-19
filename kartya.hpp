#ifndef KARTYA_HPP_INCLUDED
#define KARTYA_HPP_INCLUDED
#include "widget.hpp"
#include "graphics.hpp"
#include <vector>

class Kartya : public Widget
{
    std::vector<std::vector<int>> pixelek;
    std::vector<std::vector<std::vector<std::vector<int>>>> kartyarajzok;
    int s;
    int id;
    std::vector<int> _kartyaid;
public:
    Kartya(int _x, int _y, int _sx, int _sy);
    std::vector<std::vector<int>> beolvasas(std::string nev);
    void kirajzol(genv::event ev);
    void kartyarajz();
    void kivalaszt(genv::event ev);
    void megtartfelirat();
    void osszeskartyabeolvas();
    void kartyaidsetter(std::vector<int> _id);
    bool kartyafokuszboolgetter();
    void kartyafokuszboolsetter();
    void osszeskartyabeolvastombe();
    void kartyarajztreffkiralyra();
};

#endif // KARTYA_HPP_INCLUDED
