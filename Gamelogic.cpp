#include "Gamelogic.hpp"
#include <vector>
#include <time.h>
#include <string>
#include <algorithm>

#include <iostream>

Gamelogic::Gamelogic()
{
    zsetonok=10;
}

void Gamelogic::leoszt()
{
    lapok.clear();
    while(lapok.size()!=5)
    {
        int id1=rand()%4;
        int id2=rand()%13;
        std::vector<int> lapid;
        lapid.push_back(id1);
        lapid.push_back(id2);
        if(!vaneilyen(lapid))
            lapok.push_back(lapid);
    }
}

bool Gamelogic::vaneilyen(std::vector<int> lapid)
{
    if(!lapok.empty())
    {
        for(std::vector<int> v : lapok)
        {
            if(v==lapid)
                return true;
        }
    }
    return false;
}

void Gamelogic::consolrair()
{
    for(std::vector<int> lap : lapok)
    {
        std::cout<<lap[0]<<", "<<lap[1]<<std::endl;
    }
    std::cout<<std::endl;
}

std::vector<std::vector<int>> Gamelogic::lapokgetter()
{
    return lapok;
}

std::vector<std::string> Gamelogic::zsetongetter()
{
    std::vector<std::string> v = {std::to_string(zsetonok)};
    return v;
}

void Gamelogic::zsetonallit(int nyereseg_veszteseg)
{
    zsetonok-=nyereseg_veszteseg;
}

void Gamelogic::nyeremeny(int nyereseg_veszteseg)
{
    if(magas_lap)
        zsetonok+=static_cast<int>(nyereseg_veszteseg/2);
    if(par)
        zsetonok+=static_cast<int>(nyereseg_veszteseg*1);
    if(ket_par)
        zsetonok+=static_cast<int>(nyereseg_veszteseg*2);
    if(drill)
        zsetonok+=static_cast<int>(nyereseg_veszteseg*3);
    if(sor)
        zsetonok+=static_cast<int>(nyereseg_veszteseg*4);
    if(flush)
        zsetonok+=static_cast<int>(nyereseg_veszteseg*5);
    if(full)
        zsetonok+=static_cast<int>(nyereseg_veszteseg*6);
    if(poker)
        zsetonok+=static_cast<int>(nyereseg_veszteseg*7);
    if(szinsor)
        zsetonok+=static_cast<int>(nyereseg_veszteseg*10);
    if(royal_flush)
        zsetonok+=static_cast<int>(nyereseg_veszteseg*20);
}

void Gamelogic::kartyaidcsere(std::vector<bool> _megtartindex)
{
    for(int i=0; i<5; i++)
    {
        if(!_megtartindex[i])
        {
            int id1=rand()%4;
            int id2=rand()%13;
            std::vector<int> lapid;
            lapid.push_back(id1);
            lapid.push_back(id2);
            if(!vaneilyen(lapid))
                lapok[i]=lapid;
        }
    }
}

void Gamelogic::kezboolkivesz()
{
    magas_lap=false, par=false, ket_par=false, drill=false, sor=false, flush=false, full=false, poker=false, szinsor=false, royal_flush = false, semmi = false;
}

int Gamelogic::parszamlalo(std::vector<std::vector<int>> kartyaszamok)
{
    int szamlalo=0;
    for(std::vector<int> v : kartyaszamok)
    {
        if(v[1]==2)
            szamlalo++;
    }
    return szamlalo;
}

void Gamelogic::drill_full_ell(std::vector<std::vector<int>> kartyaszamok)
{
    for(std::vector<int> v : kartyaszamok)
    {
        if(v[1]==3 && parszamlalo(kartyaszamok)==0)
            drill=true;
        if(v[1]==3 && parszamlalo(kartyaszamok)==1)
        {
            par=false;
            drill=false;
            full=true;
        }
    }
}

