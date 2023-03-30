#include "GameManager.h"

void GameManager::Update() {

	switch (currentScene)
	{
	case GameManager::MENU:
		Menu();
		break;
	case GameManager::GAMEPLAY:
		GamePlay();
		break;
	case GameManager::HIGHSCORE:
		HighScore();
		break;
	}
}

void GameManager::Menu() {
	int sleepTime = 16; // in ms
	bool keyPressed = false;

	bool pressed1;
	bool pressed2;

	while (!keyPressed) {
		std::cout << "--- MAIN MENU ---" << std::endl;
		std::cout << "  Press 1 to play" << std::endl;
		std::cout << "  Press 2 to play" << std::endl;
		
		pressed1 = GetAsyncKeyState('1') != 0;
		pressed2 = GetAsyncKeyState('2') != 0;

		keyPressed = pressed1 || pressed2;

		Sleep(sleepTime);
		system("cls");
	}

	if (pressed1)
		currentScene = Scene::GAMEPLAY;
	else
		isPlaying = false;
}

void GameManager::GamePlay() {
	int sleepTime = 16; // in ms
	bool gamePlayRunning = true;

	Pad* playerPad = nullptr;
	Ball* ball = nullptr;
	std::vector<Wall> walls;
	std::vector<Brick> bricks;

	InitGamePlay(15, 25, playerPad, ball, walls, bricks);

	while (gamePlayRunning) {
		// Update all objects


		// Render all objects
		playerPad->Render();

		Sleep(sleepTime);
		system("cls");
	}
}

void GameManager::HighScore() {

}

void GameManager::InitGamePlay(int width, int height, Pad* p, Ball* b, std::vector<Wall>& w, std::vector<Brick>& bricks) {

	p = new Pad(Vector2(width / 2, height / 2 + height / 4), 3);
}