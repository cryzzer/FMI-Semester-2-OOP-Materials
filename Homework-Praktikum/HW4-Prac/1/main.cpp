/**
* Solution to homework assignment 4
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
#include <typeinfo>
#include <vector>

void test1() {///shuffle test
    Deck deck("Test1");
    deck.addCard(new MonsterCard("black wizard", "does nothing", 2, 69, 420));
    deck.addCard(new MagicCard("mirror", "portraits yourself", 3, CardType::BUFF));
    deck.addCard(new PendulumCard("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards", 3, 1200, 600,
                                  CardType::SPELL, 8));

    std::cout << deck.monsterCount() << " " << deck.spellCount() << " " << deck.pendulumCount() << std::endl;
    deck.printDeck();

    deck.setCard(1,new MonsterCard("change", "changes card",1,1,1));
    deck.setCard(0,new MonsterCard("change", "changes card",1,1,1));

    std::cout << deck.monsterCount() << " " << deck.spellCount() << " " << deck.pendulumCount() << std::endl;
    deck.printDeck();

    deck.shuffle();
    std::cout << "After shuffle====\n\n";
    deck.printDeck();

    deck.shuffle();
    std::cout << "After shuffle222222====\n\n";
    deck.printDeck();

    deck.setDeckInOrder();
    std::cout << "After setting in order====\n\n";
    deck.printDeck();

    std::cout << "\n\n";
    std::cout << deck;
};

void test2() {///testing for correct saving of deck

    MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 25, 3000,
                       2500);
    MonsterCard magician("Dark Magician", "The ultimate wizard.", 24, 2500, 2100);
    MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", 30,
                     CardType::SPELL);
    MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", 12, CardType::TRAP);
    PendulumCard timeGazer("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards", 20, 1200, 600,
                           CardType::BUFF, 8);
    MonsterCard gilford("Gilford The Lightning",
                        "If summonned this way(by tributing 3 monsters): Destroy all monsters your opponent controls.",
                        18,
                        2800, 1400);

    dragon.print();
    std::cout << "\n\n";
    magician.print();
    std::cout << "\n\n";
    swords.print();
    std::cout << "\n\n";
    cylinder.print();
    std::cout << "\n\n";
    timeGazer.print();
    std::cout << "\n\n";

    Deck d1("Test one");
    d1.addCard(new MonsterCard(dragon));
    d1.addCard(new MonsterCard(magician));
    d1.addCard(new MagicCard(swords));
    d1.addCard(new MagicCard(cylinder));
    d1.addCard(new PendulumCard(timeGazer));

    Duelist duelist1("Meric Ishtar", d1);
    duelist1.display();
    std::cout << "====================================\n\n";


    duelist1.getDeck().addCard(new MonsterCard(gilford));

    std::cout << "====================================\n\n";
    duelist1.display();
    ///Here I didn't add 'test1.txt' file to the committed project , because either way the file should be empty and this
    /// way it will create a new file
    std::cout << duelist1.saveDeck("test1.txt");
}

void test3(){///Testing for correct istream for MonsterCard

    MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 25, 3000,
                       2500);
    ///Here I didn't add 'file.txt' file to the committed project , because either way the file should be empty and
    /// this way it will create a new file
    std::ofstream writeFile("file.txt");
    if (!writeFile.is_open()) {
        std::cout << "Error!\n";
    }
    writeFile << dragon;

    writeFile.close();

    MonsterCard acceptDragon;

    std::ifstream readFile("file.txt", std::ios::app);
    if (!readFile.is_open()) {
        std::cout << "Error! number 2\n";
    }

    readFile >> acceptDragon;

    readFile.close();

    acceptDragon.print();

}

void test4() {///Test for correct reading from file(loading deck)

    Duelist loadingDeck("Joey");

    loadingDeck.loadDeck("TestDeck for Loading- Joey edition.txt");

    loadingDeck.getDeck().printDeck();
}

void test5() {///Test that checks if a card is already added to the deck 3 times, and if it is, you can't add it

    Duelist moreCopies("Already exists");

    MonsterCard parasite("Parasite", "When added tou your deck, creates many copies of it in your deck!", 0, 0, 0);
    moreCopies.getDeck().addCard(new MonsterCard(parasite));
    moreCopies.getDeck().addCard(new MonsterCard(parasite));
    moreCopies.getDeck().addCard(new MonsterCard(parasite));
    moreCopies.getDeck().addCard(new MonsterCard(parasite));

    MagicCard magicParasite("MagicParasite",
                            "When added tou your deck, replaces all your cards with magic cards of this type!", 0,
                            CardType::TRAP);
    moreCopies.getDeck().addCard(new MagicCard(magicParasite));
    moreCopies.getDeck().addCard(new MagicCard(magicParasite));
    moreCopies.getDeck().addCard(new MagicCard(magicParasite));
    moreCopies.getDeck().addCard(new MagicCard(magicParasite));


    PendulumCard combo("Combination Parasite",
                       "Takes the effect of the Monster Card 'Parasite' and the Spell Card 'MagicParasite'!", 0, 1, 1,
                       CardType::SPELL, 9);

    moreCopies.getDeck().addCard(new PendulumCard(combo));
    moreCopies.getDeck().addCard(new PendulumCard(combo));
    moreCopies.getDeck().addCard(new PendulumCard(combo));
    moreCopies.getDeck().addCard(new PendulumCard(combo));

    std::cout << moreCopies;
}

void test6() {///Test for duel

    Deck d1("Joey's Passion");
    d1.addCard(new MonsterCard("Jinzo", "Removes all traps from the field", 30, 2400, 1600));
    d1.addCard(new MonsterCard("Panther Warrior", "Each time you attack you sacrifice 1000 health", 19, 2000, 1000));
    d1.addCard(new MagicCard("Giant Trunade", "Return all spell and trap cards to their owner's hands", 28,
                             CardType::SPELL));
    d1.addCard(new PendulumCard("RAndom name", "Random effect", 1, 0, 0, CardType::TRAP, 1));

    Duelist joey("Joey");
    joey.setDeck(d1);

    Deck d2("Samurai");
    Duelist japan("Japanese samurai", d2);

    japan.getDeck().addCard(
            new MonsterCard("Samurai Jack", "cuts each monsters attack and defence in half", 18, 1400, 2000));
    japan.getDeck().addCard(
            new PendulumCard("Random 2", "Random effect 2(havent played with pendulums before)", 2, 100, 200,
                             CardType::BUFF, 2));
    japan.getDeck().addCard(
            new MonsterCard("Samurai Tsushima", "When summoned summon all other samurais form your Graveyard", 40, 2700,
                            2200));
    japan.getDeck().addCard(
            new MagicCard("Hearth of the Samurai", "Give all samurais 500 ATK and 500 DEF", 25, CardType::BUFF));

    joey.duel(japan);
}

int main(){
    //test1();
    //test2();
    //test3();
    //test4();
    //test5();
    ///try it a few times, since there are only 4 cards in each deck there is a possibility that both players can TIE
    //test6();

}
