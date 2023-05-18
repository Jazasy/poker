#include "menu.hpp"
#include "graphics.hpp"
#include <iostream>

using namespace genv;

Menu::Menu(int _x, int _y, int _sx, int _sy, std::vector<std::string> _opciok) : Widget(_x, _y, _sx, _sy)
{
    opciok=_opciok;
    betumeret=betumeretmeghat();
    //sx=sxmeghat();
    //sy=symeghat();
    kezdoindex = 0;
    kijeloltindex = -1;
};

void Menu::kirajzol(event ev)
{
    //posxy(ev);
    keret();
    //fokuszf(ev);
    //kivalaszt(ev);
    //valtozasf();
    //fokuszkeret();
    alap();
    //gorget(ev);
    szovegkiir();
}

void Menu::szovegsetter(std::vector<std::string> _opciok)
{
    opciok = _opciok;
}

std::string Menu::visszaadstring()
{
    std::string ures = "nincs valtozas :/";
    if(valtozas)
        return opciok[kijeloltindex];
    else
        return ures;
}

void Menu::valtozasf()
{
    if(elozokijeloltindex!=kijeloltindex)
        valtozas=true;
    else
        valtozas=false;
}

void Menu::alap()
{
    gout<<move_to(x,y)<<color(5,102,8)<<box(sx,sy);
}


void Menu::keret()
{
    gout<<move_to(x-2, y-2)<<color(255,255,255)<<box(sx+2*2, sy+2*2);
}

void Menu::vonalak()
{
    if(opciok.size()<10)
    {
        for(int i=1; i<opciok.size(); i++)
        {
            gout<<move_to(x, y+double(sy)/double(opciok.size())*i)<<color(255,255,255)<<box(sx, 2);
        }
    }
    else
    {
        for(int i=1; i<10; i++)
        {
            gout<<move_to(x, y+double(sy)/double(10)*i)<<color(255,255,255)<<box(sx, 2);
        }
    }
}

void Menu::szovegkiir()
{
    gout<<font("LiberationSans-Regular.ttf",betumeret);
    if(opciok.size()<10)
    {
        for(int i=0; i<opciok.size(); i++)
        {
            szovegkijelol(i);
            vonalak();
            gout<<move_to(x+5, y+double(sy)/double(opciok.size())*i)<<color(255,255,255)<<text(opciok[i+kezdoindex]);
        }
    }
    else
    {
        for(int i=0; i<10; i++)
        {
            szovegkijelol(i);
            vonalak();
            gout<<move_to(x+10, y+double(sy)/double(10)*i)<<color(255,255,255)<<text(opciok[i+kezdoindex]);
        }
    }
}

void Menu::szovegkijelol(int i)
{
    if(opciok.size()<10)
    {
        if(i+kezdoindex == kijeloltindex)
        gout<<move_to(x,y+double(sy)/double(opciok.size())*i)<<color(255,255,50)<<box(sx,double(sy)/double(opciok.size()));
    }
    else
    {
        if(i+kezdoindex == kijeloltindex)
            gout<<move_to(x,y+double(sy)/double(10)*i)<<color(255,255,50)<<box(sx,double(sy)/double(10));
    }
}

void Menu::kivalaszt(event ev)
{
    elozokijeloltindex=kijeloltindex;
    if(opciok.size()<10)
    {
        for(int i=0; i<opciok.size(); i++)
    {
        if(mx>x && mx<x+sx && my>y+double(sy)/double(opciok.size())*i && my<y+double(sy)/double(opciok.size())*(i+1) && ev.button == btn_left)
            kijeloltindex=i+kezdoindex;
    }
    }
    else
    {
        for(int i=0; i<10; i++)
        {
            if(mx>x && mx<x+sx && my>y+double(sy)/double(10)*i && my<y+double(sy)/double(10)*(i+1) && ev.button == btn_left)
                kijeloltindex=i+kezdoindex;
        }
    }
}

void Menu::gorget(event ev)
{
    if(opciok.size()>=10)
    {
        if(ev.button==btn_wheelup && kezdoindex!=0 && fokusz)
            kezdoindex--;
        if(ev.button==btn_wheeldown && kezdoindex!=opciok.size()-10 && fokusz)
            kezdoindex++;
    }
}

int Menu::betumeretmeghat()
{
    int betumeretf=0;
    if(opciok.size()<10)
    {
        betumeretf = double(sy)/double(opciok.size())-3;
    }
    else
    {
        betumeretf = double(sy)/double(10)-3;
    }
    return betumeretf;
}

int Menu::sxmeghat()
{
    gout<<font("LiberationSans-Regular.ttf",betumeret);
    int sxf=0;
    for(std::string s: opciok)
    {
        if(gout.twidth(s)>=sxf)
            sxf=gout.twidth(s);
    }
    if(sxf+20>=sx)
        return sxf+20;
    else
        return sx;
}

int Menu::symeghat()
{
    int syf=0;
    if(opciok.size()<10)
    {
        if((gout.cascent()+gout.cdescent())*opciok.size()>=syf)
            syf=(gout.cascent()+gout.cdescent()+2)*opciok.size();
    }
    else
    {
        if((gout.cascent()+gout.cdescent())*10>=syf)
            syf=(gout.cascent()+gout.cdescent()+2)*10;
    }
    return syf;
}
