#ifndef READ_FILE
#define READ_FILE

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string.h>
#include "data.hpp"

namespace csvio
{
    void ReadCsv(const std::string& path, std::vector<data> &dataVec);
    void fillIndex(std::vector<index> &indexVec, const std::vector<data> &dataVec);
}

#endif
