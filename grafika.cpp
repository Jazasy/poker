#include "grafika.hpp"
#include "graphics.hpp"
#include <vector>
#include <iostream>
#include "Gamelogic.hpp"
#include <string>

Grafika::Grafika(int _XX, int _YY, Gamelogic* _logic) : XX(_XX), YY(_YY), logiccop(_logic)
{
    tet = new Numdisp(10, YY-10-50, 150, 50, 100);
    kiosztogomb = new Gomb(10+150+10, YY-10-50, 110, 50, "Deal");
    mutatogomb = new Gomb(10+150+10, YY-10-50-10-50, 110, 50, "Show");
    kartya = new Kartya(10+72*0+10*0, 2.5*YY/4, 0, 0);
    kartya1 = new Kartya(10+72*1+10*1, 2.5*YY/4, 0, 0);
    kartya2 = new Kartya(10+72*2+10*2, 2.5*YY/4, 0, 0);
    kartya3 = new Kartya(10+72*3+10*3, 2.5*YY/4, 0, 0);
    kartya4 = new Kartya(10+72*4+10*4, 2.5*YY/4, 0, 0);
    nyeremenytablazatszoveg = new Menu(10, 10, XX/2-10, YY/2.5, {"Royal Flush", "Straight Flush", "Four of a Kind", "Full", "Flush", "Straight", "Drill", "Two Pair", "Pair", "High"});
    nyeremenytablazatszam = new Menu(XX/2, 10, XX/2-10, YY/2.5, {std::to_string(tet->numgetter()*20), std::to_string(tet->numgetter()*10), std::to_string(tet->numgetter()*7), std::to_string(tet->numgetter()*6), std::to_string(tet->numgetter()*5), std::to_string(tet->numgetter()*4), std::to_string(tet->numgetter()*3), std::to_string(tet->numgetter()*2), std::to_string(tet->numgetter()*20), "+1"});
    zsetonok = new Menu(10+150+10+110+10, YY-60, 120, 50, logiccop->zsetongetter());
    widgetek.push_back(tet);
    widgetek.push_back(kiosztogomb);
    widgetek.push_back(mutatogomb);
    widgetek.push_back(kartya);
    widgetek.push_back(kartya1);
    widgetek.push_back(kartya2);
    widgetek.push_back(kartya3);
    widgetek.push_back(kartya4);
    widgetek.push_back(nyeremenytablazatszoveg);
    widgetek.push_back(nyeremenytablazatszam);
    widgetek.push_back(zsetonok);
    kartyamegtartindex = {false, false, false, false, false};
}

Grafika::~Grafika()
{
    delete tet;
    delete logiccop;
    delete kiosztogomb;
    delete mutatogomb;
    delete kartya; delete kartya1; delete kartya2; delete kartya3; delete kartya4;
    delete nyeremenytablazatszoveg;
    delete nyeremenytablazatszam;
    delete zsetonok;
}

void Grafika::jatekrajz(genv::event ev)
{
    hatter();
    nyeremenyfelirat();
    nyeremenyek();
    zsetonszoveg();
    for(Widget* w : widgetek)
    {
        w->kirajzol(ev);
    }
}

void Grafika::nyeremenyek()
{
    nyeremenytablazatszam->szovegsetter({std::to_string(tet->numgetter()*20), std::to_string(tet->numgetter()*10), std::to_string(tet->numgetter()*7), std::to_string(tet->numgetter()*6), std::to_string(tet->numgetter()*5), std::to_string(tet->numgetter()*4), std::to_string(tet->numgetter()*3), std::to_string(tet->numgetter()*2), std::to_string(tet->numgetter()), "+1"});
}

void Grafika::hatter()
{
    genv::gout<<genv::move_to(0,0)<<genv::color(5,102,8)<<genv::box(XX,YY);
}

void Grafika::zsetonszoveg()
{
    genv::gout << genv::font("LiberationSans-Regular.ttf",30);
    zsetonok->szovegsetter(logiccop->zsetongetter());
    //std::cout<<logiccop->zsetongetter()[0]<<std::endl;
    genv::gout<<genv::move_to(10+150+10+110+10, YY-60-40)<<genv::color(255,255,255)<<genv::text("Chip:");
}

