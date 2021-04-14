#include <iostream>
#include "Game.hpp"

int main()
{
    Player player("Dani");

    Game game(player);
    game.StartGame();
}
