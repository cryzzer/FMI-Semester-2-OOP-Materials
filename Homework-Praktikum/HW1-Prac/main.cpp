/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Danail Nenkov
* @idnumber 62518
* @task 1,2 (both)
* @compiler VC
*/
#include <iostream>
#include "Date.hpp"
#include "MagicCard.hpp"
#include "MonsterCard.hpp"
#include "Deck.hpp"
#include "Duelist.hpp"


using namespace std;


int main()
{
	//Date d1(1,1,2001);
	//d1.print();
	//Date d2(15, 2, 2007);
	//d2.print();
	//cout << d1.dateAfterCurrDate(d2) << endl;
	//d1.addDays(3000);
	//d1.print();
	//d1.removeDays(300);
	//cout << d1.daysTillXmas() << endl;
	//cout << d1.daysTillNewYear() << endl;
	//cout << d1.daysTillNextEvent(d2) << endl;
	//d1.print();
	//d2.print();


	Deck d1;

	MagicCard spell0("spell0", "000", trap);
	MagicCard spell1("spell1", "111", spell);
	MagicCard spell2("spell2", "222", buff);
	MagicCard spell3("spell3", "333", trap);
	MagicCard spell4("spell4", "444", buff);

	d1.addNewSpell(spell0);
	d1.printSpellDeck();
	cout << d1.countSpellsInDeck();
	cout << "\n\n\n\n\n";

	d1.addNewSpell(spell1);
	d1.printSpellDeck();
	cout << d1.countSpellsInDeck();
	cout << "\n\n\n\n\n";

	d1.changeSpellFromIndex(7, spell2);
	d1.printSpellDeck();
	cout << d1.countSpellsInDeck();
	cout << "\n\n\n\n\n";

	d1.addNewSpell(spell3);
	d1.printSpellDeck();
	cout << d1.countSpellsInDeck();
	cout << "\n\n\n\n\n";

	d1.addNewSpell(spell4);
	d1.printSpellDeck();
	cout << d1.countSpellsInDeck();

	cout << "\n============================\n";

	Duelist player1("Yugi Muto",d1);

	player1.printSpellDeckFromDeck();
	cout << player1.countForSpellsInDeck();

	cout << "\n\n\n\n\n";
	player1.changeSpellFromIndexInDeck(9, spell4);
	player1.printSpellDeckFromDeck();
	cout << player1.countForSpellsInDeck();
	cout << "\n\n\n\n\n";

	d1.printSpellDeck();
	cout << d1.countSpellsInDeck();

	//MonsterCard monster0("monster0", 100, 100);
	//MonsterCard monster1("monster1", 110, 110);
	//MonsterCard monster2("monster2", 200, 200);
	//MonsterCard monster3("monster3", 300, 300);
	//MonsterCard monster4("monster4", 400, 400);
	//MonsterCard monster5("monster5", 500, 500);


	//d1.addNewMonster(monster0);
	//d1.printMonsterDeck();
	//cout << d1.countMonstersInDeck();
	//cout << "\n\n\n\n\n";

	//d1.addNewMonster(monster1);
	//d1.printMonsterDeck();
	//cout << d1.countMonstersInDeck();
	//cout << "\n\n\n\n\n";

	//d1.addMonsterToIndex(3, monster3);
	//d1.printMonsterDeck();
	//cout << d1.countMonstersInDeck();
	//cout << "\n\n\n\n\n";

	//d1.addNewMonster(monster2);
	//d1.printMonsterDeck();
	//cout << d1.countMonstersInDeck();
	//cout << "\n\n\n\n\n";

	//d1.addNewMonster(monster4);
	//d1.printMonsterDeck();
	//cout << d1.countMonstersInDeck();
	//cout << "\n\n\n\n\n";

	//d1.addMonsterToIndex(0, monster3);
	//d1.printMonsterDeck();
	//cout << d1.countMonstersInDeck();
	//cout << "\n\n\n\n\n";

	//d1.addMonsterToIndex(0, monster0);
	//d1.printMonsterDeck();
	//cout << d1.countMonstersInDeck();
	//cout << "\n\n\n\n\n";

	//d1.addMonsterToIndex(0, monster0);
	//d1.printMonsterDeck();
	//cout << d1.countMonstersInDeck();
	//cout << "\n\n\n\n\n";
}

