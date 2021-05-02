/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Danail Nenkov
* @idnumber 62518
* @task 1
* @compiler GCC
*/


#include <iostream>
#include "pendulumCard.hpp"
#include "deck.hpp"
#include "duelist.hpp"

int main() {

///testing for correct saving of deck
//    MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 3000,
//                       2500);
//    MonsterCard magician("Dark Magician", "The ultimate wizard.", 2500, 2100);
//    MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.",
//                     CardType::SPELL);
//    MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", CardType::TRAP);
//    PendulumCard timeGazer("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards", 1200, 600,
//                           CardType::BUFF, 8);
//    MonsterCard gilford("Gilford The Lightning",
//                        "If summonned this way(by tributing 3 monsters): Destroy all monsters your opponent controls.",
//                        2800, 1400);
//
//    dragon.print();
//    std::cout << "\n\n";
//    magician.print();
//    std::cout << "\n\n";
//    swords.print();
//    std::cout << "\n\n";
//    cylinder.print();
//    std::cout << "\n\n";
//    timeGazer.print();
//    std::cout << "\n\n";
//
//    Deck d1("Test one");
//    d1.addNewMonster(dragon);
//    d1.addNewMonster(magician);
//    d1.addNewSpell(swords);
//    d1.addNewSpell(cylinder);
//    d1.addNewPendulum(timeGazer);
//
//    Duelist duelist1("Meric Ishtar", d1);
//    duelist1.display();
//    std::cout << "====================================\n\n";
//
//
//
//    duelist1.getDeck().addNewMonster(gilford);
//
//    std::cout << "====================================\n\n";
//    duelist1.display();
/////Here I didn't add 'test1.txt' file to the committed project , because either way the file should be empty and this way it will create a new file
//    std::cout << duelist1.saveDeck("test1.txt");


///Testing for correct istream for MonsterCard
//    MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 3000,
//                       2500);
/////Here I didn't add 'file.txt' file to the committed project , because either way the file should be empty and this way it will create a new file
//    std::ofstream writeFile ("file.txt");
//    if(!writeFile.is_open()){
//        std::cout << "Error!\n";
//    }
//    writeFile << dragon;
//
//    writeFile.close();
//
//    MonsterCard acceptDragon;
//
//    std::ifstream readFile ("file.txt", std::ios::app);
//    if(!readFile.is_open()){
//        std::cout << "Error! number 2\n";
//    }
//
//    readFile >> acceptDragon;
//
//    readFile.close();
//
//    acceptDragon.print();


///Test for correct reading from file(loading deck)
//    Duelist loadingDeck("Joey");
//
//    loadingDeck.loadDeck("TestDeck for Loading.txt");
//
//    loadingDeck.getDeck().printDeck();


///Test that checks if a card is already added to the deck 3 times, and if it is, you can't add it
//    Duelist moreCopies("Already exists");
//
//    MonsterCard parasite("Parasite", "When added tou your deck, creates many copies of it in your deck!", 0, 0);
//    moreCopies.getDeck().addNewMonster(parasite);
//    moreCopies.getDeck().addNewMonster(parasite);
//    moreCopies.getDeck().addNewMonster(parasite);
//    moreCopies.getDeck().addNewMonster(parasite);
//
//    MagicCard magicParasite("MagicParasite",
//                            "When added tou your deck, replaces all your cards with magic cards of this type!",
//                            CardType::TRAP);
//    moreCopies.getDeck().addNewSpell(magicParasite);
//    moreCopies.getDeck().addNewSpell(magicParasite);
//    moreCopies.getDeck().addNewSpell(magicParasite);
//    moreCopies.getDeck().addNewSpell(magicParasite);
//
//    PendulumCard combo("Combination Parasite",
//                       "Takes the effect of the Monster Card 'Parasite' and the Spell Card 'MagicParasite'!", 1, 1,
//                       CardType::SPELL, 9);
//
//    moreCopies.getDeck().addNewPendulum(combo);
//    moreCopies.getDeck().addNewPendulum(combo);
//    moreCopies.getDeck().addNewPendulum(combo);
//    moreCopies.getDeck().addNewPendulum(combo);
//
//    std::cout << moreCopies;
}
