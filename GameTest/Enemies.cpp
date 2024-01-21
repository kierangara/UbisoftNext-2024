#include "stdafx.h"
#include "Enemies.h"
using namespace std; //debug


void Enemies::Init() {
	newX = 600.0f;
	newY = 400.0f;
	enemySprite = App::CreateSprite(".\\TestData\\Robot3.bmp", 1, 1);
	enemySprite->SetPosition(newX, newY);
	speed = 1.0f;
	srand(time(0));
}

void Enemies::MoveEnemy() {
	newX = RandomNumber(APP_VIRTUAL_WIDTH / 2+50, APP_VIRTUAL_WIDTH-50);
	newY = RandomNumber(50, APP_VIRTUAL_HEIGHT-50);
	float x, y;
	enemySprite->GetPosition(x, y);
	angle = atan((newY - y) / (newX - x));
	if (newX - x <= 0) { 
		angle += M_PI;
	}
	//string leftStr2 = "Angle: " + std::to_string(angle) + " ";
	//OutputDebugStringA(leftStr2.c_str());
}

void Enemies::EnemyTravel() {
	float x, y;
	enemySprite->GetPosition(x, y);
	if (abs(newX - x) < speed && abs(newY - y) < speed) {
		//string leftStr = std::to_string(newX);
		//OutputDebugStringA(leftStr.c_str());
		MoveEnemy();
		/*string leftStr = std::to_string(newX);
		OutputDebugStringA(leftStr.c_str());
		string leftStr2 = std::to_string(newY);
		OutputDebugStringA(leftStr2.c_str());*/
	}
	else {
		//string leftStr = std::to_string(x);
		//OutputDebugStringA(leftStr.c_str());
		enemySprite->SetPosition(x + speed * cosf(angle), y + speed * sinf(angle));
	}
	DrawSprite();
}


float Enemies::RandomNumber(int lowerBound, int upperBound) {
	float randNum = (float)((rand() % (upperBound - lowerBound + 1)) + lowerBound);
	/*string leftStr2 = "lower " + std::to_string(lowerBound) + " ";
	OutputDebugStringA(leftStr2.c_str());
	string leftStr = "upper "+std::to_string(upperBound) + " ";
	OutputDebugStringA(leftStr.c_str());*/
	/*string leftStr2 = "RandNum: " + std::to_string(randNum) + " ";
	OutputDebugStringA(leftStr2.c_str());*/
	return randNum;
}

void Enemies::DrawSprite() {
	enemySprite->Draw();
}

void Enemies::GetEnemyPosition(float& x, float& y) {
	enemySprite->GetPosition(x, y);
}