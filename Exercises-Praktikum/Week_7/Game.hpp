#pragma once
#include "Player.hpp"
#include <iostream>
#include <time.h>
class Game{
public:
	Game(Player newplayer);
	Game();
	void StartGame();

private:
	Player player;
	int gameNumber = 0;
	void Hacker();
};

