/*
Daniel Louis

oop

Practice 5 :
Pure object oriented card class with inheritance
*/
#pragma once 

enum Suit 
{
	Hearts,
	Diamonds,
	Clubs,
	Spades,
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

class Card
{
public :
	virtual bool is_std() const = 0;
	virtual Color get_color() const = 0;
};

class JokerCard : Card
{
public:
	bool is_std() const override
	{return false;}
};

class Red_JokerCard : public JokerCard
{
public:
	Color get_color() const override
	{return Red;}
};

class Black_JokerCard : public JokerCard
{
public: 
	Color get_color() const override
	{return Black;}
};

class StandardCard : Card
{
public:
	bool is_std() const override
	{return true;}
	virtual Rank get_rank() = 0;
	virtual Suit get_suit() = 0;
};

class Hearts_StandardCard : public StandardCard
{
public:
	Suit get_suit() override
	{return Hearts;}
	Color get_color() const override
	{return Red;}
};

class Diamonds_StandardCard : public StandardCard
{
public:
	Suit get_suit() override
	{return Diamonds;}
	Color get_color() const override
	{return Red;}
};

class Clubs_StandardCard : public StandardCard
{
	Suit get_suit() override
	{return Clubs;}
	Color get_color() const override
	{return Black;}
};

class Spades_StandardCard : public StandardCard
{
	Suit get_suit() override 
	{return Spades;}
	Color get_color() const override
	{return Black;}
};

class Ace_Diamonds : public Diamonds_StandardCard
{
public:
	Rank get_rank() override 
	{return Ace;}
};

class Two_Diamonds : public Diamonds_StandardCard
{
	Rank get_rank() override
	{return Two;}
};

class Three_Diamonds : public Diamonds_StandardCard
{
	Rank get_rank() override
	{return Three;}
};

class Four_Diamonds : public Diamonds_StandardCard
{
	Rank get_rank() override
	{return Four;}
};

class Five_Diamonds : public Diamonds_StandardCard
{
	Rank get_rank() override
	{return Five;}
};

class Six_Diamonds : public Diamonds_StandardCard
{
	Rank get_rank() override
	{return Six;}
};

class Seven_Diamonds : public Diamonds_StandardCard
{
	Rank get_rank() override
	{return Seven;}
};

class Eight_Diamonds : public Diamonds_StandardCard
{
	Rank get_rank() override
	{return Eight;}
};

class Nine_Diamonds : public Diamonds_StandardCard
{
	Rank get_rank() override
	{return Nine;}
};

class Ten_Diamonds : public Diamonds_StandardCard
{
	Rank get_rank() override
	{return Ten;}
};

class Jack_Diamonds : public Diamonds_StandardCard
{
	Rank get_rank() override
	{return Jack;}
};

class Queen_Diamonds : public Diamonds_StandardCard
{
	Rank get_rank() override
	{return Queen;}
};

class King_Diamonds : public Diamonds_StandardCard
{
	Rank get_rank() override
	{return King;}
};

class Ace_Hearts : public Hearts_StandardCard
{
	Rank get_rank() override
	{return Ace;}
};

class Two_Hearts : public Hearts_StandardCard
{
	Rank get_rank() override
	{return Two;}
};

class Three_Hearts : public Hearts_StandardCard
{
	Rank get_rank() override
	{return Three;}
};

class Four_Hearts : public Hearts_StandardCard
{
	Rank get_rank() override
	{return Four;}
};

class Five_Hearts : public Hearts_StandardCard
{
	Rank get_rank() override
	{return Five;}
};

class Six_Hearts : public Hearts_StandardCard
{
	Rank get_rank() override
	{return Six;}
};

class Seven_Hearts : public Hearts_StandardCard
{
	Rank get_rank() override
	{return Seven;}
};

class Eight_Hearts : public Hearts_StandardCard
{
	Rank get_rank() override
	{return Eight;}
};

class Nine_Hearts : public Hearts_StandardCard
{
	Rank get_rank() override
	{return Nine;}
};

class Ten_Hearts : public Hearts_StandardCard
{
	Rank get_rank() override
	{return Ten;}
};

class Jack_Hearts : public Hearts_StandardCard
{
	Rank get_rank() override
	{return Jack;}
};

class Queen_Hearts : public Hearts_StandardCard
{
	Rank get_rank() override
	{return Queen;}
};

class King_Hearts : public Hearts_StandardCard
{
	Rank get_rank() override
	{return King;}
};

class Ace_Clubs : public Clubs_StandardCard
{
	Rank get_rank() override
	{return Ace;}
};

class Two_Clubs : public Clubs_StandardCard
{
	Rank get_rank() override
	{return Two;}
};

class Three_Clubs : public Clubs_StandardCard
{
	Rank get_rank() override
	{return Three;}
};

class Four_Clubs : public Clubs_StandardCard
{
	Rank get_rank() override
	{return Four;}
};

class Five_Clubs : public Clubs_StandardCard
{
	Rank get_rank() override
	{return Five;}
};

class Six_Clubs : public Clubs_StandardCard
{
	Rank get_rank() override
	{return Six;}
};

class Seven_Clubs : public Clubs_StandardCard
{
	Rank get_rank() override
	{return Seven;}
};

class Eight_Clubs : public Clubs_StandardCard
{
	Rank get_rank() override
	{return Eight;}
};

class Nine_Clubs : public Clubs_StandardCard
{
	Rank get_rank() override
	{return Nine;}
};

class Ten_Clubs : public Clubs_StandardCard
{
	Rank get_rank() override
	{return Ten;}
};

class Jack_Clubs : public Clubs_StandardCard
{
	Rank get_rank() override
	{return Jack;}
};

class Queen_Clubs : public Clubs_StandardCard
{
	Rank get_rank() override
	{return Queen;}
};

class King_Clubs : public Clubs_StandardCard
{
	Rank get_rank() override
	{return King;}
};

class Ace_Spades : public Spades_StandardCard
{
	Rank get_rank() override
	{return Ace;}
};

class Two_Spades : public Spades_StandardCard
{
	Rank get_rank() override
	{return Two;}
};

class Three_Spades : public Spades_StandardCard
{
	Rank get_rank() override
	{return Three;}
};

class Four_Spades : public Spades_StandardCard
{
	Rank get_rank() override
	{return Four;}
};

class Five_Spades : public Spades_StandardCard
{
	Rank get_rank() override
	{return Five;}
};

class Six_Spades : public Spades_StandardCard
{
	Rank get_rank() override
	{return Six;}
};

class Seven_Spades : public Spades_StandardCard
{
	Rank get_rank() override
	{return Seven;}
};

class Eight_Spades : public Spades_StandardCard
{
	Rank get_rank() override
	{return Eight;}
};

class Nine_Spades : public Spades_StandardCard
{
	Rank get_rank() override
	{return Nine;}
};

class Ten_Spades : public Spades_StandardCard
{
	Rank get_rank() override
	{return Ten;}
};

class Jack_Spades : public Spades_StandardCard
{
public:
	Rank get_rank() override
	{return Jack;}
};

class Queen_Spades : public Spades_StandardCard
{
public:
	Rank get_rank() override
	{return Queen;}
};

class King_Spades : public Spades_StandardCard
{
public:
	Rank get_rank() override
	{return King;}
};

std::ostream& operator<<(std::ostream& os, Black_JokerCard c);
std::ostream& operator<<(std::ostream& os, Red_JokerCard c);
std::ostream& operator<<(std::ostream& os, StandardCard &c);