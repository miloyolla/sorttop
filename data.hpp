#ifndef DATA_STRUCT
#define DATA_STRUCT

#include <string>

namespace csvio
{
 
    struct data
    {
        std::string ano;
        std::string statusProc;
        std::string superintend;
        std::string numeroProc;
        std::string autoInfra;
        std::string cpfCnpj;
        std::string razSocial;
        std::string vencimento;
        std::string valorMultaApl;
    };
    struct index
    {
        std::string campo;
        int index;
    };
} // namespace csvio

#endif
