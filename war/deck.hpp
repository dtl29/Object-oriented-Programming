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

//this enum is a represtnation of set of suits within the deck
enum Suit 
{
    Hearts,
    Spades,
    Clubes,
    Dimaonds,
};

//this enum is a represnation of the set of ranks that a card can poses in a deck
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

/*
struct for the represntation of a normal card with a suit and a rank to represnt the card
*/
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

/*
Deck constrictor
*this will initilize the deck with all 52 cards that have the coresponding suit and rank 
*/
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

/*
shuffle 
*is a member function of deck 
*funtion that suffles the deck
*/
void Deck::shuffle(std::vector<Card> &theDeck)
{
	std::srand(std::time(0));
	std::random_shuffle(theDeck.begin(), theDeck.end());
}
 