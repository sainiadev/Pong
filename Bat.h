#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
class Bat
{
private:
	Vector2f m_Position;		// A RectangleShape object
	RectangleShape m_Shape;		// The position of the rectangle

	float m_Speed;				// The speed of the rectangle
	bool m_MovingRight = false;	// Is the rectangle moving right?
	bool m_MovingLeft = false;		// Is the rectangle moving left?

public:
	Bat(float startX, float startY);
	FloatRect getPosition();
	RectangleShape getShape();

	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();
	void update(Time dt);
};


