#pragma once
#include <string>
class Player{
public:
	Player();
	Player(std::string name);

	void setGuessNumber(int newNumber);
	int getGuessNumber();
	int getCoins();
	void addOrTakeCoins(int number);

private:
	int coins = 1;
	std::string playerName = "Default";
	int guessNumber = 0;
};

