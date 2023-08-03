#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref)
{
    *this = ref;
}

BitcoinExchange::BitcoinExchange(const std::string filename)
{
    this->file = filename;
    if (initDatabase(filename))
    {
        throw std::invalid_argument("Invalid database file name");
    }

}
BitcoinExchange::~BitcoinExchange(void)
{

}

BitcoinExchange& BitcoinExchange::operator= (const BitcoinExchange& other)
{
    std::map<std::string, double>::const_iterator it = other.db.begin();
    while(it != other.db.end())
    {
        db[it->first] = it->second;
        ++it;
    }
    return *this;
}

std::map<std::string, double> BitcoinExchange::getDatabase()
{
    return this->db;
}

std::string BitcoinExchange::getFilename(void)
{
    return this->file;
}

int BitcoinExchange::initDatabase(const std::string filename)
{
	std::string line, date, value;
	std::ifstream file(filename.c_str());

    if(file.is_open())
	{
		while(std::getline(file, line))
		{
			std::stringstream str(line);
            if (getline(str, date, ',') && getline(str, value, ','))
			{
                db[date] = atof(value.c_str());
            }
	    }
        return 0;
	}
    return 1;
}


void BitcoinExchange::printDB()
{
    std::map<std::string, double>::const_iterator it = this->db.begin();
    while(it != this->db.end())
    {
        std::cout << it->first << " | " << it->second << "\n";
        it++;
    }
}

/*
• The program name is btc.
• Your program must take a file as argument.
• Each line in this file must use the following format: "date | value".
• A valid date will always be in the following format: Year-Month-Day.
• A valid value must be either a float or a positive integer between 0 and 1000
*/

bool    checkFormatDate(std::string date)
{
    int i = 0;

    while (i < 4)
        if (!std::isdigit(date[i++]))
            return false;
    if (date[i++] != '-')
        return false;
    while (i < 7)
        if (!std::isdigit(date[i++]))
            return false;
    if (date[i++] != '-')
        return false;
    while (i < 10)
        if (!std::isdigit(date[i++]))
            return false;
    return true;

}

int     getValueIndex(std::string line)
{
    int i = 0;
    while (line[i] && line[i] != '|')
       i++;
    while (line[i] && !std::isdigit(line[i]) && line[i] != '-' && line[i] != '+')
        i++;
    if (!line[i--])
        return 0;
    return i;
}

bool    checkDate(std::string &line)
{
    std::string date;
    std::stringstream str(line);


    if (checkFormatDate(line) == false)
        return false;
    //year
    if (std::getline(str, date, '-'))
    {
        double n = atof(date.c_str());
        if (n < 1000 || n > 3000)
            return false;
    }
    //month
    if (std::getline(str, date, '-'))
    {
        double n = atof(date.c_str());
        if (n < 1 || n > 12)
            return false;
    }
    //day
    if (std::getline(str, date, '-'))
    {
        double n = atof(date.c_str());
        if (n < 1 || n > 31) // Please be kind, I know february has only 28 days and half months 30 :)
            return false;
    }
    return true;
}

bool    checkValue(std::string val)
{
    double nb = atof(val.c_str());
    if (nb < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (nb > 1000)
    {
        std::cout << "Error: too large number." << std::endl;
        return false;
    }
    return true;
}

bool    parseLine(std::string line)
{
    int i = getValueIndex(line);
    if (checkDate(line) == false || i == 0)
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return false;
    }
    if (checkValue(line.c_str() + i) == false)
        return false;
    return true;
}

std::string getClosestDate(std::string date, std::map<std::string, double>db)
{
    std::map<std::string, double>::const_iterator it = db.begin();
    std::string tmp;
    if (it != db.end())
        tmp = it->first;
    while (it != db.end())
    {
        if (it->first > date)
        {
            if (tmp > date)
                return std::string();
            return tmp;
        }
        tmp = it->first;
        it++;
    }
    if (tmp > date)
        return(std::string());
    return it->first;
}

void    BitcoinExchange::execute(std::string fname)
{
    double nb;
	std::string line, date, value;
    std::ifstream file(fname.c_str());


    if (file.is_open())
    {
        std::getline(file, line);
        while (std::getline(file, line))
        {
            if (parseLine(line) == true)
            {
                std::stringstream str(line);
                getline(str, date, ' ');
                std::string dbKey = getClosestDate(date, db);
                if (dbKey.empty())
                    std::cout << "Error: too old date for the database => " << date << std::endl;
                else
                {
                    nb = std::atof(line.c_str() + getValueIndex(line));
                    std::cout << date << " => " << nb << " = " << (nb * db[dbKey]) << std::endl;
                }
                
            }
       }
    }
    else
    {
        throw std::invalid_argument("Could not open the input file");
    }

}