/*
Daniel Louis
Practice one: war
oop 
*/
#pragma once
#include "deck.hpp"
#include <vector>
/*
player class
-a class to keep the players deck straight from the one that is being played with and the one that is being collected after a win
*/ 
class Player
{
public:
	//deck to be played against
	std::vector<Card> playersDeck;
	//a deck for the players winnings to be stored after each war
	std::vector<Card> winnersDeck;
	//player constructor 
	Player(std::vector<Card>::iterator start, std::vector<Card>::iterator end);
};

//player class constructor 
//with initilization of the player's deck from iteratiors for a starting point of a deck to an ending point
Player::Player(std::vector<Card>::iterator start, std::vector<Card>::iterator end)
{
	while(start != end)
	{
		playersDeck.push_back(*start);
		start++;
	}
}