//------------------------------------------------------------------------
// GameTest.cpp
/*This file implements Deadly Dodgeball is a projectile based 2D single 
player mouse and keyboard game in which the player has to defeat the 
robots in a series of stages without dying.*/
//------------------------------------------------------------------------
#include "stdafx.h"
//------------------------------------------------------------------------
//Built-in Libraries
#include <windows.h> 
#include <math.h>  
//------------------------------------------------------------------------
//API
#include "app\app.h"
//Core base class
#include "Player.h"
//------------------------------------------------------------------------
Player player;

//------------------------------------------------------------------------

//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{
	player.Init();
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime)
{
	player.Update(deltaTime);
	
	
	//------------------------------------------------------------------------
	// Sample Sound. Not used.
	//------------------------------------------------------------------------
	/*if (App::GetController().CheckButton(XINPUT_GAMEPAD_B, true))
	{
		App::PlaySound(".\\TestData\\Test.wav");
	}*/
}

//------------------------------------------------------------------------
// Add your display calls here (DrawLine,Print, DrawSprite.) 
// See App.h 
//------------------------------------------------------------------------
void Render()
{
	player.Render();
}
	
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown()
{	
	player.Shutdown();
}