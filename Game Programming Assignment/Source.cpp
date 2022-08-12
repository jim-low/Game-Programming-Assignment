#include <iostream>
#include <vector>
#include <stack>

class Game {
public:
	Game() {}

	virtual ~Game() {}

	virtual void update() {
		std::cout << "game is updating" << std::endl;
	}

	virtual void render() {
		std::cout << "game is rendering" << std::endl;
	}
};

class Menu : public Game {
public:
	Menu() {
		std::cout << "menu is being created" << std::endl;
	}

	~Menu() {
		std::cout << "menu is being destroyed" << std::endl;
	}

	void update() {
		std::cout << "menu is updating" << std::endl;
	}

	void render() {
		std::cout << "menu is rendering" << std::endl;
	}
};

class Level1 : public Game {
public:
	Level1() {
		std::cout << "level 1 is being created" << std::endl;
	}

	~Level1() {
		std::cout << "level1 is being destroyed" << std::endl;
	}

	void update() {
		std::cout << "level 1 is updating" << std::endl;
	}

	void render() {
		std::cout << "level 1 is rendering" << std::endl;
	}
};

class Level2 : public Game {
public:
	Level2() {
		std::cout << "level 2 is being created" << std::endl;
	}

	~Level2() {
		std::cout << "level 2 is being destroyed" << std::endl;
	}

	void update() {
		std::cout << "level 2 is updating" << std::endl;
	}
	void render() {
		std::cout << "level 2 is rendering" << std::endl;
	}
};

std::stack<Game*> games;
int currentLevel;

void removeLevel() {
	delete games.top();
	games.pop();
}

void backToMenu() {
	while (games.size() - 1) {
		removeLevel();
	}
}

int main() {
	bool isGameRunning = true;

	// initialization
	
	games.push(new Menu());
	games.push(new Level1());
	currentLevel = 1;

	// game loop
	std::string bruh;
	while (isGameRunning && games.size()) {
		games.top()->update();
		games.top()->render();
		std::cin >> bruh;
		
		if (bruh == "end") {
			break;
		}
		else if (bruh == "lose") {
			std::cout << "you try again lah" << std::endl;
		}
		else if (bruh == "back") {
			removeLevel();
			--currentLevel;
		}
		else if (bruh == "menu") {
			backToMenu();
			currentLevel = 0;
		}
		else if (bruh == "win") {
			if (currentLevel == 1) {
				games.push(new Level2());
			}
			else if (currentLevel == 0) {
				games.push(new Level1());
			}

			if (currentLevel < 2) {
				++currentLevel;
			}
			
		}
	}

	// clean up

	while (games.size()) {
		removeLevel();
	}

	std::cout << "end of game, ggez" << std::endl;

	return 0;
}