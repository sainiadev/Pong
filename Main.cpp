#include "Bat.h"
#include "Ball.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace sf;

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

	// Create a Ball
	Ball ball(1920 / 2, 0);

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

	// sf:Event event; is used to handle all the different events in the game
	Event event; 

	while (window.isOpen())
	{
		/*
		***********************
		Handle the player input
		***********************
		*/

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				// Quit the game whent he window is closed
				window.close();
		}
		// Handle the player quitting
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		// Handle the pressing and releasing of the arrow keys
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			bat.moveLeft();
		}
		else
		{
			bat.stopLeft();
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			bat.moveRight();
		}
		else
		{
			bat.stopRight();
		}



		/*
		*********************************
		Update the bat, the ball, the HUD
		*********************************
		*/
		
		// Update the delta time
		Time dt = clock.restart();
		bat.update(dt);
		ball.update(dt);

		// Update the HUD text
		std::stringstream ss;
		ss << "Score: " << score << "   Lives: " << lives;
		hud.setString(ss.str());

		// Handle ball hitting the bootom
		if (ball.getPosition().top > window.getSize().y)
		{
			// Reverse the ball direction
			ball.reboundBottom();

			// Remove a life
			lives--;

			// Check for zero lives
			if (lives < 1)
			{
				// reset the score
				score = 0;
				lives = 3;
			}
		}

		// Handle ball hitting the top
		if (ball.getPosition().top < 0)
		{
			// Rverse the ball direction
			ball.reboundBatOrTop();

			// Add a point to the score
			score++;
		}

		// Handle ball hitting the sided
		if (ball.getPosition().left < 0 || ball.getPosition().left + ball.getPosition().width> window.getSize().x)
		{
			// Reverse the ball direction
			ball.reboundSides();
		}

		// Has the ball hit the bat?
		if (ball.getPosition().intersects(bat.getPosition()))
		{
			// hit detected so reverse the ball and score a point
			ball.reboundBatOrTop();
		}




		/*
		*******************************
		Draw the bat, the ball, the HUD
		*******************************
		*/

		window.clear();
		window.draw(hud);
		window.draw(bat.getShape());
		window.draw(ball.getShape());
		window.display();
	}
	return 0;
}