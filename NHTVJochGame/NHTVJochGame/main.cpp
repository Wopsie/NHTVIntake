#include<SFML\Window.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include"Player.h"
#include "Projectile.h"
#include "Globals.h"
using namespace std;
using namespace sf;
	
void StartScreen(RenderWindow&);
void TutorialScreen(RenderWindow&);
void GameOverScreen(RenderWindow&);
void Reset();

Font font;
Text titleText;
Text nameText;
Text startText;
Text openTutorialText;
Text tutorialText;
Text GameoverText;
Text scoreText;
Text liveScoreText;
Globals globals;

int enemyNumberX = 8;
int enemyNumberY = 4;

bool pressed;
bool oldPressed;
bool keyReleased;

int main() {
	RenderWindow window{ VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Space Reflectors" };
	window.setFramerateLimit(60);

	//for displaying score during gameplay
	liveScoreText.setFont(font);
	liveScoreText.setOutlineColor(Color::White);
	liveScoreText.setCharacterSize(15);
	liveScoreText.setPosition(0, 0);

	if (!font.loadFromFile("Resources/Font/Xerox_Sans_Serif_Wide_Bold.ttf")) {
		cout << "cant load font" << endl;
	}

	Player player = Player(WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 1.2f);
	
	for (size_t i = 0; i < enemyNumberX; i++){
		for (size_t j = 0; j < enemyNumberY; j++){
			Enemy enemy = Enemy(60 + (i * 90), 40 + (j * 60));
			globals.AddEnemy(enemy);
		}
	}

	//main loop
	while (true) {
		window.clear(Color::Black);
		if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) break;

		if (gameState == 0){
			//STARTSCREEN
			StartScreen(window);
		}else if (gameState == 1){
			//GAMEPLAY
			if (enemyList.size() == 0) {
				globals.GameOver(true);
			}

			stringstream scoreStream;
			scoreStream << score;
			liveScoreText.setString("Score: " + scoreStream.str());
			window.draw(liveScoreText);

			//update & draw player
			player.Update();
			player.Draw(window);

			//update & draw enemies
			for (size_t i = 0; i < enemyList.size(); i++) {
				if (enemyList[i].getAlive()) {
					enemyList[i].Update();
					enemyList[i].Draw(window);
				}
				else
					enemyList.erase(enemyList.begin() + i);
			}

			//update & draw bullets
			for (size_t i = 0; i < projectileList.size(); i++){
				if (projectileList[i].getAlive()) {
					projectileList[i].Update();
					projectileList[i].Draw(window);
				}else{
					//if bullet is not alive, erase
					projectileList.erase(projectileList.begin()+i);
				}
			}
		}else if(gameState == 2) {
			//GAME OVER
			GameOverScreen(window);
		}
		else if (gameState == 4) {
			//TUTORIAL
			TutorialScreen(window);
		}



		window.display();
	}
	return 0;
}

void GameOverScreen(RenderWindow &win) {
	if (Keyboard::isKeyPressed(Keyboard::Key::BackSpace)) {
		globals.ResetScore();
		Reset();
		gameState = 0;
	}

	GameoverText.setFont(font);
	if (playerWon){
		GameoverText.setString("You defeated the evil aliens and saved the planet!");
	}else {
		GameoverText.setString("You lost the war and the evil aliens have destroyed the planet");
	}
	GameoverText.setOutlineColor(Color::White);
	GameoverText.setCharacterSize(20);
	GameoverText.setOrigin(GameoverText.getGlobalBounds().width / 2.f, GameoverText.getGlobalBounds().height / 2.f);
	GameoverText.setPosition(WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 2.f);
	win.draw(GameoverText);

	stringstream scoreStream;
	scoreStream << score;
	scoreText.setFont(font);
	scoreText.setString("Score: " + scoreStream.str());
	scoreText.setOutlineColor(Color::White);
	scoreText.setCharacterSize(20);
	scoreText.setOrigin(scoreText.getGlobalBounds().width / 2.f, scoreText.getGlobalBounds().height / 2.f);
	scoreText.setPosition(WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 1.5f);
	win.draw(scoreText);
}

void TutorialScreen(RenderWindow &win) {
	if(Keyboard::isKeyPressed(Keyboard::Key::BackSpace)) {
		gameState = 0;
	}

	tutorialText.setFont(font);
	tutorialText.setString("Defeat all aliens! \n You can only hurt them \n by reflecting your lasers off the edges of the screen. \n \n Press 'Backspace' to return to start screen");
	tutorialText.setOutlineColor(Color::White);
	tutorialText.setCharacterSize(20);
	tutorialText.setOrigin(tutorialText.getGlobalBounds().width / 2.f, tutorialText.getGlobalBounds().height / 2.f);
	tutorialText.setPosition(WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 2.f);
	win.draw(tutorialText);

}

void StartScreen(RenderWindow &win) {			
	if (Keyboard::isKeyPressed(Keyboard::Key::Return)){
		gameState = 1;
		pressed = true;
	}else
		pressed = false;

	if (Keyboard::isKeyPressed(Keyboard::Key::Space)) {
		if(keyReleased)
			gameState = 4;

		pressed = true;
	}else
		pressed = false;
	
	if (oldPressed) {
		if (!pressed) {
			keyReleased = true;
			pressed = false;
			oldPressed = false;
		}
	}

	oldPressed = pressed;

	nameText.setFont(font);
	nameText.setString("By Jochem Beltman");
	nameText.setOutlineColor(Color::White);
	nameText.setCharacterSize(15);
	nameText.setPosition(0,0);
	win.draw(nameText);

	titleText.setFont(font);
	titleText.setString("Space Reflectors");
	titleText.setOutlineColor(Color::White);
	titleText.setCharacterSize(40);
	titleText.setOrigin(titleText.getGlobalBounds().width / 2.f, titleText.getGlobalBounds().height / 2.f);
	titleText.setPosition(WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 2.f);
	win.draw(titleText);

	startText.setFont(font);
	startText.setString("Press 'Return' to start");
	startText.setOutlineColor(Color::White);
	startText.setCharacterSize(20);
	startText.setOrigin(startText.getGlobalBounds().width / 2.f, startText.getGlobalBounds().height / 2.f);
	startText.setPosition(WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 1.5f);
	win.draw(startText);

	openTutorialText.setFont(font);
	openTutorialText.setString("Press 'Space' for tutorial");
	openTutorialText.setOutlineColor(Color::White);
	openTutorialText.setCharacterSize(20);
	openTutorialText.setOrigin(openTutorialText.getGlobalBounds().width / 2.f, openTutorialText.getGlobalBounds().height / 2.f);
	openTutorialText.setPosition(WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 1.2f);
	win.draw(openTutorialText);
}

void Reset() {
	Player player = Player(WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 1.2f);
	//globals.AddToObjList(player);

	for (size_t i = 0; i < enemyNumberX; i++) {
		for (size_t j = 0; j < enemyNumberY; j++) {
			Enemy enemy = Enemy(60 + (i * 90), 40 + (j * 60));
			globals.AddEnemy(enemy);
		}
	}
}