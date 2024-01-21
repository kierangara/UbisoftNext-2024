//------------------------------------------------------------------------
// Projectiles.h
//------------------------------------------------------------------------
#include "app\app.h";


class Projectiles
{
	float posX;
	float posY;
	bool inAir;
	float targetX;
	float targetY;
	float speed;
	float speedY;
	float initialAngle;
	const float M_PI = 3.14159265358979323846f;

public:
	void Init();
	void DrawBullets();
	void Shoot(CSimpleSprite *testSprite);
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
	bool GetAirborn();
	void SetAirborn(bool airborn);
	void BulletTravel();
	float InitialAngle();
	void CheckOutOfBounds();
};

