#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
// deque + vector

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Program needs a positive integer list to work." << std::endl;
        return;
    }
    else
    {
        std::vector<std::pair<unsigned int, unsigned int>> vec;
        std::list<std::pair<unsigned int, unsigned int> > li;
        int i = 1;

        while (argv[i])
        {
            if (std::isdigit(argv[i]) && std::atoi(av[i]))
            {
                v.push_back(std::atoi(argv[i])); // faire une paire ?
                l.push_back(std::atoi(argv[i]));
            }
        }
    }
}