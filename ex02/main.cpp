#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <cctype>

int areDigit(char *str)
{
    for (int i = 0; str[i]; i++)
        if(!std::isdigit(str[i]))
            return (0);
    return 1; 
}

// VECTOR //

void sortLeftPair(std::vector<std::pair<unsigned int, unsigned int>> &vec, int n) // 0 = first item || 1 = second item
{
    if (n <= 1)
        return;
    
    sortLeftPair(vec, n - 1);
    unsigned int last = vec[n - 1].first;
    int j = n - 2;
    while (j >= 0 && vec[j].first > last)
    {
        vec[j+1].first = vec[j].first;
        j--;
    }

    vec[j + 1].first = last;
}

void sortRightPair(std::vector<std::pair<unsigned int, unsigned int>> &vec, int n) // 0 = first item || 1 = second item
{
    if (n <= 1)
        return;
    
    sortRightPair(vec, n - 1);
    unsigned int last = vec[n - 1].second;
    int j = n - 2;

    while (j >= 0 && vec[j].second > last)
    {
        vec[j+1].second = vec[j].second;
        j--;
    }
    vec[j + 1].second = last;
}

std::vector<std::pair<unsigned int, unsigned int>> initPair(std::vector<unsigned int> ref)
{
    std::vector<std::pair<unsigned int, unsigned int>> ret;

    int i = 0;
    while (i < ref.size() - 1)
    {
        ret.push_back(std::make_pair(ref[i], ref[i+1]));
        i += 2;
    }
    // for (std::vector<std::pair<unsigned int, unsigned int>>::iterator it = ret.begin(); it != ret.end(); it++)
    //     if (it->first > it->second)
    //         std::swap(it->first, it->second);


    std::cout << "PAIR VECTOR\n";
    for (std::vector<std::pair<unsigned int, unsigned int>>::iterator it = ret.begin(); it != ret.end(); it++)
        std::cout << it->first << " " << it->second << std::endl;
    std::cout << "END PAIR VECTOR\n\n";
    // We sort the values of the first slots;
    sortLeftPair(ret, ret.size());
    // We do the same for the second ones;
    sortRightPair(ret, ret.size());
    return ret;
}
std::vector<unsigned int> fjSort(std::vector<unsigned int> ref)
{
    //init vector pair to make merge sort
    std::vector<std::pair<unsigned int, unsigned int>> vecPair = initPair(ref);
    std::vector<unsigned int> result;
    std::vector<unsigned int>::iterator it;

    std::vector<std::pair<unsigned int, unsigned int>>::iterator left = vecPair.begin();
    std::vector<std::pair<unsigned int, unsigned int>>::iterator right = vecPair.begin();
    while (left != vecPair.end() && right != vecPair.end())
    {
        if (left->first <= right->second)
        {
            result.push_back(left->first);
            left++;
        }
        else{
            result.push_back(right->second);
            right++;
        }
            // std::cout << "result: ";
            // for (int i = 0; i < result.size(); i++)
            //     std::cout << result[i] << " ";
            // std::cout << "\n";
    }        
    while (left != vecPair.end())
    {
        result.push_back(left->first);
        left++;
    }
    while (right != vecPair.end())
    {
        result.push_back(right->second);
        right++;
    }
    if (ref.size() % 2)
    {
        unsigned int data = ref[ref.size() - 1];
        it = result.begin();
        while (*it < data && it != result.end())
            it++;
        result.insert(it, data);
    }
    return result;
}


// DEQUE //


void sortLeftPair(std::deque<std::pair<unsigned int, unsigned int>> &vec, int n) // 0 = first item || 1 = second item
{
    if (n <= 1)
        return;
    
    sortLeftPair(vec, n - 1);
    unsigned int last = vec[n - 1].first;
    int j = n - 2;
    while (j >= 0 && vec[j].first > last)
    {
        vec[j+1].first = vec[j].first;
        j--;
    }

    vec[j + 1].first = last;
}

void sortRightPair(std::deque<std::pair<unsigned int, unsigned int>> &vec, int n) // 0 = first item || 1 = second item
{
    if (n <= 1)
        return;
    
    sortRightPair(vec, n - 1);
    unsigned int last = vec[n - 1].second;
    int j = n - 2;

    while (j >= 0 && vec[j].second > last)
    {
        vec[j+1].second = vec[j].second;
        j--;
    }
    vec[j + 1].second = last;
}

std::deque<std::pair<unsigned int, unsigned int>> initPair(std::deque<unsigned int> ref)
{
    std::deque<std::pair<unsigned int, unsigned int>> ret;

    int i = 0;
    while (i < ref.size() - 1)
    {
        ret.push_back(std::make_pair(ref[i], ref[i+1]));
        i += 2;
    }
    // for (std::deque<std::pair<unsigned int, unsigned int>>::iterator it = ret.begin(); it != ret.end(); it++)
    //     if (it->first > it->second)
    //         std::swap(it->first, it->second);


    std::cout << "PAIR deque\n";
    for (std::deque<std::pair<unsigned int, unsigned int>>::iterator it = ret.begin(); it != ret.end(); it++)
        std::cout << it->first << " " << it->second << std::endl;
    std::cout << "END PAIR deque\n\n";
    // We sort the values of the first slots;
    sortLeftPair(ret, ret.size());
    // We do the same for the second ones;
    sortRightPair(ret, ret.size());
    return ret;
}
std::deque<unsigned int> fjSort(std::deque<unsigned int> ref)
{
    //init deque pair to make merge sort
    std::deque<std::pair<unsigned int, unsigned int>> vecPair = initPair(ref);
    std::deque<unsigned int> result;
    std::deque<unsigned int>::iterator it;

    std::deque<std::pair<unsigned int, unsigned int>>::iterator left = vecPair.begin();
    std::deque<std::pair<unsigned int, unsigned int>>::iterator right = vecPair.begin();
    while (left != vecPair.end() && right != vecPair.end())
    {
        if (left->first <= right->second)
        {
            result.push_back(left->first);
            left++;
        }
        else{
            result.push_back(right->second);
            right++;
        }
            // std::cout << "result: ";
            // for (int i = 0; i < result.size(); i++)
            //     std::cout << result[i] << " ";
            // std::cout << "\n";
    }        
    while (left != vecPair.end())
    {
        result.push_back(left->first);
        left++;
    }
    while (right != vecPair.end())
    {
        result.push_back(right->second);
        right++;
    }
    if (ref.size() % 2)
    {
        unsigned int data = ref[ref.size() - 1];
        it = result.begin();
        while (*it < data && it != result.end())
            it++;
        result.insert(it, data);
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
        std::vector <unsigned int> vresult = fjSort(vec);
        std::deque <unsigned int> dresult = fjSort(deque);
        for (int i = 0; i < vresult.size(); i++)
            std::cout << vresult[i] << " ";
        std::cout << '\n';

        std::cout << "\n\n DEQUE:\n";
        for (int i = 0; i < dresult.size(); i++)
            std::cout << dresult[i] << " ";
        std::cout << '\n';
    }
    return 0;
}