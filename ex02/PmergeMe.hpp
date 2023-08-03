#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <cctype>
#include <iomanip>
#include <time.h>
class PmergeMe
{
private:
    /* data */
public:
    PmergeMe();
    PmergeMe (const PmergeMe &ref);
    PmergeMe & operator = (const PmergeMe &ref);
    ~PmergeMe();
};

#endif