void Grafika::grafcsere()
{
    if(kartya->kartyafokuszboolgetter())
       kartyamegtartindex[0]=true;
    if(kartya1->kartyafokuszboolgetter())
       kartyamegtartindex[1]=true;
    if(kartya2->kartyafokuszboolgetter())
       kartyamegtartindex[2]=true;
    if(kartya3->kartyafokuszboolgetter())
       kartyamegtartindex[3]=true;
    if(kartya4->kartyafokuszboolgetter())
       kartyamegtartindex[4]=true;
    logiccop->kartyaidcsere(kartyamegtartindex);
    kartyamegtartindex = {false, false, false, false, false};
    kartyafokuszkivesz();
}

void Grafika::kartyafokuszkivesz()
{
    kartya->kartyafokuszboolsetter();
    kartya1->kartyafokuszboolsetter();
    kartya2->kartyafokuszboolsetter();
    kartya3->kartyafokuszboolsetter();
    kartya4->kartyafokuszboolsetter();
}

int Grafika::numgettergetter()
{
    for(int i=0; i<logiccop->lapokgetter().size(); i++)
    {
        std::cout<<logiccop->lapokgetter()[i][0]<<", "<<logiccop->lapokgetter()[i][1]<<std::endl;
    }
    std::cout<<std::endl;

    int szam = tet->numgetter();
    return szam;
}

bool Grafika::grafikagetmutatogombbool()
{
    return mutatogomb->visszaadbool();
}

bool Grafika::grafikagetkiosztogombbool()
{
    return kiosztogomb->visszaadbool();
}

void Grafika::grafikakartyaidsetter()
{
    kartya->kartyaidsetter(logiccop->lapokgetter()[0]);
    kartya1->kartyaidsetter(logiccop->lapokgetter()[1]);
    kartya2->kartyaidsetter(logiccop->lapokgetter()[2]);
    kartya3->kartyaidsetter(logiccop->lapokgetter()[3]);
    kartya4->kartyaidsetter(logiccop->lapokgetter()[4]);
    kartyafokuszkivesz();
}

void Grafika::nyeremenyfelirat()
{
    genv::gout << genv::font("LiberationSans-Regular.ttf",50);
    if(logiccop->parboolgetter())
        genv::gout<<genv::move_to(XX/2-genv::gout.twidth("PAIR")/2, 2.5*YY/4-90)<<genv::color(255,255,255)<<genv::text("PAIR");
    if(logiccop->ket_parboolgetter())
        genv::gout<<genv::move_to(XX/2-genv::gout.twidth("TWO PAIR !")/2, 2.5*YY/4-90)<<genv::color(255,255,255)<<genv::text("TWO PAIR !");
    if(logiccop->drillgetter())
        genv::gout<<genv::move_to(XX/2-genv::gout.twidth("DRILL !!")/2, 2.5*YY/4-90)<<genv::color(255,255,255)<<genv::text("DRILL !!");
    if(logiccop->sorgetter())
        genv::gout<<genv::move_to(XX/2-genv::gout.twidth("STRAGHT !!!")/2, 2.5*YY/4-90)<<genv::color(255,255,255)<<genv::text("STRAGHT !!!");
    if(logiccop->flushgetter())
        genv::gout<<genv::move_to(XX/2-genv::gout.twidth("FLUSH :o")/2, 2.5*YY/4-90)<<genv::color(255,255,255)<<genv::text("FLUSH :o");
    if(logiccop->fullgetter())
        genv::gout<<genv::move_to(XX/2-genv::gout.twidth("FULL *_*")/2, 2.5*YY/4-90)<<genv::color(255,255,255)<<genv::text("FULL *_*");
    if(logiccop->pokergetter())
        genv::gout<<genv::move_to(XX/2-genv::gout.twidth("FOUR OF A KIND ^o^")/2, 2.5*YY/4-90)<<genv::color(255,255,255)<<genv::text("FOUR OF A KIND ^o^");
    if(logiccop->szinsorgetter())
        genv::gout<<genv::move_to(0, 2.5*YY/4-90)<<genv::color(0,255,255)<<genv::text("STRAIGHTFLUSH");
    if(logiccop->royal_flushgetter())
        genv::gout<<genv::move_to(XX/2-genv::gout.twidth("ROYAL FLUSH")/2, 2.5*YY/4-90)<<genv::color(255,223,0)<<genv::text("ROYAL FLUSH");
}

