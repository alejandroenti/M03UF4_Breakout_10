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
		std::cout << "  Press 2 to exit" << std::endl;
		
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

	InitGamePlay(15, 25, &playerPad, &ball, walls, bricks);

	while (gamePlayRunning) {
		// Update all objects


		// Render all objects
		playerPad->Render();
		for (Wall wall : walls) {
			wall.Render();
		}
		for (Brick brick : bricks) {
			brick.Render();
		}
		ball->Render();

		Sleep(sleepTime);
		system("cls");
	}
}

void GameManager::HighScore() {

}

void GameManager::InitGamePlay(int width, int height, Pad** p, Ball** b, std::vector<Wall>& w, std::vector<Brick>& bricks) {

	// PAD
	*p = new Pad(Vector2(width / 2, height / 2 + height / 4), 3);
	
	// WALLS
	// Top Row
	w.push_back(Wall(WallType::CORNER1, Vector2(0, 0)));
	for (int i = 1; i < width - 1; i++)
		w.push_back(Wall(WallType::HORIZONTAL, Vector2(i, 0)));
	w.push_back(Wall(WallType::CORNER2, Vector2(width - 1, 0)));
	
	// Middle Walls
	for (int i = 0; i < height - 2; i++) {
		for (int j = 0; j < 2; j++) {
			w.push_back(Wall(WallType::VERTICAL, Vector2(j * (width - 1), i + 1)));
		}
	}

	// Last Row
	w.push_back(Wall(WallType::CORNER2, Vector2(0, height - 1)));
	for (int i = 1; i < width - 1; i++)
		w.push_back(Wall(WallType::HORIZONTAL, Vector2(i, height - 1)));
	w.push_back(Wall(WallType::CORNER1, Vector2(width - 1, height - 1)));

	// BRICKS
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j < width - 1; j++) {
			bricks.push_back(Brick(Vector2(j, i + 1), i + 1));
		}
	}

	// BALL
	*b = new Ball(Vector2(width / 2, height / 2 + height / 4 - 5), Vector2(0, 1), 1);
}