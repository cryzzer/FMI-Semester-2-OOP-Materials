#include "Game.hpp"

Game::Game() {

}

Game::Game(Player newplayer) {
	player = newplayer;
}
void Game::StartGame() {
	while (player.getCoins() > 0) {
		player.addOrTakeCoins(-1);
		srand(time(NULL));


		gameNumber = rand() % 100 + 1;

		std::cout << "Enter your new number for guessing!  :";
		int newNum;
		std::cin >> newNum;
		player.setGuessNumber(newNum);


		char command;
		std::cout << "Enter command ('y' to play the game / 'n' to end the game  / 'h' to activate hack :";
		std::cin >> command;
		bool correctGuess = false;
		if (command == 'y') {
			if (player.getGuessNumber() == gameNumber) {
				correctGuess = true;
			}
		}
		else if (command == 'n') {
			break;
		}
		else if (command == 'h') {
			Hacker();
			if (player.getGuessNumber() == gameNumber) {
				correctGuess = true;
			}
		}


		if (player.getGuessNumber() == gameNumber) {
			std::cout << "You guessed the number!\n";
			player.addOrTakeCoins(2);
			std::cout << "playerCoins: " << player.getCoins() << std::endl << std::endl;
		}
		else {
			std::cout << "Your guess wasn't correct, game's number was: " << gameNumber << std::endl;
			std::cout << "playerCoins: " << player.getCoins() << std::endl << std::endl;
		}

	}

	std::cout << "Thanks for playing!\n";
}
void Game::Hacker() {
	player.setGuessNumber(gameNumber);
}
