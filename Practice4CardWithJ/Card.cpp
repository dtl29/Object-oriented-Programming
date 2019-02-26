/*
Daniel Louis
Practice Four: Card redesign with joker 
oop 
*/
#include <iostream>
#include "Card.hpp"

bool operator==(Card a, Card b)
{
	if(a.is_StandardCard() && b.is_StandardCard())
		return a.get_rank() == b.get_rank() && a.get_suit() == b.get_suit();
	else if (!(a.is_StandardCard() && b.is_StandardCard()))
		return a.get_color() == b.get_color();
	else
		return false;
}

bool operator!=(Card a, Card b)
{
	return !(a==b);
}

bool operator<(Card a, Card b)
{
	if(a.is_StandardCard() && b.is_StandardCard())
	{
		if(a.get_suit() < b.get_suit())
			return true;
		else if(b.get_suit() < a.get_suit())
			return false;
		return a.get_rank() < b.get_rank();
	}
	else if (!(a.is_StandardCard() && b.is_StandardCard()))
	{
		if(a.get_color() < b.get_color())
			return true;
		else
			return false;
	}
	else
		abort();
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

bool operator==(CardSlow a, CardSlow b)
{
	if((a.is_StandardCard() && !(b.is_StandardCard())) ||
		(!(a.is_StandardCard()) && b.is_StandardCard()))
	{
		return false;
	}
	else
	{
		if(a.is_StandardCard())
		{
			return a.get_suit() == b.get_suit() && a.get_rank() == b.get_rank();
		}
		else
		{
			return a.get_color() == b.get_color();
		}
	}
}
bool operator==(CardSlow a, Card b)
{
	if(a.is_StandardCard() && !(b.is_StandardCard()) \
		|| !(a.is_StandardCard() && b.is_StandardCard()))
	{
		return false;
	}
	else
	{
		if(a.is_StandardCard())
		{
			return a.get_suit() == b.get_suit() && a.get_rank() == b.get_rank();
		}
		else
		{
			return a.get_color() == b.get_color();
		}
	}
}
bool operator==(Card a, CardSlow b)
{
	if(a.is_StandardCard() && !(b.is_StandardCard()) \
		|| !(a.is_StandardCard() && b.is_StandardCard()))
	{
		return false;
	}
	else
	{
		if(a.is_StandardCard())
		{
			return a.get_suit() == b.get_suit() && a.get_rank() == b.get_rank();
		}
		else
		{
			return a.get_color() == b.get_color();
		}
	}
}

Deck::Deck(std::deque<Card>::iterator start, std::deque<Card>::iterator end)
{
	this->assign(start,end);
}

Deck::Deck()
{

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 13; j++)
		{
			this->push_back(Card(Rank(j),Suit(i)));
		}
	}
	this->push_back(Color(Black));
	this->push_back(Color(Red));
}

//initilaize the deck to have all 54 cards
///52 standard cards
///2 joker cards
DeckWithSlowCard::DeckWithSlowCard()
{
	//could change to constant initliaztion without loops for performance. 
	//idk if that would be faster 

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 13; j++)
		{
			this->push_back(CardSlow(Suit(i), Rank(j)));
		}
	}
	this->push_back(CardSlow(Red));
	this->push_back(CardSlow(Black));
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
	if(c.is_StandardCard())
	{
		return  os << c.get_rank() << c.get_suit(); 
	}
	else
	{
		return os << c.get_color();
	}
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

std::ostream& operator<<(std::ostream& os, CardSlow c)
{
	if(c.is_StandardCard())
	{
		return os << c.get_rank() << c.get_suit();
	}
	else
	{
		return os << c.get_color();
	}
}

std::ostream& operator<<(std::ostream& os, Color c)
{
	switch(c)
	{
		case Red : return os << 'R';
		case Black: return os << 'B';
	}
}

std::ostream& operator<<(std::ostream& os, DeckWithSlowCard const& d)
{
	int n = 0;
	for(CardSlow c : d)
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