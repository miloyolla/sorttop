#include "readfl.hpp"

namespace csvio
{

void fillVector(char *buffer, vector<data> dataVec);

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
    // o buffer ja contem todo o arquivo de texto na memoria
    // apartir daqui eu ja posso trabalhar com ele
    fillVector(buffer, dataVec);
    
    free(buffer);
}
void fillVector(char *buffer, vector<data> dataVec)
{
    for (int i = 0; buffer[i]; i++)
    {
        printf("%c\n", buffer[i]);
        // aqui entra o código de montar as estruturas
    }
}
} // namespace csvio