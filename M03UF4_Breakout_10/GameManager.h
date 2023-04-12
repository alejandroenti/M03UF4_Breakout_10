#pragma once

#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <map>

#include "ConsoleControl.h"
#include "Ball.h"
#include "Brick.h"
#include "Pad.h"
#include "Wall.h"

class GameManager {

private:
	std::map<std::string, int> scores;

	void Menu();
	void GamePlay();
	void HighScore();
	void Credits();
	void InitGamePlay(int width, int height, Pad** p, Ball** b, std::vector<Wall>& w, std::vector<Brick>& bricks);

public:
	enum Scene { MENU, GAMEPLAY, HIGHSCORE, CREDITS};
	Scene currentScene;
	bool isPlaying;

	GameManager()
		: currentScene(MENU), isPlaying(true) {}
	void Update();
	void PrintGameplayTitle();
	void PrintScore(Ball* b);
	void PrintLifes(Pad* p);
};