/*
Daniel Louis
Practice one: war
oop 
*/
#pragma once

#include "Card.hpp"
#include <vector>
/*
player class
-a class to keep the players deck straight from the one that is being played with and the one that is being collected after a win
*/ 
class Player
{
public:
	std::vector<Card> playersDeck;
	std::vector<Card> winnersDeck;
	Player(std::vector<Card>::iterator start, std::vector<Card>::iterator end);
};

//player class constructor 
Player::Player(std::vector<Card>::iterator start, std::vector<Card>::iterator end)
{
	while(start != end)
	{
		playersDeck.push_back(*start);
		start++;
	}
}