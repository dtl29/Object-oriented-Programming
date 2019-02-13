/*
Daniel Louis
Practice Two: Card redesign and game class created
oop 
*/
#include <iostream>
#include "Card.hpp"

bool operator==(Card a, Card b)
{
	return a.get_rank() == b.get_rank() && a.get_suit() == b.get_suit();
}

bool operator!=(Card a, Card b)
{
	return !(a==b);
}

bool operator<(Card a, Card b)
{
	if(a.get_suit() < b.get_suit())
		return true;
	else if(b.get_suit() < a.get_suit())
		return false;
	return a.get_rank() < b.get_rank();
}
bool operator>(Card a, Card b)
{
	return b < a;
}
bool operator<=(Card a, Card b)
{
	return !(b < a);
}
bool operator>=(Card a, Card b)
{
	return !(a < b);
}

Deck::Deck(std::deque<Card>::iterator start, std::deque<Card>::iterator end)
{
	this->assign(start,end);
}


std::ostream& 
operator<<(std::ostream& os, Suit s)
{
	switch (s) {
		case Hearts: return os << "H";
		case Spades: return os << "S";
		case Diamonds: return os << "D";
		case Clubs: return os << "C";
	}

}

std::ostream& 
operator<<(std::ostream& os, Rank r)
{
		switch (r) {
			case Ace: return os << "A";
			case Two: return os << "2";
			case Three: return os << "3";
			case Four: return os << "4";
			case Five: return os << "5";
			case Six: return os << "6";
			case Seven: return os << "7";
			case Eight: return os << "8";
			case Nine: return os << "9";
			case Ten: return os << "T";
			case Jack: return os << "J";
			case Queen: return os << "Q";
			case King: return os << "K";
	}
}

std::ostream& 
operator<<(std::ostream& os, Card c)
{
	return  os << c.get_rank() << c.get_suit(); 
}

std::ostream& 
operator<<(std::ostream& os, Deck const& d)
{
	int n = 0;
	for(Card c : d)
	{
		os << c << ' ';
		if(n == 12)
		{
			os << '\n';
			n=0;
		}
		else
		{
			n++;
		}
	} 
	return os;
}
