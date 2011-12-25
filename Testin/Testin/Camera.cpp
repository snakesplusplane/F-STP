#include <SFML\Graphics.hpp>
#include <math.h>
#include "Camera.h"

Camera::Camera(int w, int h, float inSpeed)
{
	size.x = w;
	size.y = h;

	if(inSpeed < 0.0)
		inSpeed = 0.0;
	else if (inSpeed > 1.0)
		inSpeed = 1.0;

	this->speed = inSpeed;
}

Camera::~Camera(){}

void Camera::Move(int x, int y)
{
	position.x = (float)x;
	position.y = (float)y;
	target.x = (float)x;
	target.y = (float)y;
}

void Camera::MoveCenter(int x, int y)
{
	x = x - (size.x / 2);
	y = y - (size.y / 2);

	position.x = (float)x;
	position.y = (float)y;
	target.x = (float)x;
	target.y = (float)y;
}

void Camera::MoveTowards(int x, int y)
{
	target.x = (float)x;
	target.y = (float)y;

}

void Camera::MoveCenterTowards(int x, int y)
{
	x = x - (size.x / 2);
	y = y - (size.y / 2);

	target.x = (float)x;
	target.y = (float)y;
}

void Camera::Update()
{
	float x, y, d;
	float vx, vy, v;
	x = (float)(target.x - position.x);
	y = (float)(target.y - position.y);

	if( (x*x + y*y) <= 1)
	{
		position.x = target.x;
		position.y = target.y;

	}
	else
	{
		d = sqrt( (x*x + y*y));
		v = (d * speed)/60;

		if(v < 1.0f)
			v = 1.0f;

		vx = x * (v/d);
		vy = y * (v/d);
		position.x += vx;
		position.y += vy;
	}
}

sf::IntRect Camera::GetTileBounds(int tileSize)
{
	int x = (int)position.x / tileSize;
	int y = (int)position.y / tileSize;

}