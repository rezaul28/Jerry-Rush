#include "Function_Prototype.h"
#include "TextureSprite.h"
#include "Variable_all.h"
#include "Game_Over.h"
#include "Game_Level_2.h"
#include "Game_Level_1.h"

typedef struct menustateCondition {
	int M_state : 1;
	int M_position_x : 16;
	int M_position_y : 16;
}menuState;

void instruction() {
	sf::Texture instruction;
	sf::Sprite instructionsprite;

	int introState = 1;
	while (window.isOpen()) {
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			if (evnt.type == evnt.Closed) {
				window.close();
			}

		}
		sf::Vector2i mousePos;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			mousePos = sf::Mouse::getPosition(window);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			introState = 2;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
			if (introState == 2)
				introState = 1;
			else
				return;
		}
		if (introState == 1) {
			instruction.loadFromFile("instruction.jpg");
		}
		else
			instruction.loadFromFile("instruction1.jpg");
		instructionsprite.setTexture(instruction);
		window.clear();
		window.draw(instructionsprite);
		window.display();

	}
}

void menu() {

	/////////////////////////////////////////////////////////////////////////////////////////////////////////new lines
	sf::Music introMusic;
	introMusic.openFromFile("themeMusic.wav");
	int introMusicFlag = 0;
	////////////////////////////////////////////////////////////////////////////////////////////////////////

	menuState __newGame, __highScore, __exit, __introduction;

	FILE *file_menu;
	file_menu = fopen("Menu_file.txt", "r");
	if (file_menu == NULL)
	{
		printf("File can't be opened -----> fp\n");
	}
	char menu_image_Ara[1000];

	MenuFile;
	firstWindow.loadFromFile(menu_image_Ara);
	firstWindowSprite.setTexture(firstWindow);

	MenuFile;
	imgTexture.loadFromFile(menu_image_Ara);
	sprite.setTexture(imgTexture);

	MenuFile2;
	newGame.loadFromFile(menu_image_Ara);
	newGameSprite.setTexture(newGame);
	__newGame.M_position_x = menuReceiver[0];
	__newGame.M_position_y = menuReceiver[1];
	newGameSprite.setPosition(__newGame.M_position_x, __newGame.M_position_y);

	MenuFile2;
	highScore.loadFromFile(menu_image_Ara);
	highScoreSprite.setTexture(highScore);
	__highScore.M_position_x = menuReceiver[0];
	__highScore.M_position_y = menuReceiver[1];
	highScoreSprite.setPosition(__highScore.M_position_x, __highScore.M_position_y);

	MenuFile2;
	exit0.loadFromFile(menu_image_Ara);
	exitSprite.setTexture(exit0);
	__exit.M_position_x = menuReceiver[0];
	__exit.M_position_y = menuReceiver[1];
	exitSprite.setPosition(__exit.M_position_x, __exit.M_position_y);

	MenuFile2;
	introduction.loadFromFile(menu_image_Ara);
	introductionSprite.setTexture(introduction);
	__introduction.M_position_x = menuReceiver[0];
	__introduction.M_position_y = menuReceiver[1];
	introductionSprite.setPosition(__introduction.M_position_x, __introduction.M_position_y);

	fclose(file_menu);


	while (window.isOpen()) {
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			if (evnt.type == evnt.Closed) {
				window.close();
			}

		}
		sf::Vector2i mousePos;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			mousePos = sf::Mouse::getPosition(window);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			welcomePageState = 1;
			introMusicFlag = 1;///////////////////////////////////////////////////////////////////new line
		}

		window.clear();
		if (welcomePageState == 1) {
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////new line
			if (introMusicFlag == 1) {
				introMusic.play();
				introMusicFlag = 0;
			}
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			window.draw(sprite);
			window.draw(newGameSprite);
			window.draw(highScoreSprite);
			window.draw(exitSprite);
			window.draw(introductionSprite);

			if (mousePos.x >= __newGame.M_position_x && mousePos.x <= (__newGame.M_position_x + 225) && mousePos.y >= __newGame.M_position_y && mousePos.y <= (__newGame.M_position_y + 63)) {
				introMusic.stop();///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////new line
				Game_level_1();
			}
			if (mousePos.x >= __highScore.M_position_x && mousePos.x <= (__highScore.M_position_x + 225) && mousePos.y >= __highScore.M_position_y && mousePos.y <= (__highScore.M_position_y + 63)) {
				window.draw(highScore1Sprite);
				highScoreFunction();
			}
			if (mousePos.x >= __introduction.M_position_x && mousePos.x <= (__introduction.M_position_x + 225) && mousePos.y >= __introduction.M_position_y && mousePos.y <= (__introduction.M_position_y + 63)) {
				window.draw(introduction1Sprite);
				instruction();
			}
			if (mousePos.x >= __exit.M_position_x && mousePos.x <= (__exit.M_position_x + 225) && mousePos.y >= __exit.M_position_y && mousePos.y <= (__exit.M_position_y + 63)) {
				window.draw(exit1Sprite);
				window.close();
			}
		}
		else
			window.draw(firstWindowSprite);

		window.display();
	}

}