#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

#include "BitcoinExchange.hpp"
using namespace std;
 
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        if (argc > 2)
            std::cout << "Wrong nomber of arguments\n";
        else
        {
            std::cout << "Error: could not open file." << std::endl;
        }
        return 1;
    }
    
    BitcoinExchange btc("data.csv");
    btc.execute(argv[1]);
    return 0;

}
