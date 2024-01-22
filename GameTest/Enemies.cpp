#include "stdafx.h"
#include "Enemies.h"


void Enemies::Init() {
	SetActiveState(true);
	newX = 800.0f;
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
}

void Enemies::EnemyTravel() {
	if (IsActive()) {
		float x, y;
		enemySprite->GetPosition(x, y);
		if (abs(newX - x) < speed && abs(newY - y) < speed) {
			MoveEnemy();
		}
		else {
			enemySprite->SetPosition(x + speed * cosf(angle), y + speed * sinf(angle));
		}
		DrawSprite();
	}
}


float Enemies::RandomNumber(int lowerBound, int upperBound) {
	float randNum = (float)((rand() % (upperBound - lowerBound + 1)) + lowerBound);
	return randNum;
}

void Enemies::DrawSprite() {
	enemySprite->Draw();
}

void Enemies::GetEnemyPosition(float& x, float& y) {
	enemySprite->GetPosition(x, y);
}

bool Enemies::IsActive() {
	return active;
}

void Enemies::SetActiveState(bool activeState) {
	active = activeState;
}