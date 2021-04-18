#pragma once

#include <fstream>
#include <vector>
#include "SectionVotes.hpp"

class ElectionResultsDatabase
{
    
public:
	ElectionResultsDatabase();
    
	void addResultsFromFile(const char* filename);

	int numberOfSections() const;

	int votesForParty(Party) const;

	Party winningParty() const;
    
	friend std::ostream& operator<<(std::ostream& out, const ElectionResultsDatabase& section);
	friend std::istream& operator>>(std::istream& in, ElectionResultsDatabase& section);

private:
	std::vector<SectionVotes> allVotes;
	int sectionNumber;
};


std::ostream& operator<<(std::ostream& out, const ElectionResultsDatabase& section);
std::istream& operator>>(std::istream& in, ElectionResultsDatabase& section);