#include <iostream>
#include "SectionVotes.hpp"
#include "ElectionResultsDatabase.hpp"

int main()
{
    /*Test 1*/

    SectionVotes sec1(1, 2, 3);
    SectionVotes sec2(4, 5, 6);

    std::ofstream test1;
    test1.open("Sample.txt");

    test1 << sec1;
    test1 << sec2;

    test1.close();

    SectionVotes sec3;
    SectionVotes sec4;

    std::ifstream test2;
    test2.open("Sample.txt");

    test2 >> sec3;
    test2 >> sec4;

    std::cout << sec3 << '\n';
    std::cout << sec4 << '\n';

    ElectionResultsDatabase testObj;

    std::ifstream obj1File;
    obj1File.open("Sample.txt", std::ios::app);

    obj1File >> testObj;

    obj1File.close();

    std::cout << testObj;

    std::ofstream obj2File;
    obj2File.open("Sample2.txt");

    obj2File << testObj;

    obj2File.close();


    /*Test 2*/

    //ElectionResultsDatabase db;
    //db.addResultsFromFile("example.txt");
    //std::cout << db.votesForParty(PARTY1) << "\n"; // връща 50
    //std::cout << db.votesForParty(PARTY2) << "\n"; // връща 60
    //std::cout << db.votesForParty(PARTY3) << "\n"; // връща 40
    //std::cout << db.winningParty() << "\n"; // връща PARTY2
    //std::cout << db.numberOfSections() << "\n"; // връща 

}


