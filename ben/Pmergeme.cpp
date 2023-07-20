#include "PmergeMe.hpp"

	PmergeMe::PmergeMe() {
		// Constructor
	}

	void PmergeMe::setSequence(const std::vector<int>& seq) {
		m_sequence = seq;
	}

	void PmergeMe::mergeISVector() {
		// Copy the sequence into a local vector for sorting
		std::vector<int> seqCopy = m_sequence;

		// Start the timer
		std::clock_t start = std::clock();

		// Sort the sequence using the merge-insert sort algorithm
		mergeInsertSortVector(seqCopy, 0, seqCopy.size());

		// End the timer and record the time taken
		std::clock_t end = std::clock();
		m_timeVector = static_cast<double>(end - start) / CLOCKS_PER_SEC;

		// Copy the sorted sequence into the member variable
		m_sortedSequenceVector = seqCopy;
	}


	void PmergeMe::mergeISList() {
		// Copy the sequence into a local list for sorting
		std::list<int> seqCopy(m_sequence.begin(), m_sequence.end());

		// Start the timer
		std::clock_t start = std::clock();

		// Sort the sequence using the std::list::sort member function
		mergeInsertSortList(seqCopy);


		// End the timer and record the time taken
		std::clock_t end = std::clock();
		m_timeList = static_cast<double>(end - start) / CLOCKS_PER_SEC;

		// Copy the sorted sequence into the member variable
		m_sortedSequenceList = seqCopy;
	}

	void PmergeMe::displayResults() const {
		// Display the original sequence
		std::cout << "Original sequence: ";
		for (std::vector<int>::const_iterator it = m_sequence.begin(); it != m_sequence.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		// Display the sorted sequence (vector version)
		std::cout << "Sequence sort (vector): ";
		for (std::vector<int>::const_iterator it = m_sortedSequenceVector.begin(); it != m_sortedSequenceVector.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		// Display the sorted sequence (list version)
		std::cout << "Sequence sort (list): ";
		for (std::list<int>::const_iterator it = m_sortedSequenceList.begin(); it != m_sortedSequenceList.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		// Display the sorting times for each container
		std::cout << std::fixed << std::setprecision(3);
		std::cout << "Execution time (vector): " << m_timeVector * 1000000 << " microseconds" << std::endl;
		std::cout << "Execution time (list): " << m_timeList * 1000000 << " microseconds" << std::endl;
	}