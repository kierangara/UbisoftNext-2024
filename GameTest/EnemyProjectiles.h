#pragma once
#include "App/app.h"
//#include "Enemies.h"
#include "Projectiles.h"

class EnemyProjectiles: public Projectiles
{
private:
	//****************************************************************
	// StateVariables
	// ***************************************************************
	//Distance and time for projectile to reach player
	float xDistToTarget, yDistToTarget, timeToTarget;
	//Start is enemy coordinates, final is player coordinates
	float startX, startY, finalX, finalY;
	//launch angle based on player location. angle 1 bigger, longer flight time. Not used in this implementation
	float launchAngle1, launchAngle2;
	//initial speed of projectile
	float speed;
	//downward deceleration
	float gravity;

public:
	//Shoot projectile finding angle based on target (player) position
	void Shoot(Enemies enemy, CSimpleSprite* target);
	//track projectile to determine if active and if hits. Return true if hit
	bool BulletControl(Enemies enemy, CSimpleSprite* target);
	void GetAllyPosition(CSimpleSprite* target, float& allyX, float& allyY);
	//Check for bullet hitting player, return true if hit
	bool CheckHit(CSimpleSprite* target);
};

