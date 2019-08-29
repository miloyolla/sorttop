#ifndef DATA_STRUCT
#define DATA_STRUCT

struct data
{
    char ano[4];
    char statusProc[64];
    char superintend[32];
    char numeroProc[32];
    char autoInfra[32];
    char cpfCnpj[32];
    char razSocial[128];
    char vencimento[16];
    char valorMultaApl[32];
};
struct index
{
    char campo[128];
    int index;
};

#endif
