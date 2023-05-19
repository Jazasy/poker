#include "kartya.hpp"
#include "graphics.hpp"
#include <fstream>
#include <iostream>

Kartya::Kartya(int _x, int _y, int _sx, int _sy) :  Widget(_x, _y, _sx, _sy)
{
    osszeskartyabeolvas();
    s = 0;
    _kartyaid = {-1,-1};
}

void Kartya::kirajzol(genv::event ev)
{
    posxy(ev);
    kivalaszt(ev);
    megtartfelirat();
    if(_kartyaid[0]==0 && _kartyaid[1]==11)
        kartyarajztreffkiralyra();
    else
        kartyarajz();
}

void Kartya::mutatogomboolsetter(bool ih)
{
    _mutatogombool = ih;
}

std::vector<std::vector<int>> Kartya::beolvasas(std::string nev)
{
    std::vector<std::vector<int>> _pixelek;
    std::ifstream f;
    f.open(nev);
    if (!f.is_open())
    {
        std::cerr << "Hiba: " << nev << " fájl nem található vagy nem nyitható meg!" << std::endl;
        return _pixelek;
    }
    f>>sx>>sy;
    int r,g,b;
    while(f.good())
    {
        f>>r>>g>>b;
        std::vector<int> pixel;
        pixel.push_back(r);
        pixel.push_back(g);
        pixel.push_back(b);
        _pixelek.push_back(pixel);
    }
    f.close();
    return _pixelek;
}

void Kartya::kartyarajztreffkiralyra()
{
    if(_kartyaid[0] != -1 && _kartyaid[1] != -1)
    {
        for(int i=0; i<sy-2; i++)
        {
            for(int j=0; j<sx; j++)
            {
                genv::gout<<genv::move_to(x+j,y+i)<<genv::color(kartyarajzok[_kartyaid[0]][_kartyaid[1]][s][0],kartyarajzok[_kartyaid[0]][_kartyaid[1]][s][1],kartyarajzok[_kartyaid[0]][_kartyaid[1]][s][2])<<genv::dot;
                s++;
            }
        }
        s=0;
        genv::gout<<genv::move_to(x+1,y+sy-2)<<genv::color(255,255,255)<<genv::line(sx-2,0);
        genv::gout<<genv::move_to(x+2,y+sy-1)<<genv::color(255,255,255)<<genv::line(sx-4,0);
    }
}

void Kartya::kartyarajz()
{
    if(_kartyaid[0] != -1 && _kartyaid[1] != -1)
    {
        for(int i=0; i<sy; i++)
        {
            for(int j=0; j<sx; j++)
            {
                genv::gout<<genv::move_to(x+j,y+i)<<genv::color(kartyarajzok[_kartyaid[0]][_kartyaid[1]][s][0],kartyarajzok[_kartyaid[0]][_kartyaid[1]][s][1],kartyarajzok[_kartyaid[0]][_kartyaid[1]][s][2])<<genv::dot;
                s++;
            }
        }
        s=0;
    }
}

bool Kartya::kartyafokuszboolgetter()
{
    return fokusz;
}

void Kartya::kartyafokuszboolsetter()
{
    fokusz=false;
}

void Kartya::kivalaszt(genv::event ev)
{
    if(mx>x && mx<x+sx && my>y && my<y+sy && ev.button == genv::btn_left && _mutatogombool)
        fokusz=!fokusz;
}

void Kartya::megtartfelirat()
{
    if(fokusz)
    {
        genv::gout<<genv::move_to(x-3, y-3)<<genv::color(255,0,0)<<genv::box(sx+2*3, sy+2*3);
        genv::gout << genv::font("LiberationSans-Regular.ttf",15);
        genv::gout<<genv::move_to(x+(sx/2-genv::gout.twidth("HOLD")/2), y-30)<<genv::color(255,100,100)<<genv::text("HOLD");
    }
    if(!fokusz)
    {
        genv::gout<<genv::move_to(x-3, y-3)<<genv::color(5,102,8)<<genv::box(sx+2*3, sy+2*3);
    }
}

void Kartya::kartyaidsetter(std::vector<int> _id)
{
    _kartyaid = _id;
}

