#include "Bat.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
int main()
{
	// Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the game
	RenderWindow window(vm, "Pong Game", Style::Fullscreen);
	int score = 0;
	int lives = 3;

	// Create a bat at the bottom center of the screen
	Bat bat(1920 / 2, 1080 - 20);

	// We will add aball in the next lesson

	// Create a Text object called HUD
	Text hud;

	// Retro style font
	Font font;
	font.loadFromFile("fonts/DS-Digi.ttf");

	// Set the font to our retro font
	hud.setFont(font);
	// Make it nice and big
	hud.setCharacterSize(75);
	// Choose a color
	hud.setFillColor(Color::White);
	// Position it top left
	hud.setPosition(20, 20);
	// Here is our clock for timing everything
	Clock clock;
	while (window.isOpen())
	{
		/*
		***********************
		Handle the player input
		***********************
		*/



		/*
		*********************************
		Update the bat, the ball, the HUD
		*********************************
		*/





		/*
		*******************************
		Draw the bat, the ball, the HUD
		*******************************
		*/
	}
	return 0;
}