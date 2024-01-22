#include "stdafx.h"
#include "Player.h"

void Player::Init() {
	health = 10;
	stage = 0;
	botsRemaining = 0;
	playerSprite = App::CreateSprite(".\\TestData\\Test.bmp", 8, 4);
	playerSprite->SetPosition(400.0f, 400.0f);
	float speed = 1.0f / 15.0f;
	playerSprite->CreateAnimation(ANIM_BACKWARDS, speed, { 0,1,2,3,4,5,6,7 });
	playerSprite->CreateAnimation(ANIM_LEFT, speed, { 8,9,10,11,12,13,14,15 });
	playerSprite->CreateAnimation(ANIM_RIGHT, speed, { 16,17,18,19,20,21,22,23 });
	playerSprite->CreateAnimation(ANIM_FORWARDS, speed, { 24,25,26,27,28,29,30,31 });
	playerSprite->SetScale(1.0f);
	//------------------------------------------------------------------------
	// Bullet UI Initialisation
	projectile.Init();

	
}

void Player::StartStage() {
	stage += 1;
	botsRemaining = stage;
	
	for (int i = 0; i < stage; i++) {
		enemies[i].Init();
		eProjectile[i].Init();
	}
}

void Player::Update(float deltaTime) {
	playerSprite->Update(deltaTime);
	//move player controls
	if (App::GetController().GetLeftThumbStickX() > 0.5f)
	{
		playerSprite->SetAnimation(ANIM_RIGHT);
		float x, y;
		playerSprite->GetPosition(x, y);
		if (x < APP_VIRTUAL_WIDTH/2 - 10) {
			x += 1.0f;
			playerSprite->SetPosition(x, y);
		}
	}
	if (App::GetController().GetLeftThumbStickX() < -0.5f)
	{
		playerSprite->SetAnimation(ANIM_LEFT);
		float x, y;
		playerSprite->GetPosition(x, y);
		if (x > 10) {
			x -= 1.0f;
			playerSprite->SetPosition(x, y);
		}
	}
	if (App::GetController().GetLeftThumbStickY() > 0.5f)
	{
		playerSprite->SetAnimation(ANIM_FORWARDS);
		float x, y;
		playerSprite->GetPosition(x, y);
		if (y < APP_VIRTUAL_HEIGHT - 50) {
			y += 1.0f;
			playerSprite->SetPosition(x, y);
		}
	}
	if (App::GetController().GetLeftThumbStickY() < -0.5f)
	{
		playerSprite->SetAnimation(ANIM_BACKWARDS);
		float x, y;
		playerSprite->GetPosition(x, y);
		if (y > 30) {
			y -= 1.0f;
			playerSprite->SetPosition(x, y);
		}
	}
	//Sprite rotation controls
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_UP, false))
	{
		playerSprite->SetScale(playerSprite->GetScale() + 0.1f);
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_DOWN, false))
	{
		playerSprite->SetScale(playerSprite->GetScale() - 0.1f);
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_LEFT, false))
	{
		playerSprite->SetAngle(playerSprite->GetAngle() + 0.1f);
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_RIGHT, false))
	{
		playerSprite->SetAngle(playerSprite->GetAngle() - 0.1f);
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_A, true))
	{
		playerSprite->SetAnimation(-1);
	}
	//Shoot controls
	if (App::IsKeyPressed(VK_LBUTTON) && !projectile.GetAirborn())
	{
		projectile.Shoot(playerSprite);
	}
	//restart controls
	if (App::IsKeyPressed('R') && (health<=0 || (botsRemaining <= 0 && stage == numEnemies)))
	{
		Init();
	}
	//start stage controls
	if (App::IsKeyPressed(VK_SPACE) && botsRemaining <= 0 && stage!=numEnemies)
	{
		StartStage();
	}
}

void Player::Render() {
	//Display instructions baseed on stage
	if (botsRemaining <= 0) {
		if (stage < numEnemies-1) {
			App::Print(50, 700, "Use WASD to move");
			App::Print(50, 670, "Avoid enemy projectiles");
			App::Print(50, 640, "Aim with your mouse, left click to FIRE");
			App::Print(50, 610, ("Survive all " + std::to_string(numEnemies) + " stages to win!").c_str());
			App::Print(475, 600, ("Stage: " + std::to_string(stage + 1)).c_str());
			App::Print(425, 550, "Press SPACE to start");
		}
		else if (stage == numEnemies-1) {
			App::Print(450, 600, "Final Stage");
			App::Print(425, 550, "Press SPACE to start");
		}
		else {
			App::Print(450, 600, "YOU WIN");
			App::Print(425, 550, "Press R to restart");
		}
		
	}
	//handle projectile movement and collisions
	if (health>0) {
		playerSprite->Draw();
		botsRemaining = projectile.BulletControl(numEnemies, enemies);
		for (int i = 0; i < stage; i++) {
			enemies[i].EnemyTravel();
		}
		for (int i = 0; i < stage; i++) {
			if (eProjectile[i].BulletControl(enemies[i], playerSprite)) {
				Damaged();
			}
		}

		App::Print(100, 100, ("Health: " + std::to_string(health)).c_str());
		App::DrawLine(APP_VIRTUAL_WIDTH / 2, APP_VIRTUAL_HEIGHT, APP_VIRTUAL_WIDTH / 2, 0, 1.0F, 0, 0);
	}
	//Game over
	else {
		for (int i = 0; i < numEnemies; i++) {
			enemies[i].SetActiveState(false);
		}
		App::Print(450, 400, "GAME OVER");
		App::Print(425, 350, "Press R to restart");
	}

	
}

void Player::Shutdown()
{
	delete playerSprite;
}

void Player::Damaged() {
	if (health > 0) {
		health -= 1;
	}
}

void Player::GetPosition(float& playerX, float& playerY) {
	playerSprite->GetPosition(playerX, playerY);
}