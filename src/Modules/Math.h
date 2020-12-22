#pragma once


static const float Pi = 3.1415926535f;

// converts degrees to radians
static float DegToRad(const float deg)
{
	return deg * Pi / 180.0f;
}

// returns X coordinate of angle
static float AngleToX(const float deg)
{
	return static_cast<float>(cos(DegToRad(deg)));
}

// returns Y coordinate of angle
static float AngleToY(const float deg)
{
	return static_cast<float>(sin(DegToRad(deg)));
}

// converts screen degrees ( 0 is North ) , to world degrees ( 0 is East ) 
static float WorldDeg(float deg)
{
	return deg - 90;
}