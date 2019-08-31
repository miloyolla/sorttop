/* 
    ARQUIVO DE DESENVOLVIMENTO

    CONTEM A FUNÇAO MAIN DE TESTES! duh

*/

#include <iostream>
#include <vector>
#include "data.hpp"
#include "readfl.hpp"

void printField(const std::vector<csvio::data> &dataVec);

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

void printField(const std::vector<csvio::data> &dataVec)
{
    std::cout << "linhas lidas: " << dataVec.size() << std::endl;
    for (auto &data : dataVec)
        std::cout << data.razSocial << " " << data.cpfCnpj << std::endl;

}
