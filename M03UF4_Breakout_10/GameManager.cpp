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
	case GameManager::CREDITS:
		Credits();
		break;
	}
}

void GameManager::Menu() {
	int sleepTime = 100; // in ms
	bool keyPressed = false;

	bool pressed1;
	bool pressed2;
	bool pressed3;
	bool pressed0;

	while (!keyPressed) {
		ConsoleSetColor(ConsoleColor::GREEN, ConsoleColor::BLACK);
		std::cout << " --------------------------------------------------------" << std::endl;
		std::cout << " | ___ \\| ___ \\|  ___| / _ \\ | | / /|  _  || | | ||_   _|" << std::endl;
		std::cout << " | |_/ /| |_/ /| |__  / /_\\ \\| |/ / | | | || | | |  | |  " << std::endl;
		std::cout << " | ___ \\|    / |  __| |  _  ||    \\ | | | || | | |  | |  " << std::endl;
		std::cout << " | |_/ /| |\\ \\ | |___ | | | || |\\  \\\\ \\_/ /| |_| |  | |  " << std::endl;
		std::cout << " \\____/ \\_| \\_|\\____/ \\_| |_/\\_| \\_/ \\___/  \\___/   \\_/  " << std::endl;
		std::cout << " --------------------------------------------------------\n\n" << std::endl;

		ConsoleSetColor(ConsoleColor::BLUE, ConsoleColor::BLACK);
		std::cout << " 1 - Play" << std::endl;
		std::cout << " 2 - Ranking" << std::endl;
		std::cout << " 3 - Credits\n" << std::endl;

		ConsoleSetColor(ConsoleColor::RED, ConsoleColor::BLACK);
		std::cout << " 0 - Exit" << std::endl;

		ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
		
		pressed1 = GetAsyncKeyState('1') != 0;
		pressed2 = GetAsyncKeyState('2') != 0;
		pressed3 = GetAsyncKeyState('3') != 0;
		pressed0 = GetAsyncKeyState('0') != 0;

		keyPressed = pressed1 || pressed2 || pressed3 || pressed0;

		Sleep(sleepTime);
		system("cls");
	}

	if (pressed1)
		currentScene = Scene::GAMEPLAY;
	else if (pressed2)
		currentScene = Scene::HIGHSCORE;
	else if (pressed3)
		currentScene = Scene::CREDITS;
	else
		isPlaying = false;
}

void GameManager::GamePlay() {
	int sleepTime = 100; // in ms
	bool gamePlayRunning = true;

	Pad* playerPad = nullptr;
	Ball* ball = nullptr;
	std::vector<Wall> walls;
	std::vector<Brick> bricks;

	InitGamePlay(25, 15, &playerPad, &ball, walls, bricks);

	while (gamePlayRunning) {
		// Update all objects
		ball->Update(walls, bricks, playerPad);

		// Render all objects
		playerPad->Render();
		for(std::vector<Wall>::iterator it = walls.begin(); it != walls.end(); it++)
			it->Render();
		for (std::vector<Brick>::iterator it = bricks.begin(); it != bricks.end(); it++)
			it->Render();
		ball->Render();

		// Sleep & Clear
		Sleep(sleepTime);
		system("cls");
	}
}

void GameManager::HighScore() {

}

void GameManager::Credits() {
	int sleepTime = 100;
	
	bool keyPressed = false;

	while (!keyPressed) {

		ConsoleSetColor(ConsoleColor::GREEN, ConsoleColor::BLACK);
		std::cout << " -------------------------------------------------" << std::endl;	 
		std::cout << " /  __ \\| ___ \\|  ___||  _  \\|_   _||_   _|/  ___|" << std::endl;	 
		std::cout << " | /  \\/| |_/ /| |__  | | | |  | |    | |  \\ `--. " << std::endl;	 
		std::cout << " | |    |    / |  __| | | | |  | |    | |   `--. \\" << std::endl;	 
		std::cout << " | \\__/\\| |\\ \\ | |___ | |/ /  _| |_   | |  /\\__/ /" << std::endl;	 
		std::cout << "  \\____/\\_| \\_|\\____/ |___/   \\___/   \\_/  \\____/" << std::endl;	 
		std::cout << " ------------------------------------------------\n" << std::endl;

		ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
		std::cout << " Programmed by Alejandro Lopez & Oriol Valls" << std::endl;
		std::cout << " Directed by Eduard Arnau" << std::endl;
		std::cout << " Made in ENTI\n" << std::endl;

		ConsoleSetColor(ConsoleColor::RED, ConsoleColor::BLACK);
		std::cout << " Press Space to return" << std::endl;

		ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);

		keyPressed = GetAsyncKeyState(VK_SPACE) != 0;

		Sleep(sleepTime);
		system("cls");
	}

	currentScene = GameManager::MENU;
}

void GameManager::InitGamePlay(int width, int height, Pad** p, Ball** b, std::vector<Wall>& w, std::vector<Brick>& bricks) {

	// PAD
	*p = new Pad(Vector2(width / 2, height / 2 + height / 4), 3);
	
	// WALLS
	// Top Row
	w.push_back(Wall(WallType::CORNER, Vector2(0, 0)));
	for (int i = 1; i < width - 1; i++)
		w.push_back(Wall(WallType::HORIZONTAL, Vector2(i, 0)));
	w.push_back(Wall(WallType::CORNER, Vector2(width - 1, 0)));
	
	// Middle Walls
	for (int i = 0; i < height - 2; i++) {
		for (int j = 0; j < 2; j++) {
			w.push_back(Wall(WallType::VERTICAL, Vector2(j * (width - 1), i + 1)));
		}
	}

	// Last Row
	w.push_back(Wall(WallType::CORNER, Vector2(0, height - 1)));
	for (int i = 1; i < width - 1; i++)
		w.push_back(Wall(WallType::HORIZONTAL, Vector2(i, height - 1)));
	w.push_back(Wall(WallType::CORNER, Vector2(width - 1, height - 1)));

	// BRICKS
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j < width - 1; j++) {
			bricks.push_back(Brick(Vector2(j, i), 1));
		}
	}

	// BALL
	*b = new Ball(Vector2(width / 2, height / 2), Vector2(1, 1), 1);
}