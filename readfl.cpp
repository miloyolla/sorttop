#include "readfl.hpp"
// Rayner stuff:
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

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

void ReadCsv(const std::string &path, std::vector<data> &dataVec)
{
    // by Rayner
    std::ifstream stream(path);
    if (!stream)
    {
        std::cerr << "Erro ao abrir o arquivo" << std::endl;
        return;
    }

    std::string fileLine;
    // ignorando a primeira linha
    std::getline(stream, fileLine);
    // passando por cada linha
    while (std::getline(stream, fileLine))
    {
        std::stringstream line(fileLine);
        std::string result;

        csvio::data data;
        csvio::dataFields curField = ano;
        // divindo a linha entre virgulas
        // result: cada item separado por virgula
        while (std::getline(line, result, ','))
        {
            switch (curField)
            {
            case ano:
                data.ano = result;
                curField = statusProc;
                break;
            case statusProc:
                data.statusProc = result;
                curField = superintend;
                break;
            case superintend:
                data.superintend = result;
                curField = numeroProc;
                break;
            case numeroProc:
                data.numeroProc = result;
                curField = autoInfra;
                break;
            case autoInfra:
                data.autoInfra = result;
                curField = cpfCnpj;
                break;
            case cpfCnpj:
                data.cpfCnpj = result;
                curField = razSocial;
                break;
            case razSocial:
                data.razSocial = result;
                curField = vencimento;
                break;
            case vencimento:
                data.vencimento = result;
                curField = valorMultaApl;
                break;
            case valorMultaApl:
                data.valorMultaApl = result;
                break;
            }
        }
        dataVec.push_back(data);
    }
}
void fillIndex(std::vector<index> &indexVec, const std::vector<data> &dataVec, dataFields field)
{
    index index;

    switch (field)
    {
    case ano:
        for (int i = 0; i < dataVec.size; i++)
        {
            index.campo = dataVec[i].ano;
            index.index = i;
            indexVec.push_back(index);
        }
        return;
    case statusProc:
        for (int i = 0; i < dataVec.size; i++)
        {
            index.campo = dataVec[i].statusProc;
            index.index = i;
            indexVec.push_back(index);
        }
        return;
    case superintend:
        for (int i = 0; i < dataVec.size; i++)
        {
            index.campo = dataVec[i].superintend;
            index.index = i;
            indexVec.push_back(index);
        }
        return;
    case numeroProc:
        for (int i = 0; i < dataVec.size; i++)
        {
            index.campo = dataVec[i].numeroProc;
            index.index = i;
            indexVec.push_back(index);
        }
        return;
    case autoInfra:
        for (int i = 0; i < dataVec.size; i++)
        {
            index.campo = dataVec[i].autoInfra;
            index.index = i;
            indexVec.push_back(index);
        }
        return;
    case cpfCnpj:
        for (int i = 0; i < dataVec.size; i++)
        {
            index.campo = dataVec[i].cpfCnpj;
            index.index = i;
            indexVec.push_back(index);
        }
        return;
    case razSocial:
        for (int i = 0; i < dataVec.size; i++)
        {
            index.campo = dataVec[i].razSocial;
            index.index = i;
            indexVec.push_back(index);
        }
        return;
    case vencimento:
        for (int i = 0; i < dataVec.size; i++)
        {
            index.campo = dataVec[i].vencimento;
            index.index = i;
            indexVec.push_back(index);
        }
        return;
    case valorMultaApl:
        for (int i = 0; i < dataVec.size; i++)
        {
            index.campo = dataVec[i].valorMultaApl;
            index.index = i;
            indexVec.push_back(index);
        }
        return;
    }
}
} // namespace csvio
