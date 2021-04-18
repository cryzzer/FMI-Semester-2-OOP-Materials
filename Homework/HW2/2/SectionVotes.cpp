#include "SectionVotes.hpp"

SectionVotes::SectionVotes() {
	partyVotes.push_back(0);
	partyVotes.push_back(0);
	partyVotes.push_back(0);
}
SectionVotes::SectionVotes(int party1Votes, int party2Votes, int party3Votes) {
	partyVotes.push_back(party1Votes);
	partyVotes.push_back(party2Votes);
	partyVotes.push_back(party3Votes);
}

int SectionVotes::votesForParty(Party party) const {//getter for the votes for a certain party
	return partyVotes[party];
}


std::ostream& operator<<(std::ostream& out, const SectionVotes& section) {
	out << section.votesForParty(PARTY1) << ' ' << section.votesForParty(PARTY2) << ' ' << section.votesForParty(PARTY3) << '\n';
	//entering the information into the `ostream` with this format
	return out;
}

std::istream& operator>>(std::istream& in, SectionVotes& section) {
	in >> section.partyVotes[PARTY1];
	in >> section.partyVotes[PARTY2];
	in >> section.partyVotes[PARTY3];

	//extracting information
	return in;
}