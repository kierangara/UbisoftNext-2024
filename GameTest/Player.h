#pragma once
#include "App/app.h"
#include "EnemyProjectiles.h"
class Player
{
	//****************************************************************
	// StateVariables
	// ***************************************************************
	//numEnemies is max number of enemies, determines the number of stages
	const int numEnemies = 5;
	//Enemies is array of enemies, all inactive until initialised
	Enemies enemies[5];
	//projectile is projectile associated with player sprite
	CSimpleSprite* playerSprite;
	Projectiles projectile;
	//EnemyProjectiles array associates an EnemyProjectiles object with each enemy
	EnemyProjectiles eProjectile[5];
	//------------------------
	//variables that determine the game state
	//game ends when no health, stage progresses when no bots remaining
	int health;
	int stage;
	int botsRemaining;
	//------------------------

	//Enumerator for animation directions
	enum
	{
		ANIM_FORWARDS,
		ANIM_BACKWARDS,
		ANIM_LEFT,
		ANIM_RIGHT,
	};

public:
	//Initialise the player sprite, projectile and game state variables
	void Init();
	//Manage player movement controls and key inputs for shooting, restarting and switching stage
	void Update(float deltaTime);
	//Call projectile and enemy movement functions, display instruction UI
	void Render();
	//Reset object positions but maintain game state variables and sprite position. Increment stage and #active enemies
	void StartStage();
	//Reduce player health
	void Damaged();
	//Getter for coordinates of player sprite
	void GetPosition(float& playerX, float& playerY);
	//Called when the APP_QUIT_KEY is pressed Just before the app exits.
	void Shutdown();
};

