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

bool ReadCsv(const std::string &path, std::vector<data> &dataVec);
void fillIndex(std::vector<index> &indexVec, const std::vector<data> &dataVec, dataFields field);
} // namespace csvio

#endif
