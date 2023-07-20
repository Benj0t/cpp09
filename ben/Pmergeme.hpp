#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <cstring>

class PmergeMe {
public:
	PmergeMe();
	void setSequence(const std::vector<int>& seq);
    void mergeInsertSortVector(std::vector<int>& v, size_t start, size_t end);
	void mergeISVector();
	void mergeInsertSortList(std::list<int>& l);
	void mergeISList();
	void displayResults() const;

private:
	std::vector<int> m_sequence;
	std::vector<int> m_sortedSequenceVector;
	std::list<int> m_sortedSequenceList;
	double m_timeVector;
	double m_timeList;
};

#endif