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
		// Save Binary text before Exit
		isPlaying = false;
}

void GameManager::PrintGameplayTitle() {
	ConsoleSetColor(ConsoleColor::GREEN, ConsoleColor::BLACK);
	std::cout << " ---------------------------------------------------------" << std::endl;
	std::cout << "  _____   ___  ___  ___ _____ ______  _       ___  __   __" << std::endl;
	std::cout << " |  __ \\ / _ \\ |  \\/  ||  ___|| ___ \\| |     / _ \\ \\ \\ / /" << std::endl;
	std::cout << " | |  \\// /_\\ \\| .  . || |__  | |_/ /| |    / /_\\ \\ \\ V /" << std::endl;
	std::cout << " | | __ |  _  || |\\/| ||  __| |  __/ | |    |  _  |  \\ /  " << std::endl;
	std::cout << " | |_\\ \\| | | || |  | || |___ | |    | |____| | | |  | |  " << std::endl;
	std::cout << "  \\____/\\_| |_/\\_|  |_/\\____/ \\_|    \\_____/\\_| |_/  \\_/  " << std::endl;
	std::cout << " ---------------------------------------------------------" << std::endl;
}

void GameManager::PrintScore(Ball* b) {

	// Change color
	ConsoleSetColor(ConsoleColor::RED, ConsoleColor::BLACK);

	// Render Brick
	std::cout << "\n Score: " << b->GetScore();
}

void GameManager::PrintLifes(Pad* p) {
	// Change color
	ConsoleSetColor(ConsoleColor::RED, ConsoleColor::BLACK);

	// Render Brick
	std::cout << "\n Lifes: " << p->GetLifes() << "\n\n";
}

