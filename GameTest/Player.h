#pragma once
#include "App/app.h"
#include "EnemyProjectiles.h"
class Player
{
	const int numEnemies = 5;
	Enemies enemies[5];
	CSimpleSprite* playerSprite;
	Projectiles projectile;
	EnemyProjectiles eProjectile[5];
	int health;
	int stage;
	int botsRemaining;

	enum
	{
		ANIM_FORWARDS,
		ANIM_BACKWARDS,
		ANIM_LEFT,
		ANIM_RIGHT,
	};

public:
	void Init();
	void Update(float deltaTime);
	void Render();
	void StartStage();
	void Damaged();
	void GetPosition(float& playerX, float& playerY);
	void Shutdown();
};

