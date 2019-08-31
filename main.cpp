/* 
    ARQUIVO DE DESENVOLVIMENTO

    CONTEM A FUNÇAO MAIN DE TESTES! duh

*/

#include <iostream>
#include <vector>
#include "data.hpp"
#include "readfl.hpp"

int main(int argc, char *argv[])
{
    std::vector<csvio::data> dataVec;
    std::vector<csvio::index> index;

    char option;
    bool reploop = true;

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
                  << "s - sair."
                  << std::endl
                  << "------------------------------------------------"
                  << std::endl
                  << "Entre com sua opção:()"
                  << std::endl;
        std::cin >> option;
        switch (option)
        {
        case 'a':
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
    

    std::cout << "linhas lidas: " << dataVec.size() << std::endl;
    for (auto &data : dataVec)
        std::cout << data.razSocial << " " << data.cpfCnpj << std::endl;

    */

    return 0;
}
