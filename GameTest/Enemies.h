#include "app\app.h";

class Enemies
{
	//****************************************************************
	// StateVariables
	// ***************************************************************
	CSimpleSprite* enemySprite;
	//movement speed of enemy
	float speed;
	const float M_PI = 3.14159265358979323846f;
	//x,y coordinates to move to, angle needed to get there
	float newX;
	float newY;
	float angle;
	//if enemy is active (alive) or not
	bool active;

public:
	//initialize starting position of enemy
	void Init();
	//--------------------------------------
	//Use random number to generate new x,y coordinates for enemy
	//Move there using angle and speed
	void MoveEnemy();
	void EnemyTravel();
	float RandomNumber(int lowerBound, int upperBound);
	//-------------------------------------
	void DrawSprite();
	void GetEnemyPosition(float& x, float& y);
	bool IsActive();
	void SetActiveState(bool activeState);
};

