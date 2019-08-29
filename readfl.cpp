#include "readfl.hpp"

namespace csvio
{
void ReadCsv(char *path)
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
    printf("%s", buffer);
    free(buffer);
}
} // namespace csvio