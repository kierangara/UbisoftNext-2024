#include "stdafx.h"
#include "EnemyProjectiles.h"


void EnemyProjectiles::Shoot(Enemies enemy, CSimpleSprite* target) {
	if (!GetAirborn()) {
		SetAirborn(true);
		SetSpeed(-(abs(GetSpeed())));
		//Get location where shooting from
		float& enemyX = startX;
		float& enemyY = startY;
		enemy.GetEnemyPosition(enemyX, enemyY);
		startX -= 100;
		startY += 20;
		SetPosX(startX);
		SetPosY(startY);

		//Find location of ally, where want bullet to hit
		GetAllyPosition(target,finalX, finalY);
		xDistToTarget = startX - finalX;
		yDistToTarget = finalY - startY;
		speed = GetSpeed();
		gravity = 0.05f;
		//launchAngle1 is alternate longer travel time angle that would reach same target. Could be used for easier mode but often hits ceilling
		//launchAngle1 = atan((pow(speed, 2) + sqrt((pow(speed, 4) - gravity * (gravity * pow(xDistToTarget, 2) + 2 * yDistToTarget * pow(speed, 2))))) / (gravity * xDistToTarget));
		launchAngle2 = atan((pow(speed, 2) - sqrt((pow(speed, 4) - gravity * (gravity * pow(xDistToTarget, 2) + 2 * yDistToTarget * pow(speed, 2))))) / (gravity * xDistToTarget));
		SetAngle(launchAngle2);
		SetSpeedY(abs(speed) * sinf(launchAngle2));
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