void Kartya::osszeskartyabeolvas()
{
    std::vector<std::vector<std::vector<int>>> ckartyak;
    ckartyak.push_back(beolvasas("C2.bmp.kep"));
    ckartyak.push_back(beolvasas("C3.bmp.kep"));
    ckartyak.push_back(beolvasas("C4.bmp.kep"));
    ckartyak.push_back(beolvasas("C5.bmp.kep"));
    ckartyak.push_back(beolvasas("C6.bmp.kep"));
    ckartyak.push_back(beolvasas("C7.bmp.kep"));
    ckartyak.push_back(beolvasas("C8.bmp.kep"));
    ckartyak.push_back(beolvasas("C9.bmp.kep"));
    ckartyak.push_back(beolvasas("C10.bmp.kep"));
    ckartyak.push_back(beolvasas("Cj.bmp.kep"));
    ckartyak.push_back(beolvasas("Cq.bmp.kep"));
    ckartyak.push_back(beolvasas("Ck.bmp.kep"));
    ckartyak.push_back(beolvasas("Ca.bmp.kep"));
    kartyarajzok.push_back(ckartyak);

    std::vector<std::vector<std::vector<int>>> skartyak;
    skartyak.push_back(beolvasas("S2.bmp.kep"));
    skartyak.push_back(beolvasas("S3.bmp.kep"));
    skartyak.push_back(beolvasas("S4.bmp.kep"));
    skartyak.push_back(beolvasas("S5.bmp.kep"));
    skartyak.push_back(beolvasas("S6.bmp.kep"));
    skartyak.push_back(beolvasas("S7.bmp.kep"));
    skartyak.push_back(beolvasas("S8.bmp.kep"));
    skartyak.push_back(beolvasas("S9.bmp.kep"));
    skartyak.push_back(beolvasas("S10.bmp.kep"));
    skartyak.push_back(beolvasas("Sj.bmp.kep"));
    skartyak.push_back(beolvasas("Sq.bmp.kep"));
    skartyak.push_back(beolvasas("Sk.bmp.kep"));
    skartyak.push_back(beolvasas("Sa.bmp.kep"));
    kartyarajzok.push_back(skartyak);

    std::vector<std::vector<std::vector<int>>> hkartyak;
    hkartyak.push_back(beolvasas("H2.bmp.kep"));
    hkartyak.push_back(beolvasas("H3.bmp.kep"));
    hkartyak.push_back(beolvasas("H4.bmp.kep"));
    hkartyak.push_back(beolvasas("H5.bmp.kep"));
    hkartyak.push_back(beolvasas("H6.bmp.kep"));
    hkartyak.push_back(beolvasas("H7.bmp.kep"));
    hkartyak.push_back(beolvasas("H8.bmp.kep"));
    hkartyak.push_back(beolvasas("H9.bmp.kep"));
    hkartyak.push_back(beolvasas("H10.bmp.kep"));
    hkartyak.push_back(beolvasas("Hj.bmp.kep"));
    hkartyak.push_back(beolvasas("Hq.bmp.kep"));
    hkartyak.push_back(beolvasas("Hk.bmp.kep"));
    hkartyak.push_back(beolvasas("Ha.bmp.kep"));
    kartyarajzok.push_back(hkartyak);

    std::vector<std::vector<std::vector<int>>> dkartyak;
    dkartyak.push_back(beolvasas("D2.bmp.kep"));
    dkartyak.push_back(beolvasas("D3.bmp.kep"));
    dkartyak.push_back(beolvasas("D4.bmp.kep"));
    dkartyak.push_back(beolvasas("D5.bmp.kep"));
    dkartyak.push_back(beolvasas("D6.bmp.kep"));
    dkartyak.push_back(beolvasas("D7.bmp.kep"));
    dkartyak.push_back(beolvasas("D8.bmp.kep"));
    dkartyak.push_back(beolvasas("D9.bmp.kep"));
    dkartyak.push_back(beolvasas("D10.bmp.kep"));
    dkartyak.push_back(beolvasas("Dj.bmp.kep"));
    dkartyak.push_back(beolvasas("Dq.bmp.kep"));
    dkartyak.push_back(beolvasas("Dk.bmp.kep"));
    dkartyak.push_back(beolvasas("Da.bmp.kep"));
    kartyarajzok.push_back(dkartyak);

}
