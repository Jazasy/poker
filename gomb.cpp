#include "gomb.hpp"
#include "graphics.hpp"
#include <string>

using namespace genv;

Gomb::Gomb(int _x, int _y, int _sx, int _sy, std::string _szoveg) : Widget(_x, _y, _sx, _sy)
{
    betumeret = sy-17;
    szoveg = _szoveg;
}

void Gomb::kirajzol(event ev)
{
    posxy(ev);
    keret();
    megnyom(ev);
    megnyomva();
    alap();
    gombszoveg();
    meghivasszamlalo+=1;
    visszaadbool();

}

void Gomb::alap()
{
    gout<<move_to(x,y)<<color(125,255,85)<<box(sx,sy);
}

void Gomb::gombszoveg()
{
    gout << font("LiberationSans-Regular.ttf",betumeret);
    gout<<move_to(x+sx/2-genv::gout.twidth(szoveg)/2,y+sy/2-(genv::gout.cascent()+genv::gout.cdescent())/2)<<color(0,0,0)<<text(szoveg);
}

void Gomb::keret()
{
    gout<<move_to(x-2, y-2)<<color(0,0,0)<<box(sx+2*2, sy+2*2);
}

void Gomb::megnyom(event ev)
{
    fokusz=false;
    if(mx>x && mx<x+sx && my>y && my<y+sy && ev.button == genv::btn_left)
        fokusz = true;
}

void Gomb::megnyomva()
{
    if(fokusz)
    {
        genv::gout<<genv::move_to(x-3, y-3)<<genv::color(255,0,0)<<genv::box(sx+2*3, sy+2*3);
    }
    if(!fokusz)
    {
        genv::gout<<genv::move_to(x-3, y-3)<<genv::color(0,0,0)<<genv::box(sx+2*3, sy+2*3);
        keret();
    }
}

bool Gomb::visszaadbool()
{
    return fokusz;
}

std::string Gomb::visszaadstring()
{
    std::string ures = "nincs valtozas :/";
    if(valtozas)
        return szoveg;
    else
        return ures;
}
