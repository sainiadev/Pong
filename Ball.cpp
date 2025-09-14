#include "Ball.h"

// This is a Constructor function for the Ball class

Ball::Ball(float startX, float startY) :m_Position(startX, startY)
{
	m_Shape.setSize(sf::Vector2f(10, 10));
	m_Shape.setPosition(m_Position);
}
FloatRect Ball::getPosition()
{
	return m_Shape.getGlobalBounds();
}
RectangleShape Ball::getShape()
{
	return m_Shape;
}
float Ball::getXVelocity()
{
	return m_DirectionX;
}
void Ball::reboundSides()
{
	m_DirectionX = -m_DirectionX;
}
void Ball::reboundBatOrTop()
{
	m_DirectionY = -m_DirectionY;
	m_Speed = m_Speed * 1.5f;
}
void Ball::reboundBottom()
{
	m_Position.y = 0;
	m_Position.x = 500;
	m_DirectionY = -m_DirectionY;
}
void Ball::update(Time dt)
{
	// Update the ball position 
	m_Position.y += m_Speed * m_DirectionY * dt.asSeconds();
	m_Position.x += m_Speed * m_DirectionX * dt.asSeconds();

	// Move the ball
	m_Shape.setPosition(m_Position);
}