bool Gamelogic::flushell()
{
    for(std::vector<int> v : lapok)
    {
        if(v[0] != lapok[0][0])
            return false;
    }
    return true;
}

void Gamelogic::pokerell(std::vector<std::vector<int>> kartyaszamok)
{
    for(std::vector<int> v : kartyaszamok)
    {
        if(v[1]==4)
            poker=true;
    }
}

bool Gamelogic::sorell()
{
    std::vector<int> lapokszammal = {lapok[0][1], lapok[1][1], lapok[2][1], lapok[3][1], lapok[4][1]};
    std::sort(lapokszammal.begin(), lapokszammal.end());
    for(int i=0; i<4; i++)
    {
        if(lapokszammal[i]+1 != lapokszammal[i+1])
        {
            return false;
        }
    }
    return true;
}

bool Gamelogic::magassorell()
{
    std::vector<int> lapokszammal = {lapok[0][1], lapok[1][1], lapok[2][1], lapok[3][1], lapok[4][1]};
    std::sort(lapokszammal.begin(), lapokszammal.end());
    if(lapokszammal[0]==8)
    {
        for(int i=0; i<4; i++)
        {
            if(lapokszammal[i]+1 != lapokszammal[i+1])
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

void Gamelogic::semmiell()
{
    if(!magas_lap && !par && !ket_par && !drill && !sor && !flush && !full && !poker && !szinsor && !royal_flush)
        semmi = true;
    else
        semmi = false;
}

void Gamelogic::magasell()
{
    if(!par && !ket_par && !drill && !sor && !flush && !full && !poker && !szinsor && !royal_flush)
    {
        for(std::vector<int> v : lapok)
        {
            if(v[1]>=11)
            {
                magas_lap = true;
            }
        }
    }
}

void Gamelogic::ellenoriz()
{
    std::vector<std::vector<int>> kartyaszamok = mindenlapdarabmehat();
    if(parszamlalo(kartyaszamok)==1)
        par=true;
    if(parszamlalo(kartyaszamok)==2)
        ket_par=true;
    drill_full_ell(kartyaszamok);
    sor = sorell();
    flush=flushell();
    pokerell(kartyaszamok);
    if(sorell() && flushell() && !magassorell())
        szinsor=true;
    if(magassorell() && flushell())
        royal_flush=true;
    magasell();
    semmiell();
}

std::vector<std::vector<int>> Gamelogic::mindenlapdarabmehat()
{
    std::vector<std::vector<int>> kartyaszamok;
    for(int i=0; i<13; i++)
    {
        if(darabmeghat(i)!=0)
        {
            std::vector<int> kartyaszam;
            kartyaszam.push_back(i);
            kartyaszam.push_back(darabmeghat(i));
            kartyaszamok.push_back(kartyaszam);
            //std::cout<<i+2<<":    "<<darabmeghat(i)<<std::endl;
        }
    }
    //std::cout<<std::endl;
    return kartyaszamok;
}

int Gamelogic::darabmeghat(int keresett_szam)
{
    int szamlalo = 0;
    for(std::vector<int> v : lapok)
    {
        if(v[1]==keresett_szam)
            szamlalo++;
    }
    return szamlalo;
}



bool Gamelogic::parboolgetter()
{
    return par;
}

bool Gamelogic::ket_parboolgetter()
{
    return ket_par;
}

bool Gamelogic::drillgetter()
{
    return drill;
}

bool Gamelogic::sorgetter()
{
    return sor;
}

bool Gamelogic::flushgetter()
{
    return flush;
}

bool Gamelogic::fullgetter()
{
    return full;
}

bool Gamelogic::pokergetter()
{
    return poker;
}

bool Gamelogic::szinsorgetter()
{
    return szinsor;
}

bool Gamelogic::royal_flushgetter()
{
    return royal_flush;
}

bool Gamelogic::semmigetter()
{
    return semmi;
}

bool Gamelogic::magas_lapgetter()
{
    return magas_lap;
}
