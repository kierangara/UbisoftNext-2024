#include "app\app.h";

class Enemies
{
	CSimpleSprite* enemySprite;
	float speed;
	const float M_PI = 3.14159265358979323846f;
	float newX;
	float newY;
	float angle;
	bool active;

public:
	void Init();
	void MoveEnemy();
	void EnemyTravel();
	float RandomNumber(int lowerBound, int upperBound);
	void DrawSprite();
	void GetEnemyPosition(float& x, float& y);
	bool IsActive();
	void SetActiveState(bool activeState);
};

