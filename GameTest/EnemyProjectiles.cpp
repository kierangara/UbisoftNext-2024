#include "stdafx.h"
#include "EnemyProjectiles.h"
using namespace std; //debug

/*void EnemyProjectiles::Init() {
	posX = -1;
	posY = 0;
	inAir = false;
	targetX = 0;
	targetY = 0;
	speed = 5.0f;
	speedY = 0;
	initialAngle = 0;
}

void EnemyProjectiles::DrawBullets() {
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
}*/

void EnemyProjectiles::Shoot(Enemies enemy, CSimpleSprite* target) {
	if (!GetAirborn()) {
		SetAirborn(true);
		//float x = 0;
	//float y = 0;
		SetSpeed(-(abs(GetSpeed())));
		float& enemyX = startX;
		float& enemyY = startY;
		enemy.GetEnemyPosition(enemyX, enemyY);
		startX -= 100;
		startY += 20;
		SetPosX(startX);
		SetPosY(startY);

		//Find location of ally, where want bullet to hit
		/*float& allyX = finalX;
		float& allyY = finalY;*/
		GetAllyPosition(target,finalX, finalY);
		xDistToTarget = startX - finalX;
		yDistToTarget = finalY - startY;
		speed = GetSpeed();
		//string leftStr = std::to_string(speed) + " ";
		//OutputDebugStringA(leftStr.c_str());
		gravity = 0.05f;
		//launchAngle1 = atan((pow(speed, 2) + sqrt((pow(speed, 4) - gravity * (gravity * pow(xDistToTarget, 2) + 2 * yDistToTarget * pow(speed, 2))))) / (gravity * xDistToTarget));
		launchAngle2 = atan((pow(speed, 2) - sqrt((pow(speed, 4) - gravity * (gravity * pow(xDistToTarget, 2) + 2 * yDistToTarget * pow(speed, 2))))) / (gravity * xDistToTarget));
		SetAngle(launchAngle2);
		SetSpeedY(abs(speed) * sinf(launchAngle2));
		//timeToTarget = xDistToTarget / GetSpeed();

		//string leftStr=std::to_string(x)+" ";
		//OutputDebugStringA(leftStr.c_str());	
	}
}

bool EnemyProjectiles::BulletControl(Enemies enemy, CSimpleSprite * target) {
	bool hit = false;
	if (!GetAirborn()&&enemy.IsActive()) {
		Shoot(enemy, target);
	}
	else if(GetAirborn()){
		BulletTravel();
		hit = CheckHit(target);
	}
	return hit;
	//string leftStr=std::to_string(launchAngle2)+" ";
	//OutputDebugStringA(leftStr.c_str());	
}

void EnemyProjectiles::GetAllyPosition(CSimpleSprite* target, float &allyX, float &allyY) {
	target->GetPosition(allyX, allyY);
}

bool EnemyProjectiles::CheckHit(CSimpleSprite* target) {
	float x = GetPosX();
	if (x != x) {
		SetAirborn(false);
	}
	float y = GetPosY();
	
	GetAllyPosition(target, finalX, finalY);
	if (x >= finalX - 10 && x <= finalX + 10 && y >= finalY - 30 && y <= finalY + 50) {
		SetAirborn(false);
		return true;
	}
	else {
		return false;
	}
}