void GameManager::GamePlay() {
	int sleepTime = 100; // in ms
	bool gamePlayRunning = true;

	Pad* playerPad = nullptr;
	Ball* ball = nullptr;
	std::vector<Wall> walls;
	std::vector<Brick> bricks;

	int score = 0;

	InitGamePlay(25, 15, &playerPad, &ball, walls, bricks);

	while (gamePlayRunning) {

		PrintGameplayTitle();
		PrintScore(ball);
		PrintLifes(playerPad);

		if (playerPad->GetLifes() <= 0 || bricks.size() == 0) {

			gamePlayRunning = false;

			if (playerPad->GetLifes() <= 0) {
				ConsoleSetColor(ConsoleColor::RED, ConsoleColor::BLACK);
				std::cout << " __   __ _____  _   _   _      _____  _____  _____  _ " << std::endl;
				std::cout << " \\ \\ / /|  _  || | | | | |    |  _  |/  ___||  ___|| |" << std::endl;
				std::cout << "  \\ V / | | | || | | | | |    | | | |\\ `--. | |__  | |" << std::endl;
				std::cout << "   \\ /  | | | || | | | | |    | | | | `--. \\|  __| | |" << std::endl;
				std::cout << "   | |  \\ \\_/ /| |_| | | |____\\ \\_/ //\\__/ /| |___ |_|" << std::endl;
				std::cout << "   \\_/   \\___/  \\___/  \\_____/ \\___/ \\____/ \\____/ (_)\n\n" << std::endl;
			}
			else {
				ConsoleSetColor(ConsoleColor::GREEN, ConsoleColor::BLACK);
				std::cout << " __   __ _____  _   _   _    _  _____  _   _  _ " << std::endl;
				std::cout << " \\ \\ / /|  _  || | | | | |  | ||_   _|| \\ | || |" << std::endl;
				std::cout << "  \\ V / | | | || | | | | |  | |  | |  |  \\| || |" << std::endl;
				std::cout << "   \\ /  | | | || | | | | |/\\| |  | |  | . ` || |" << std::endl;
				std::cout << "   | |  \\ \\_/ /| |_| | \\  /\\  / _| |_ | |\\  ||_|" << std::endl;
				std::cout << "   \\_/   \\___/  \\___/   \\/  \\/  \\___/ \\_| \\_/(_)\n\n" << std::endl;
			}

			std::string name = "";

			ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
			std::cout << " Introduce your name: ";
			std::cin >> name;

			//scores.insert(std::pair<std::string, int>(name, ball->GetScore()));

			SaveScore(name, ball->GetScore());

			currentScene = GameManager::MENU;
			continue;
		}

		// Update all objects
		ball->Update(walls, bricks, playerPad);
		playerPad->Update(walls);
		

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

	int sleepTime = 100;

	bool keyPressed = false;

	while (!keyPressed) {

		ConsoleSetColor(ConsoleColor::GREEN, ConsoleColor::BLACK);
		std::cout << " ----------------------------------------------------------------------" << std::endl;
		std::cout << "  _   _  _____  _____  _   _  _____  _____  _____ ______  _____  _____ " << std::endl;
		std::cout << " | | | ||_   _||  __ \\| | | |/  ___|/  __ \\|  _  || ___ \\|  ___|/  ___|" << std::endl;
		std::cout << " | |_| |  | |  | |  \\/| |_| |\\ `--. | /  \\/| | | || |_/ /| |__  \\ `--. " << std::endl;
		std::cout << " |  _  |  | |  | | __ |  _  | `--. \\| |    | | | ||    / |  __|  `--. \\" << std::endl;
		std::cout << " | | | | _| |_ | |_\\ \\| | | |/\\__/ /| \\__/\\\\ \\_/ /| |\\ \\ | |___ /\\__/ /" << std::endl;
		std::cout << " \\_| |_/ \\___/  \\____/\\_| |_/\\____/  \\____/ \\___/ \\_| \\_|\\____/ \\____/ " << std::endl;
		std::cout << " -----------------------------------------------------------------------\n\n" << std::endl;

		ConsoleSetColor(ConsoleColor::YELLOW, ConsoleColor::BLACK);
		int cont = 1;
		/*for (auto it = scores.begin(); it != scores.end(); it++) {
			std::cout << " " << cont << ". " << it->first << ":\t" << it->second << std::endl;
			cont++;
		}
		auto it = scores.begin();
		for (int i = 0; i < scores.size(); i++) {
			std::cout << " " << i + 1 << ". " << it->first << ":\t" << it->second << std::endl;
			it++;
		}*/

		std::ifstream file("scores.wcs", std::ios::binary);

		if (!file.is_open()) {
			std::cout << "Error: cannot open file" << std::endl;
			return;
		}

		std::map<int, std::string, std::greater<int>> scores; 
		std::string line;
		while (std::getline(file, line)) {
			std::size_t pos = line.find(":");
			if (pos != std::string::npos) {
				std::string userName = line.substr(0, pos);
				int score = std::stoi(line.substr(pos + 1));
				scores[score] = userName;
			}
		}
		file.close();

		int i = 0;
		for (auto it = scores.begin(); it != scores.end() && i < 5; ++it, ++i) {
			std::cout << i + 1 << ". " << it->second << ": " << it->first << std::endl;
		}


		ConsoleSetColor(ConsoleColor::RED, ConsoleColor::BLACK);
		std::cout << "\n Press Space to return" << std::endl;

		ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);

		keyPressed = GetAsyncKeyState(VK_SPACE) != 0;

		Sleep(sleepTime);
		system("cls");
	}

	currentScene = GameManager::MENU;
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

	int offsetX = 1;
	int offsetY = 11;

	// PAD
	*p = new Pad(Vector2(width / 2 + offsetX, height / 2 + height / 4 + offsetY), 1);
	
	// WALLS
	// Top Row
	w.push_back(Wall(WallType::CORNER, Vector2(0 + offsetX, offsetY)));
	for (int i = 1; i < width - 1; i++)
		w.push_back(Wall(WallType::HORIZONTAL, Vector2(i + offsetX, offsetY)));
	w.push_back(Wall(WallType::CORNER, Vector2(width - 1 + offsetX, offsetY)));
	
	// Middle Walls
	for (int i = 0; i < height - 2; i++) {
		for (int j = 0; j < 2; j++) {
			w.push_back(Wall(WallType::VERTICAL, Vector2(j * (width - 1) + offsetX, i + 1 + offsetY)));
		}
	}

	// Last Row
	w.push_back(Wall(WallType::CORNER, Vector2(0 + offsetX, height - 1 + offsetY)));
	for (int i = 1; i < width - 1; i++)
		w.push_back(Wall(WallType::HORIZONTAL, Vector2(i + offsetX, height - 1 + offsetY)));
	w.push_back(Wall(WallType::CORNER, Vector2(width - 1 + offsetX, height - 1 + offsetY)));

	// BRICKS
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j < width - 1; j++) {
			bricks.push_back(Brick(Vector2(j + offsetX, i + offsetY), 1));
		}
	}

	// BALL
	*b = new Ball(Vector2(width / 2 + offsetX, height / 2 + height / 4 - 5 + offsetY), Vector2(0, 1), 1);
}

void GameManager::SaveScore(std::string userName, int score) {
	std::ofstream file;
	
	file.open("scores.wcs", std::ios::app | std::ios::binary);

	std::string content = userName + ":" + std::to_string(score) + "\n";

	file.write(content.data(), content.size());
	
	file.close();
}