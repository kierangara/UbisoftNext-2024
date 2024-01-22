//------------------------------------------------------------------------
// Projectiles.h
// Base class for implementing all projectile functions
// Projectiles follow proper projectile physics with a constant downward accleration "gravity"
// Projectiles do not account for air resistance
// With current implementation each entity (player or enemy) can only
// have one projectile in the air at any given time.
//------------------------------------------------------------------------
#include "app\app.h";
#include "Enemies.h"


class Projectiles
{
	//****************************************************************
	// StateVariables
	// ***************************************************************
	//posX, posY: x,y coordinates to track top left corner of projectile
	float posX;
	float posY;
	//inAir: monitors active state of projectile, active while true.
	bool inAir;
	//targetX, targetY: x,y coordinates to track target of projectile
	float targetX;
	float targetY;
	//speed magnitude of initial velocity with initial direction initialAngle, 
	//speedY vertical component influenced by downward acceleration
	float speed;
	float speedY;
	float initialAngle;
	//------------------------------------------------------------------

	//M_PI: Pi constant defined for determining launch angles (in rad)
	const float M_PI = 3.14159265358979323846f;

public:
	//void Init(); initialises the state variable base values
	void Init();
	// void DrawBullets() draws squares for the UI element of the projectiles
	void DrawBullets();
	//-----------------------------------
	//Interfaces for state variables
	//___________________________________
	float GetPosX();
	void SetPosX(float x);
	float GetPosY();
	void SetPosY(float y);
	float GetTargetX();
	void SetTargetX(float x);
	float GetTargetY();
	void SetTargetY(float y);
	float GetSpeed();
	void SetSpeed(float newSpeed);
	void SetSpeedY(float newSpeedY);
	bool GetAirborn();
	void SetAirborn(bool airborn);
	//-----------------------------------
	//Control Functions
	//-----------------------------------
	//void Shoot(CSimpleSprite* playerSprite);
	//Shoots the projectile from the specified sprite at the initial
	//angle of the mouse from the sprite with initial speed speed
	void Shoot(CSimpleSprite* playerSprite);
	//----------------------------------
	//void BulletTravel();
	//Determines each new position of the projectile based on the
	//initial speed and angle and the downwards acceleration
	void BulletTravel();
	//---------------------------------
	//int BulletControl(int numEnemies, Enemies enemies[5]);
	//Calls the other control functions to move the bullet and
	//check for collisions
	//Returns the number of enemies remaining
	int BulletControl(int numEnemies, Enemies enemies[5]);
	//---------------------------------
	// float InitialAngle();
	//Determine the angle of the mouse relative to the player
	float InitialAngle();
	//---------------------------------
	// void SetAngle(float newAngle);
	//Set the initial angle of a shot
	void SetAngle(float newAngle);
	//---------------------------------
	//void CheckOutOfBounds();
	//Checks if the projectile is outside the bounds of the screen
	//Determined by APP_VIRTUAL_WIDTH and APP_VIRTUAL_HEIGHT
	//Deactivates the bullet if it is
	void CheckOutOfBounds();
	//---------------------------------
	//int CheckHit(int numEnemies, Enemies enemy[5]);
	//Checks if the projectile hit an enemy
	//Deactivates the bullet if so
	//Returns the number of enemies remaining
	int CheckHit(int numEnemies, Enemies enemy[5]);
	//----------------------------------
};

