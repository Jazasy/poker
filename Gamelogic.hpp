#ifndef GAMELOGIC_HPP_INCLUDED
#define GAMELOGIC_HPP_INCLUDED
#include <vector>
#include <string>
#include <string>

class Gamelogic
{
    std::vector<std::vector<int>> lapok;
    int zsetonok;
    bool magas_lap, par, ket_par, drill, sor, flush, full, poker, szinsor, royal_flush, semmi;
public:
    Gamelogic();
    void leoszt();
    void consolrair();
    std::vector<std::vector<int>> lapokgetter();
    std::vector<std::string> zsetongetter();
    void zsetonallit(int nyereseg_veszteseg);
    void nyeremeny(int nyereseg_veszteseg);
    void kartyaidcsere(std::vector<bool> _megtartindex);
    bool vaneilyen(std::vector<int> lapid);
    void ellenoriz();
    int darabmeghat(int keresett_szam);
    std::vector<std::vector<int>> mindenlapdarabmehat();
    int parszamlalo(std::vector<std::vector<int>> kartyaszamok);
    void drillell(std::vector<std::vector<int>> kartyaszamok);
    void kezboolkivesz();
    void drill_full_ell(std::vector<std::vector<int>> kartyaszamok);
    void pokerell(std::vector<std::vector<int>> kartyaszamok);
    bool flushell();
    bool sorell();
    bool magassorell();
    bool parboolgetter();
    bool ket_parboolgetter();
    bool drillgetter();
    bool sorgetter();
    bool flushgetter();
    bool fullgetter();
    bool pokergetter();
    bool szinsorgetter();
    bool royal_flushgetter();
    void semmiell();
    bool semmigetter();
    bool magas_lapgetter();
    void magasell();
    void zsetonalap();
    void kartyaidsetter(std::vector<std::vector<int>> alap);
    std::string legmagasabb();
    unsigned long long faktorialis(int n);
    double kombinacio(int a, int b);
    double osszeseset();
    std::string royalflushpr();
    std::string szinsorpr();
    std::string pokerpr();
    std::string flushpr();
    std::string sorpr();
    std::string magaspr();
    std::string parpr();
    std::string drillpr();
    std::string fullpr();
    std::string ketparpr();
    std::string magaslappr();

};

#endif // GAMELOGIC_HPP_INCLUDED
