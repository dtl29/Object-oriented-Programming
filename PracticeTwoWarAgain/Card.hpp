/*
Daniel Louis
Practice Two: Card redesign and game class created
oop 
*/
#pragma once

#include <deque>
#include <iostream>
#include <algorithm>
#include <iosfwd>
#include <ctime>

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

class Card
{
private:
	unsigned int data;
	//Suit suit;
	//Rank rank;
public:
	Card (Rank r , Suit s)
		: data(static_cast<unsigned>(s) << 4 | static_cast<unsigned> (r))
		{}
	/*Card(Suit s, Rank r)
		: suit(s), rank(r)
		{}*/
	//data holds 00 00 0000 last four are for rank
	//how do I get last four to be the only ones 
	Rank get_rank(){return static_cast<Rank> (data & 0xf) ;}
	Suit get_suit(){return static_cast<Suit>(data >> 4);}
};

bool operator==(Card a, Card b);
bool operator!=(Card a, Card b);

bool operator<(Card a, Card b);
bool operator>(Card a, Card b);
bool operator<=(Card a, Card b);
bool operator>=(Card a, Card b);


struct Deck 
	: std::deque<Card>
	//: std::array<Card,52>
{
	using std::deque<Card>::deque;
	Deck(std::deque<Card>::iterator begin, std::deque<Card>::iterator end);
};

std::ostream& operator<<(std::ostream& os, Suit s);
std::ostream& operator<<(std::ostream& os, Rank r);
std::ostream& operator<<(std::ostream& os, Card c);
std::ostream& operator<<(std::ostream& os, Deck const& d);
