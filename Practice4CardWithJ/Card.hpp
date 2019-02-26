/*
Daniel Louis
Practice Four: Card redesign with joker 
oop 
*/
#pragma once

#include <deque>
#include <iostream>
#include <algorithm>
#include <iosfwd>
#include <ctime>

#include <bitset>

enum Suit 
{
	Hearts,
	Diamonds,
	Spades,
	Clubs,
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

enum Color
{
	Red,
	Black,
};

struct StandardCard
{
	Suit s; 
	Rank r;

	StandardCard(Suit suit, Rank rank)
		: s(suit) , r(rank)
	{} 
};

struct JokerCard
{
	Color c;

	JokerCard(Color color)
		: c(color)
	{}
};

union PlayingCard
{
	StandardCard sc;
	JokerCard jc;

	PlayingCard(Suit s, Rank r)
		: sc(s,r)
	{}
	PlayingCard(Color c)
		: jc(c)
	{}
};

/*
Card class 
holds both jokers and standard cards in an 8 bit reprsentation 
*/
class Card
{
private:
	unsigned int data;

public:
	//bits will be k0ss rrrr 
	///first will be to describe if its a joker or a standard card
	Card (Rank r , Suit s)
		: data(static_cast<unsigned>(s) << 4 | static_cast<unsigned> (r))
		{}
		// bits will be kc00 0000
	Card (Color c)
		: data( 128 | static_cast<unsigned>(c << 6))
	{}

	//data holds 00 00 0000 last four are for rank
	Rank get_rank(){if(this->is_StandardCard()) return static_cast<Rank> (data & 0xf);}
	Suit get_suit(){if(this->is_StandardCard()) return static_cast<Suit>(data >> 4);}
	Color get_color(){if(!(this->is_StandardCard())) return static_cast<Color>((data & 64) >> 6 );}

	bool is_StandardCard()
	{
		if((data & 128) != 128) 
		{
			return true;
		} 
		else
		{ 
			return false;
		}
	}
	//print binary rep of data
	void printBinary()
	{
		std::cout << '\n' << std::bitset<8>(data) << '\n';
	}
};

struct Deck 
	: std::deque<Card>
	//: std::array<Card,52>
{
	using std::deque<Card>::deque;
	Deck();
	Deck(std::deque<Card>::iterator begin, std::deque<Card>::iterator end);
};

/*
Card with joker as a tagged union
**not bit compressed one! 
*/
class CardSlow
{
private:
	int kind;
	PlayingCard pc; 
public:
	CardSlow(Suit s, Rank r)
		: pc(s,r) , kind(0)
	{}
	CardSlow(Color c)
		: pc(c), kind(1) 
	{}

	bool is_StandardCard() const {if(kind == 0) return true; else return false;}

	Suit get_suit() const {if(kind == 0) return pc.sc.s;}
	Rank get_rank() const {if(kind == 0) return pc.sc.r;}
	Color get_color() const {if(kind == 1) return pc.jc.c;}
};

bool operator==(Card a, Card b);
bool operator!=(Card a, Card b);

bool operator<(Card a, Card b);
bool operator>(Card a, Card b);
bool operator<=(Card a, Card b);
bool operator>=(Card a, Card b);

bool operator==(CardSlow a, CardSlow b);
bool operator==(CardSlow a, Card b);
bool operator==(Card a, CardSlow b);

struct DeckWithSlowCard
	: std::deque<CardSlow>
{
	using std::deque<CardSlow>::deque;
	DeckWithSlowCard();
};

std::ostream& operator<<(std::ostream& os, Suit s);
std::ostream& operator<<(std::ostream& os, Rank r);
std::ostream& operator<<(std::ostream& os, Card c);
std::ostream& operator<<(std::ostream& os, Deck const& d);

std::ostream& operator<<(std::ostream& os, CardSlow);
std::ostream& operator<<(std::ostream& os, Color c);
std::ostream& operator<<(std::ostream& os, DeckWithSlowCard const& d);