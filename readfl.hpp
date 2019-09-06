/////////////////////////////////////////////////////
//    UFRJ - IM/IMA
//    TMA-B
//    Mileny Loyolla
//    Vitor Pavani
//    Rodrigo Chueri
//    DATA: 06/09/2019
/////////////////////////////////////////////////////

#ifndef READ_FILE
#define READ_FILE

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string.h>
#include "data.hpp"

namespace csvio
{
enum dataFields
{
    ano,
    statusProc,
    superintend,
    numeroProc,
    autoInfra,
    cpfCnpj,
    razSocial,
    vencimento,
    valorMultaApl
};

bool ReadCsv(const std::string &path, std::vector<data> &dataVec, char separator);
void fillIndex(std::vector<index> &indexVec, const std::vector<data> &dataVec, dataFields field);
} // namespace csvio

#endif
