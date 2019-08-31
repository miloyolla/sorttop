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
    
    csvio::ReadCsv(argv[1], dataVec);
    
    std::cout << "linhas lidas: " << dataVec.size() << std::endl;
    for (auto& data : dataVec)
        std::cout << data.razSocial << " " << data.cpfCnpj << std::endl;

    return 0;
}
