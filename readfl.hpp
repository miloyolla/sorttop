#ifndef READ_FILE
#define READ_FILE

#include <cstdio>
#include <cstdlib>
#include <vector>
#include "data.h"

using namespace std;
namespace csvio
{
void ReadCsv(char *path, vector<data> &dataVec);
}

#endif
