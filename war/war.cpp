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

/*
function war
-will compare two Cards and see what one is larger and if it was a tie it will compare the next one in the array
*/
int war(Card playerOnesCard, Card playerTwosCard, Player &one, Player &two, int &i);

//main is the driver function for the aplication and will output the winner of the game to standard output
//this will play a game of war with one deck of cards. 
int main()
{
	//deck is from deck.hpp and will be the deck for the game that is randomly shuffeled then seperated to each player
	Deck deck;
	//player one's container and their deck that is the first half of the random deck
	Player playerOne(deck.theDeck.begin(),deck.theDeck.begin() + deck.theDeck.size() / 2);
	//player two's container and theird deck that is the second half of the random deck
	Player playerTwo(deck.theDeck.begin() + deck.theDeck.size() / 2, deck.theDeck.end());
	int i = 0;

	//keep playing the game of war until one of the two players has all 52 cards in their deck
	//the player that has 52 cards in their deck has all the cards and will be the winner of war
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

		//call to the war function 
		war(playerOne.playersDeck.back(), playerTwo.playersDeck.back(), playerOne, playerTwo, i);
		i = 1;

	}

	//standard output the winner 
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
int war(Card playerOnesCard, Card playerTwosCard, Player &one, Player &two,int &i)
{
	//if player one or player two's deck is empty return 0
	if(one.playersDeck.size() == 0 || two.playersDeck.size() == 0)
	{
		return 0;
	}
	
	//if the player one wins the war and both players decks are not empty
	//then player one wins and pushes the winning cards onto their prize deck. and both players discard the top card of their current deck
	if(playerOnesCard.rank > playerTwosCard.rank && (one.playersDeck.size() != 0 || two.playersDeck.size() != 0))
	{
		one.winnersDeck.push_back(one.playersDeck.back());
		one.winnersDeck.push_back(two.playersDeck.back());
		one.playersDeck.pop_back();
		two.playersDeck.pop_back();
		return 1;
	}
	//if player two wins player two has the two prize cards pushed onto their winnings and both players pop the top card of their current deck
	if(playerOnesCard.rank < playerTwosCard.rank && (one.playersDeck.size() != 0 || two.playersDeck.size() != 0))
	{
		two.winnersDeck.push_back(one.playersDeck.back());
		two.winnersDeck.push_back(two.playersDeck.back());
		one.playersDeck.pop_back();
		two.playersDeck.pop_back();
		return 2;
	}
	//if it is war and both players cards equal the same thing 
	//have the top three cards of both decks play war again and determin the winner after to get all 8 cards of that war
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
	//if somehow the cards where not compariable the program has run unexpected results 
	//abort when unexpected result since there is no solution to correct the program and get it back on track.
	else
	{
		abort();
	}
}