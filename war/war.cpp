/*
Daniel Louis
Practice one: war
oop 
*/
#include <iostream>
#include <algorithm>
#include <ctime>
#include "deck.hpp"
#include "Player.hpp"

int war(Card playerOnesCard, Card playerTwosCard, Player &one, Player &two, int &i);

int main()
{
	Deck deck;
	Player playerOne(deck.theDeck.begin(),deck.theDeck.begin() + deck.theDeck.size() / 2); 
	Player playerTwo(deck.theDeck.begin() + deck.theDeck.size() / 2, deck.theDeck.end());
	int i = 0;

	//std::cout << (playerTwoIterator+2)->rank << " " << (playerOneIterator+1)->rank << std::endl;
	while(playerOne.playersDeck.size() < 52 && playerTwo.playersDeck.size() < 52)
	{
		if(playerOne.playersDeck.size() == 0 || playerTwo.playersDeck.size() == 0)
		{
			playerOne.playersDeck = playerOne.winnersDeck;
			playerTwo.playersDeck = playerTwo.winnersDeck;
			std::srand(std::time(0));
			std::random_shuffle(playerOne.playersDeck.begin(), playerOne.playersDeck.end());
			std::random_shuffle(playerTwo.playersDeck.begin(), playerTwo.playersDeck.end());
		}

		war(playerOne.playersDeck.back(), playerTwo.playersDeck.back(), playerOne, playerTwo, i);
		i = 1;

	}

	if(playerOne.playersDeck.size() >= 52)
	{
		std::cout << "player one wins \n";
	}
	else
	{
		std::cout << "player two wins \n";
	}
}
/*
function war
-will compare two Cards and see what one is larger and if it was a tie it will compare the next one in the array
*/
int war(Card playerOnesCard, Card playerTwosCard,Player &one, Player &two,int &i)
{
	if(one.playersDeck.size() == 0 || two.playersDeck.size() == 0)
	{
		return 0;
	}
	
	if(playerOnesCard.rank > playerTwosCard.rank && (one.playersDeck.size() != 0 || two.playersDeck.size() != 0))
	{
		one.winnersDeck.push_back(one.playersDeck.back());
		one.winnersDeck.push_back(two.playersDeck.back());
		one.playersDeck.pop_back();
		two.playersDeck.pop_back();
		return 1;
	}
	if(playerOnesCard.rank < playerTwosCard.rank && (one.playersDeck.size() != 0 || two.playersDeck.size() != 0))
	{
		two.winnersDeck.push_back(one.playersDeck.back());
		two.winnersDeck.push_back(two.playersDeck.back());
		one.playersDeck.pop_back();
		two.playersDeck.pop_back();
		return 2;
	}
	if(playerOnesCard.rank == playerTwosCard.rank && (one.playersDeck.size() != 0 || two.playersDeck.size() != 0))
	{
		i++;
		int newWar = war(one.playersDeck[one.playersDeck.size() - i], two.playersDeck[two.playersDeck.size() - i], one, two, i);
		if(newWar < 1 || newWar > 2)
		{
			return 0;
		}
		else if( newWar == 1 && (one.playersDeck.size() != 0 || two.playersDeck.size() != 0))
		{
				one.winnersDeck.push_back(one.playersDeck.back());
				one.winnersDeck.push_back(two.playersDeck.back());
				one.playersDeck.pop_back();
				two.playersDeck.pop_back();
				return 1;
		} 
		else if(newWar == 2 && (one.playersDeck.size() != 0 || two.playersDeck.size() != 0))
		{
				two.winnersDeck.push_back(one.playersDeck.back());
				two.winnersDeck.push_back(two.playersDeck.back());
				one.playersDeck.pop_back();
				two.playersDeck.pop_back();
				return 2;
		}
	}
	else
	{
		abort();
	}
}