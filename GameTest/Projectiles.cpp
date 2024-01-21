#include "stdafx.h"
#include "Projectiles.h"
#include "app\app.h"
#include "math.h"
using namespace std; //debug

void Projectiles::Init() {
	posX = -1;
	posY = 0;
	inAir = false;
	targetX = 0;
	targetY = 0;
	speed = 5.0f;
	speedY = 0;
	initialAngle = 0;
}

void Projectiles::DrawBullets() {
	//string leftStr=std::to_string(left);
	//OutputDebugStringA(leftStr.c_str());
	float r = 1.0f;
	float g = 1.0f;
	float b = 1.0f;
	float size = 10.0f;
	float left = posX;
	float top = posY;
	float right = left + size;
	float bottom = top - size;
	if (left != -1.0f) {
		App::DrawLine(left, top, left, bottom, r, g, b);
		App::DrawLine(left, top, right, top, r, g, b);
		App::DrawLine(right, top, right, bottom, r, g, b);
		App::DrawLine(left, bottom, right, bottom, r, g, b);
	}
}

float Projectiles::GetPosX()
{
	return posX;
}

void Projectiles::SetPosX(float x) {
	posX = x;
}

float Projectiles::GetPosY()
{
	return posY;
}

void Projectiles::SetPosY(float y) {
	posY = y;
}

float Projectiles::GetTargetX()
{
	return targetX;
}

void Projectiles::SetTargetX(float x) {
	targetX = x;
}

float Projectiles::GetTargetY()
{
	return targetY;
}

void Projectiles::SetTargetY(float y) {
	targetY = y;
}


float Projectiles::GetSpeed()
{
	return speed;
}

void Projectiles::SetSpeed(float newSpeed) {
	speed = newSpeed;
}

void Projectiles::SetSpeedY(float newSpeedY) {
	speedY = newSpeedY;
}

bool Projectiles::GetAirborn()
{
	return inAir;
}

void Projectiles::SetAirborn(bool airborn) {
	inAir = airborn;
}

void Projectiles::Shoot(CSimpleSprite *testSprite) {
	if (!inAir) {
		inAir = true;
		float& mouseX = targetX;
		float& mouseY = targetY;
		App::GetMousePos(mouseX, mouseY);
		string leftStr=std::to_string(targetX);
		OutputDebugStringA(leftStr.c_str());
		//OutputDebugStringA("Left Click"); //debug
		float x, y;
		testSprite->GetPosition(x, y);
		posX = x + 50;
		posY = y;
		initialAngle = InitialAngle();
		speedY = speed * sinf(initialAngle);
	}
	
}

float Projectiles::InitialAngle() {
	float angle;
	float xDiff = targetX - posX;
	float yDiff = targetY - posY;
	angle = atan(yDiff / xDiff);
	if (xDiff < 0) {
		angle += M_PI;
	}
	return angle;
}

void Projectiles::SetAngle(float newAngle) {
	initialAngle = newAngle;
}

void Projectiles::BulletTravel() {
	if (inAir) {
		CheckOutOfBounds();
		DrawBullets();
		posX += speed * cosf(initialAngle);
		posY += speedY;
		speedY -= 0.05f;
		//string leftStr=std::to_string(speedY);
		//OutputDebugStringA(leftStr.c_str());
		
	}
}

void Projectiles::CheckOutOfBounds() {
	if (posX <= 0 || posX >= APP_VIRTUAL_WIDTH || posY <= 0 || posY >= APP_VIRTUAL_HEIGHT) {
		inAir = false;
		printf("Hi");
	}
}
