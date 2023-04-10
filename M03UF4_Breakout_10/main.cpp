#include <stdlib.h>
#include <time.h>

#include "GameManager.h"

int main() {

	srand(time(NULL));

	GameManager game;

	while (game.isPlaying) {
		game.Update();
	}

	return 0;
}