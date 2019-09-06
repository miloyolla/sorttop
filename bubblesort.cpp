/* UFRJ - IM/IMA
TMA-B
Mileny Loyolla
Vitor Pavani
Rodrigo Chueri

DATA: 01/03/2019
*/
#include "bubble.hpp"

void bubble(std::vector<> &index)
{
    bool troca;

    while (troca == true)
    {
        troca = false;
        std::string aux;

        for (int i = 0; i <= index.size(); i++)
        {
            if (index[i].campo > index[i + 1].campo)
            {
                troca = true;
                aux = index[i].campo;
                index[i].campo = index[i + 1].campo;
                index[i + 1].campo = aux;
            }
        }
    }
}