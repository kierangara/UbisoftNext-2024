#pragma once
#include "App/app.h"
//#include "Enemies.h"
#include "Projectiles.h"

class EnemyProjectiles: public Projectiles
{
private:
	float xDistToTarget, yDistToTarget, timeToTarget;
	float startX, startY, finalX, finalY;
	float launchAngle1, launchAngle2;
	float speed;
	float gravity;
	/*float posX;
	float posY;
	bool inAir;
	float targetX;
	float targetY;
	float speed;
	float speedY;
	float initialAngle;
	const float M_PI = 3.14159265358979323846f;*/

public:
	//void Init();
	//void DrawBullets();
	void Shoot(Enemies enemy, CSimpleSprite* target);
	bool BulletControl(Enemies enemy, CSimpleSprite* target);
	void GetAllyPosition(CSimpleSprite* target, float& allyX, float& allyY);
	bool CheckHit(CSimpleSprite* target);
};

