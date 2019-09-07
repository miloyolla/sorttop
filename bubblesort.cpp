/////////////////////////////////////////////////////
//    UFRJ - IM/IMA
//    TMA-B
//    Mileny Loyolla
//    Vitor Pavani
//    Rodrigo Chueri
//    DATA: 06/09/2019
/////////////////////////////////////////////////////

#include "bubble.hpp"
namespace sort 
{

void bubble(std::vector<csvio::index> &index)
{
    bool troca;

    while (troca == true)
    {
        troca = false;
        csvio::index aux;

        for (int i = 0; i <= index.size(); i++)
        {
            if (index[i].campo > index[i + 1].campo)
            {
                troca = true;
                aux = index[i];
                index[i] = index[i + 1];
                index[i + 1] = aux;
            }
        }
    }
}
}