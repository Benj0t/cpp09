#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <cctype>
// deque + vector

int areDigit(char *str);

std::vector<std::pair<unsigned int, unsigned int>> initPair(std::vector<unsigned int> ref)
{
    std::vector<std::pair<unsigned int, unsigned int>> ret;

    int i = 0;
    while (i < ref.size())
    {
        ret.push_back(std::make_pair(ref[i], ref[i+1]));
        i += 2;
    }

    std::cout << "PAIR VECTOR\n";
    for (std::vector<std::pair<unsigned int, unsigned int>>::iterator it = ret.begin(); it != ret.end(); it++)
        std::cout << it->first << " " << it->second << std::endl;
    std::cout << "END PAIR VECTOR\n\n";
    return ret;
}

std::vector<unsigned int> fjSort(std::vector<unsigned int> ref)
{
    //init vector pair to make merge sort
    std::vector<std::pair<unsigned int, unsigned int>> vecPair = initPair(ref);

    std::vector<unsigned int> result;

    int flag = ref.size() % 2;
    std::vector<unsigned int>::iterator it2;
    for (std::vector<std::pair<unsigned int, unsigned int>>::iterator it = vecPair.begin(); it != vecPair.end(); it++)
    {
        if (it->first > it->second)
            std::swap(it->first, it->second);
        
        if (result.empty())
        {
            result.push_back(it->first);
            result.push_back(it->second);
        }
        else{
            it2 = result.begin();
            while (*it2 < it->second && it2 != result.end())
                it2++;
            result.insert(it2, it->second);
            std::cout << "result: ";
            
            for (int i = 0; i < result.size(); i++)
                std::cout << result[i] << " ";
            std::cout << "\n";
            
            it2 = result.begin();
            while (*it2 < it->first && it2 != result.end())
                it2++;
            result.insert(it2, it->first);
            std::cout << "result: ";
            
            for (int i = 0; i < result.size(); i++)
                std::cout << result[i] << " ";
            std::cout << "\n";
            // std::cout << "TEST" << *it2 << " " <<  it->second << '\n';
        }
    }
    return result;
}


int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Program needs a positive integer list to work." << std::endl;
        return 1;
    }
    else
    {
        std::vector<unsigned int> vec;
        std::deque<unsigned int> deque;

        int i = 0;

        while (argv[++i])
        {
            if (std::atoi(argv[i]) && areDigit(argv[i]))
            {
                vec.push_back(std::atoi(argv[i])); 
                deque.push_back(std::atoi(argv[i]));
            }
            else
            {
               std::cout << "Error encountered with this entry: \"" <<argv[i] <<  "\"\nProgram needs a positive integer list to work." << std::endl;
               return 1;
            }
        }
        std::vector <unsigned int> result = fjSort(vec);
        for (int i = 0; i < result.size(); i++)
            std::cout << result[i] << " ";
        std::cout << '\n';
    }
    return 0;
}