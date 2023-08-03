#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <sstream>
# include <cstdlib>
# include <map>

class BitcoinExchange{
    private:
        std::string file;
        std::map<std::string, double> db;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &ref);
        BitcoinExchange& operator= (const BitcoinExchange& other);
        ~BitcoinExchange();
        BitcoinExchange(const std::string filename);

    private:
        int initDatabase(const std::string filename);
    public:
        std::map<std::string, double> getDatabase(void);
        std::string getFilename(void);
        void printDB(void);
        void execute(std::string fname);
};

#endif