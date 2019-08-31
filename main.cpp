/* 
    ARQUIVO DE DESENVOLVIMENTO

    CONTEM A FUNÇAO MAIN DE TESTES! duh

*/

#include <iostream>
#include <vector>
#include "data.hpp"
#include "readfl.hpp"

void printField(const std::vector<csvio::data> &dataVec);

void chooseField(const std::vector<csvio::index> &index);

int main(int argc, char *argv[])
{
    std::vector<csvio::data> dataVec;
    std::vector<csvio::index> index;

    char option;
    bool reploop = true;
    std::string filePath;

    if (argc > 2)
    {
        csvio::ReadCsv(argv[1], dataVec);
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
            csvio::ReadCsv(filePath, dataVec);
            break;
        case 'c':
            chooseField(index);
            break;
        case 'm':

            break;
        case 'b':

            break;
        case 'p':
            printField(dataVec);
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
    /* 
    


    */

    return 0;
}
// menu para escolher o campo de ordenaçao
void chooseField(const std::vector<csvio::index> &index)
{
    bool reploop = true;
    char option;
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
                  << "##################################"
                  << std::endl
                  << "Entre com uma opção(a/p/i/n/f/c/r/v/m/s):";

        switch (option)
        {
        case 'a':

            break;
        case 'p':

            break;
        case 'i':

            break;
        case 'n':

            break;
        case 'f':

            break;
        case 'c':

            break;
        case 'r':

            break;
        case 'v':

            break;
        case 'm':

            break;

        case 's':
            reploop = false;
            break;

        default:
            std::cout << "opção inválida" << std::endl;
            break;
        }

    } while (reploop);
}

void printField(const std::vector<csvio::data> &dataVec)
{
    std::cout << "linhas lidas: " << dataVec.size() << std::endl;
    for (auto &data : dataVec)
        std::cout << data.razSocial << " " << data.cpfCnpj << std::endl;
}
