﻿Daniel Louis
Practice one: war
oop


    For this project I made the abstractions for the physical game into the computer so to represent the different parts of the physical game I made a Player class and a Deck structure that would 
	represent the igame. The Deck abstraction had a couple of parts to it containing a Card that would be placed into a deck vector so each of the 52 cards of the deck was represented by an individual 
	card. Then for the Player I had them have two decks one that was for the decks they would play with flipping over the top card of and another winning pile that would take all the cards that a play 
	won in a round of the game. Once the deck being played was emptied the Player would shuffle the winning pile and place is back into the playing deck. 
        For the rest of the abstraction I made a function that would act as the physical act of playing though a round. This function was the war part and would compare the rank of two cards and the 
		winner of the larger card would gain both of the cards into their winners pile and both would lose the top card of their playing deck. When there was a tie for the larger card the function would 
		be called again so it would play again until there was a winner. This will continue until one player had all 52 cards in their deck and the other had zero in their deck. 
        The game requires no input from the players so there was none in the game, once it started it played until it ended. And the only output was to say who the winner of the game was after the game 
		had already finished.