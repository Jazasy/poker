#ifndef GAMELOGIC_HPP_INCLUDED
#define GAMELOGIC_HPP_INCLUDED
#include <vector>
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
};

#endif // GAMELOGIC_HPP_INCLUDED
