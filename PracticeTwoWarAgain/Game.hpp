/*
Daniel Louis
Practice Two: Card redesign and game class created
oop 
*/
#pragma once

#include "Card.hpp"

class Game
{
private:
	Deck start();
	int warCompare(Deck &ones, Deck &twos, Deck &onesWin, Deck &twosWin);

public:
	void war();

};

Deck Game::start()
{
	Deck d;
	Suit s = Suit(0);
	Rank r = Rank(0);
	Card c(r, s);

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 13; j++)
		{
			r = Rank(j);
			c = Card(r, s);
			d.push_back(c);
		}
		s = Suit(i);
	}


	std::random_device rng;
	std::minstd_rand prng(rng());
	std::shuffle(d.begin(), d.end(), prng);

	return d;

}
void Game::war()
{
	Deck d = start();

	Deck playerOnesDeck(d.begin(),d.begin()+(d.size()/2));
	Deck playerTwosDeck(d.begin()+(d.size()/2),d.end());

	Deck playerOnesWinnings, playerTwosWinnings;

	int n = 0;
	while(playerOnesDeck.size() != 0 || playerTwosDeck.size()!=0)
	{
		warCompare(playerOnesDeck, playerTwosDeck, playerOnesWinnings, playerTwosWinnings);

	}
	if(playerOnesWinnings.size() > playerTwosWinnings.size())
	{
		std::cout << "Player one wins\n"; 
	}
	else if( playerTwosWinnings.size() > playerOnesWinnings.size())
	{
		std::cout << "Player Two wins\n";
	}
	else
	{	
		std::cout << "It was a tie.\n";
	}

}

int Game::warCompare(Deck &ones, Deck &twos, Deck &onesWin, Deck &twosWin)
{
	if(ones.size()==0 || twos.size() == 0)
	{
		if(ones.size() != 0)
		{ return 1;}
		if(twos.size() != 0)
		{ return 2;}
		else
		{ abort();} 
	}

	int winner;
	if(ones[0].get_rank() > twos[0].get_rank())
	{
		onesWin.push_back(ones.front());
		onesWin.push_back(twos.front());
		ones.pop_front();
		twos.pop_front();
		return 1;
	}
	if(ones[0].get_rank() < twos[0].get_rank())
	{
		twosWin.push_back(ones.front());
		twosWin.push_back(twos.front());
		ones.pop_front();
		twos.pop_front();
		return 2;
	}
	else
	{
		Card holdOne(ones.front()), holdTwo(twos.front());
		ones.pop_front();
		twos.pop_front();
		winner = warCompare(ones, twos, onesWin, twosWin);
		if(winner == 1)
		{
			onesWin.push_back(holdOne);
			onesWin.push_back(holdTwo);
			return 1;
		}
		else
		{
			twosWin.push_back(holdOne);
			twosWin.push_back(holdTwo);
			return 2;
		}
	}
}
