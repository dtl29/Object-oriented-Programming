/*
Daniel Louis
Practice one: war
oop 
*/
#pragma once 
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

enum Suit 
{
    Hearts,
    Spades,
    Clubes,
    Dimaonds,
};

enum Rank
{
	Ace,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
};

struct Card
{
	Suit suit;
	Rank rank;
};
/*
struct for the deck to be split in half between the players
*/
struct Deck
{
 	std::vector<Card> theDeck;
 	Deck();
 	void printTheDeck(std::vector<Card> theDeck); 
 	void shuffle(std::vector<Card> &theDeck);
};

//Deck constrictor 
Deck::Deck()
{
	Card card;
	for(int i = 0; i < 4; i++)
	{
		card.suit = Suit(i);
		for(int k = 0; k < 13; k++)
		{
			card.rank = Rank(k);
			theDeck.push_back(card);
		}
	}

	shuffle(theDeck);
}
//suffles the deck
void Deck::shuffle(std::vector<Card> &theDeck)
{
	std::srand(std::time(0));
	std::random_shuffle(theDeck.begin(), theDeck.end());
}
 