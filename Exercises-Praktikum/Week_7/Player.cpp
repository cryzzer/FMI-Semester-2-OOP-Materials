#include "Player.hpp"

Player::Player() {
	playerName = "Default";
	coins = 1;
	guessNumber = 0;
}
Player::Player(std::string name) {
	playerName = name;
	coins = 1;
	guessNumber = 0;
}

void Player::setGuessNumber(int newNumber) {
	guessNumber = newNumber;
}

int Player::getGuessNumber() {
	return guessNumber;
}
int Player::getCoins() {
	return coins;
}
void Player::addOrTakeCoins(int number) {
	coins += number;
}