/* 





*/



#include <iostream>
#include <vector>
#include "data.hpp"
#include "readfl.hpp"

void printField(const std::vector<csvio::index> &index);

bool chooseField(std::vector<csvio::index> &indexVec , const std::vector<csvio::data> &dataVec);

int main(int argc, char *argv[])
{
    std::vector<csvio::data> dataVec;
    std::vector<csvio::index> index;

    char option;
    bool reploop = true;
    bool hasField = false;
    bool hasFile = false;

    std::string filePath;

    if (argc > 2)
    {
        hasFile = csvio::ReadCsv(argv[1], dataVec);
    }
    // basic REPL menu
    do
    {

        std::cout << "------------------------------------------------"
                  << std::endl
                  << "a - ler um arquivo."
                  << std::endl
                  << "c - escolher campo de ordenação. "
                  << std::endl
                  << "m - ordenar com merge sort"
                  << std::endl
                  << "b - ordenar com bubble sort"
                  << std::endl
                  << "p - imprimir o arquivo"
                  << std::endl
                  << "s - sair."
                  << std::endl
                  << "------------------------------------------------"
                  << std::endl
                  << "Entre com uma opção:(a/c/m/b/s): ";
        std::cin >> option;
        switch (option)
        {
        case 'a':
            std::cout << "Digite o caminho para o arquivo: ";
            std::cin >> filePath;
            hasFile = csvio::ReadCsv(filePath, dataVec);
            break;
        case 'c':
            if (hasFile)
            {
            hasField = chooseField(index, dataVec);
            }
            else
            {
            std::cout << "nenhum arquivo lido. " << std::endl;
            }
        
            break;
        case 'm':
            if (hasField)
            {
                std::cout << "Ainda Não implementado.";
            }
            else
            {
                std::cout << "Nenhum campo selecionado.";
            }
            break;
        case 'b':
            if (hasField)
            {
                std::cout << "Ainda Não implementado.";
            }
            else
            {
                std::cout << "Nenhum campo selecionado.";
            }
            break;
        case 'p':
            if (hasField)
            {
                printField(index);
            }
            else
            {
                std::cout << "Nenhum campo selecionado.";
            }
            
            break;
        case 's':
            reploop = false;
            break;

        default:
            std::cout << "opção inválida" << std::endl;
            break;
        }
        std::cout << " " << std::endl;
    } while (reploop);



    return 0;
}
// menu para escolher o campo de ordenaçao
bool chooseField(std::vector<csvio::index> &indexVec , const std::vector<csvio::data> &dataVec)
{
    bool reploop = true;
    char option;
    csvio::dataFields campo;
    do
    {
        std::cout << "##################################"
                  << std::endl
                  << "escolha um campo de ordenação:"
                  << std::endl
                  << "a - ano."
                  << std::endl
                  << "p - status do processo."
                  << std::endl
                  << "i - super intendência."
                  << std::endl
                  << "n - numero do processo."
                  << std::endl
                  << "f - auto infração."
                  << std::endl
                  << "c - cpf / cnpj."
                  << std::endl
                  << "r - razão social."
                  << std::endl
                  << "v - vencimento."
                  << std::endl
                  << "m - valor da multa aplicada."
                  << std::endl
                  << "s - sair"
                  << std::endl
                  << "##################################"
                  << std::endl
                  << "Entre com uma opção(a/p/i/n/f/c/r/v/m/s):";
        std::cin >> option;
        switch (option)
        {
        case 'a':
            reploop = false;
            campo = csvio::dataFields::ano;
            indexVec.clear();
            fillIndex(indexVec, dataVec, campo);
            break;
        case 'p':
            reploop = false;
            campo = csvio::dataFields::statusProc;
            indexVec.clear();
            fillIndex(indexVec, dataVec, campo);

            break;
        case 'i':
            reploop = false;
            campo = csvio::dataFields::superintend;
            indexVec.clear();
            fillIndex(indexVec, dataVec, campo);

            break;
        case 'n':
            reploop = false;
            campo = csvio::dataFields::numeroProc;
            indexVec.clear();
            fillIndex(indexVec, dataVec, campo);

            break;
        case 'f':
            reploop = false;
            campo = csvio::dataFields::autoInfra;
            indexVec.clear();
            fillIndex(indexVec, dataVec, campo);

            break;
        case 'c':
            reploop = false;
            campo = csvio::dataFields::cpfCnpj;
            indexVec.clear();
            fillIndex(indexVec, dataVec, campo);

            break;
        case 'r':
            reploop = false;
            campo = csvio::dataFields::razSocial;
            indexVec.clear();
            fillIndex(indexVec, dataVec, campo);

            break;
        case 'v':
            reploop = false;
            campo = csvio::dataFields::vencimento;
            indexVec.clear();
            fillIndex(indexVec, dataVec, campo);

            break;
        case 'm':
            reploop = false;
            campo = csvio::dataFields::valorMultaApl;
            indexVec.clear();
            fillIndex(indexVec, dataVec, campo);
            break;

        case 's':
            return false;

        default:
            std::cout << "opção inválida" << std::endl;
            break;
        }

    } while (reploop);
    return true;
}

void printField(const std::vector<csvio::index> &index)
{
    std::cout << "linhas lidas: " << index.size() << std::endl;
    for (int i = 0; i < index.size(); i++)
    {
        std::cout <<index[i].index << " - " << index[i].campo << std::endl;
    }
    
}
