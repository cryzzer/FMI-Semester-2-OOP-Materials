#pragma once
#include <vector>
#include <fstream>

enum Party
{
    PARTY1 = 0,
    PARTY2 = 1,
    PARTY3 = 2,
};

class SectionVotes
{
    
public:
    SectionVotes();
    SectionVotes(int party1Votes, int party2Votes, int party3Votes);
    
    int votesForParty(Party party) const;//getter
    
    friend std::istream& operator>>(std::istream& in, SectionVotes& section);
private:
    std::vector<int> partyVotes;
};

std::ostream& operator<<(std::ostream& out, const SectionVotes& section);
std::istream& operator>>(std::istream& in, SectionVotes& section);

