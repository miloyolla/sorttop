#include "readfl.hpp"

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
void strcp(char *src, char *dest, int strsize);

void fillVector(char *buffer, vector<data> &dataVec);

void fillIndexVector(vector<data> &dataVec , vector<index> &indVector);


void ReadCsv(char *path, vector<data> &dataVec)
{
    FILE *fp;
    char *buffer;
    long fSize;
    long result;
    fp = fopen(path, "r");
    if (fp == NULL)
    {
        fputs("File error", stderr);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    fSize = ftell(fp);
    rewind(fp);
    buffer = (char *)malloc(sizeof(char) * fSize);
    if (buffer == NULL)
    {
        fputs("Memory error", stderr);
        return;
    }
    result = fread(buffer, 1, fSize, fp);

    if (result != fSize)
    {
        fputs("Reading error", stderr);
        return;
    }

    fclose(fp);
    fillVector(buffer, dataVec);
    free(buffer);
}
void fillVector(char *buffer, vector<data> &dataVec)
{

    data data;
    char str[128];
    int j = 0;
    dataFields field = ano;
    for (int i = 0; buffer[i]; i++)
    {
        // a primeira struct do vector é o identificador de cada coluna no csv
        switch (buffer[i])
        {
        case ';':
            printf("inicio de uma nova celula\n");
            switch (field)
            {
            case ano:
                strcp(str, data.ano, 4);
                field = statusProc;
                break;
            case statusProc:
                strcp(str, data.statusProc,64);
                field = superintend;
                break;
            case superintend:
                strcp(str, data.superintend,32);
                field = numeroProc;
                break;
            case numeroProc:
                strcp(str, data.numeroProc,32);
                field = autoInfra;
                break;
            case autoInfra:
                strcp(str, data.autoInfra,32);
                field = cpfCnpj;
                break;
            case cpfCnpj:
                strcp(str, data.cpfCnpj,32);
                field = razSocial;
                break;
            case razSocial:
                strcp(str, data.razSocial,128);
                field = vencimento;
                break;
            case vencimento:
                strcp(str, data.vencimento,16);
                field = valorMultaApl;
                break;
    
            }
            j = 0;
            break;
        case '\n':
            strcp(str, data.valorMultaApl,32); // copia a ultima celula para a estrutura
            field = ano; // reseta o enumarator para o inicio da linha
            dataVec.push_back(data);
            //adicionar o data ao vector
            j = 0;
            break;
        default:
            buffer[i] = str[j];
            // adiciona o dado a um campo do data
            break;
        }
    }
}
void strcp(char *src, char *dest, int strsize)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    while  (i > strsize )
    {
        i++;
        dest[i] = '\0';
    }
}
} // namespace csvio