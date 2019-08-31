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

    void ReadCsv(const std::string& path, std::vector<data> &dataVec)
    {
        // by Rayner
        std::ifstream stream(path);
        if(!stream)
        {
            std::cerr << "Erro ao abrir o arquivo" << std::endl;
            return;
        }

        std::string fileLine;
        // ignorando a primeira linha
        std::getline(stream, fileLine);
        // passando por cada linha
        while(std::getline(stream, fileLine))
        {
            std::stringstream line(fileLine);
            std::string result;

            csvio::data data;
            csvio::dataFields curField = ano;
            // divindo a linha entre virgulas
            // result: cada item separado por virgula
            while(std::getline(line, result, ','))
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
                    data.valorMultaApl =  result;
                    break;
                }
            }
            dataVec.push_back(data);
        }
    }

} // namespace csvio