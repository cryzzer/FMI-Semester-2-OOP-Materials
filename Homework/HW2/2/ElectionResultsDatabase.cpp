#include "ElectionResultsDatabase.hpp"
#include <algorithm>

ElectionResultsDatabase::ElectionResultsDatabase() : sectionNumber(0){}

void ElectionResultsDatabase::addResultsFromFile(const char* filename) {
	std::ifstream votesFile;
	votesFile.open(filename, std::ios::app);//opening the file

	votesFile >> *this;//using the already writter `operator>>` to extract the information into a vector from SectionVotes

	votesFile.close();//closing file
}

int ElectionResultsDatabase::numberOfSections() const {
	return sectionNumber;//getter for the count of sections
}

int ElectionResultsDatabase::votesForParty(Party party) const {//calculating how many votes a party has
	int totalVotes = 0;
	for (size_t i = 0; i < allVotes.size(); i++) {
		totalVotes += allVotes[i].votesForParty(party);
	}
	return totalVotes;
}

Party ElectionResultsDatabase::winningParty() const {
	//here return the party with most votes, but if 2 of them have equal votes, return the 1st party in the list
	int allVotesParty1 = votesForParty(PARTY1);
	int allVotesParty2 = votesForParty(PARTY2);
	int allVotesParty3 = votesForParty(PARTY3);

	if (allVotesParty1 == allVotesParty2 && allVotesParty1 == allVotesParty3) {
		return PARTY1;
	}
	if (allVotesParty1 == allVotesParty2 && allVotesParty1 > allVotesParty3) {
		return PARTY1;
	}
	if (allVotesParty1 == allVotesParty3 && allVotesParty1 > allVotesParty2) {
		return PARTY1;
	}
	if (allVotesParty1 == allVotesParty3 && allVotesParty1 < allVotesParty2) {
		return PARTY2;
	}
	if (allVotesParty1 == allVotesParty2 && allVotesParty1 < allVotesParty3) {
		return PARTY3;
	}
	if (allVotesParty1 > allVotesParty2 && allVotesParty1 > allVotesParty3) {
		return PARTY1;
	}

	if (allVotesParty2 == allVotesParty3 && allVotesParty2 > allVotesParty1) {
		return PARTY2;
	}
	if (allVotesParty2 == allVotesParty3 && allVotesParty2 < allVotesParty1) {
		return PARTY1;
	}
	if (allVotesParty2 > allVotesParty1 && allVotesParty2 > allVotesParty3) {
		return PARTY2;
	}
	if (allVotesParty2 > allVotesParty1 && allVotesParty2 < allVotesParty3) {
		return PARTY3;
	}

	if (allVotesParty3 > allVotesParty2 && allVotesParty3 > allVotesParty1) {
		return PARTY3;
	}
	
	return PARTY3;
}

std::ostream& operator<<(std::ostream& out, const ElectionResultsDatabase& section) {
	//entering the information from the SectionVotes vector into `ostream`
	for (size_t i = 0; i < section.allVotes.size(); i++) {
		out << section.allVotes[i];
	}
	return out;
}
std::istream& operator>>(std::istream& in, ElectionResultsDatabase& section) {
	//extraction the information from `istream` and writing it into a vector from SectionVotes
	SectionVotes temp;
	while(in >> temp) {//while there is information, extract it
		section.allVotes.push_back(temp);
		section.sectionNumber++;//adding the number of sections
	}
	return in;
}

