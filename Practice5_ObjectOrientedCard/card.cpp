/*
Daniel Louis

oop

Practice 5 :
Pure object oriented card class with inheritance
*/
#include <iostream>
#include "card.hpp"
std::ostream& operator<<(std::ostream& os, Black_JokerCard c)
{
	return os << "B";
}
std::ostream& operator<<(std::ostream& os, Red_JokerCard c)
{
	return os << "R";
}
std::ostream& operator<<(std::ostream& os, StandardCard &c) 
{
	switch(c.get_rank())
	{
		case 0 : os << "A";
			break;
		case 1 : os << "2";
			break;
		case 2 : os << "3";
			break;
		case 3 : os << "4";
			break;
		case 4 : os << "5";
			break;
		case 5 : os << "6";
			break;
		case 6 : os << "7";
			break;
		case 7 : os << "8";
			break;
		case 8 : os << "9";
			break;
		case 9 : os << "T";
			break;
		case 10 : os << "J";
			break;
		case 11 : os << "Q";
			break;
		case 12 : os << "K";
			break;
	}
	switch(c.get_suit())
	{
		case 0 : return os << "H";
		case 1 : return os << "D";
		case 2 : return os << "C";
		case 3 : return os << "S";
	}
}