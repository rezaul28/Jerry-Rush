typedef struct highScore {
	char name[100];
	int stracPoint;
}structure;

structure score[10], tm;

using namespace std;
using namespace sf;

//this function is for saveing the name, inputed in entername function in file 
void saveingName(string  playerInput) {
	char str[100];
	strcpy_s(str, playerInput.c_str());
	FILE *file;
	fopen_s(&file, "highScore.txt", "w");
	fprintf(file, "%s", str);
	fclose(file);
	return;
}


//this function is for input player name from window.
void entername() {
	int commentShowState = 0;
	font.loadFromFile("arial.ttf");
	sf::Event event;
	sf::String playerInput;
	sf::Text playerText;
	playerText.setFont(font);
	playerText.setPosition(300, 300);
	playerText.setFillColor(sf::Color::Color(255, 255, 255));

	enterUrName.setFont(font);
	enterUrName.setString("Enter Your Name");
	enterUrName.setFillColor(sf::Color::Color(255, 255, 255));
	enterUrName.setPosition(300, 250);
	enterUrName.setCharacterSize(30);

	commentText.setString("Press ENTER to continue");
	commentText.setFont(font);
	commentText.setFillColor(sf::Color::Color(255, 255, 255));
	commentText.setPosition(750, 600);
	commentText.setCharacterSize(20);

	while (window.isOpen()) {

		while (window.pollEvent(event)) {
			if (event.type == event.Closed) {
				window.close();
			}

			if (event.type == sf::Event::TextEntered)
			{

				if (event.text.unicode > 64 && event.text.unicode < 91 || event.text.unicode>96 && event.text.unicode < 123)
				{
					playerInput += event.text.unicode;
					commentShowState = 1;

				}
				playerText.setString(playerInput);
				break;

			}
		}
		window.draw(enterUrName);
		window.draw(playerText);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {

			saveingName(playerInput);
			point = 0;
			life = 1;
			variable();
			return;
		}
		if (commentShowState == 1) {
			window.draw(commentText);
		}
		window.display();
		window.clear(sf::Color::Color(0, 0, 51));


	}

}



int readHighScoreFromFile(int i, int limit) {
	FILE *file;
	file = fopen("text.txt", "r");
	for (i; i < limit; i++) {
		fscanf(file, "%d", &score[i].stracPoint);
		fscanf(file, "%s", score[i].name);
	}
	fclose(file);
	return 0;
}

//this function is for sort structure accourding to the highscores.
int getHighscores() {

	FILE *file;
	file = fopen("highScore.txt", "r");
	fscanf(file, "%s", score[0].name);
	score[0].stracPoint = point;
	printf("%d\n%s\n", score[0].stracPoint, score[0].name);
	fclose(file);

	readHighScoreFromFile(1, 6);

	//the loop is for sort the structure descending order.
	for (int j = 0; j < 6; j++) {
		for (int k = 0; k < 5; k++) {
			if (score[k].stracPoint < score[k + 1].stracPoint) {
				tm = score[k];
				score[k] = score[k + 1];
				score[k + 1] = tm;
			}
		}
	}


	file = fopen("text.txt", "w");
	//The loop is for write the scores and name of sorted highscore.
	for (int k = 0; k < 5; k++) {
		fprintf(file, "%d\n%s\n", score[k].stracPoint, score[k].name);
	}
	fclose(file);
	return 0;

}

//this function is for show the highscores, when highscore button is pressed.
void highScoreFunction() {
	readHighScoreFromFile(0, 5);

	font.loadFromFile("arial.ttf");

	scoreBoard.loadFromFile("scoreboard.png");
	scoreBoardSprite.setTexture(scoreBoard);

	highscoreText.setFont(font);
	highscoreText.setFillColor(sf::Color::White);
	highscoreText.setPosition(300, 100);
	highscoreText.setCharacterSize(60);
	highscoreText.setString("High Score");

	nameText.setFont(font);
	nameText.setString("Name");
	nameText.setFillColor(sf::Color::White);
	nameText.setPosition(highScoreNamePosition_x, highScoreElementPosition_y);
	nameText.setCharacterSize(25);

	highscoreText1.setFont(font);
	highscoreText1.setFillColor(sf::Color::White);
	highscoreText1.setPosition(highScoreNamePosition_x, highScoreElementPosition_y - (highScoreElementDestance_y * 1));
	highscoreText1.setCharacterSize(25);
	highscoreText1.setString(score[0].name);

	highscoreText2.setFont(font);
	highscoreText2.setFillColor(sf::Color::White);
	highscoreText2.setPosition(highScoreNamePosition_x, highScoreElementPosition_y - (highScoreElementDestance_y * 2));
	highscoreText2.setCharacterSize(25);
	highscoreText2.setString(score[1].name);

	highscoreText3.setFont(font);
	highscoreText3.setFillColor(sf::Color::White);
	highscoreText3.setPosition(highScoreNamePosition_x, highScoreElementPosition_y - (highScoreElementDestance_y * 3));
	highscoreText3.setCharacterSize(25);
	highscoreText3.setString(score[2].name);

	highscoreText4.setFont(font);
	highscoreText4.setFillColor(sf::Color::White);
	highscoreText4.setPosition(highScoreNamePosition_x, highScoreElementPosition_y - (highScoreElementDestance_y * 4));
	highscoreText4.setCharacterSize(25);
	highscoreText4.setString(score[3].name);

	highscoreText5.setFont(font);
	highscoreText5.setFillColor(sf::Color::White);
	highscoreText5.setPosition(highScoreNamePosition_x, highScoreElementPosition_y - (highScoreElementDestance_y * 5));
	highscoreText5.setCharacterSize(25);
	highscoreText5.setString(score[4].name);

	char scoreAra[5][100];
	for (int i = 0; i < 5; i++) {
		sprintf(scoreAra[i], "%d", score[i].stracPoint);
	}

	scoreText.setFont(font);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(highScorePointPosition_x - 20, highScoreElementPosition_y - (highScoreElementDestance_y * 0));
	scoreText.setCharacterSize(25);
	scoreText.setString("Score");

	scoreNumText1.setFont(font);
	scoreNumText1.setFillColor(sf::Color::White);
	scoreNumText1.setPosition(highScorePointPosition_x, highScoreElementPosition_y - (highScoreElementDestance_y * 1));
	scoreNumText1.setCharacterSize(25);
	scoreNumText1.setString(scoreAra[0]);

	scoreNumText2.setFont(font);
	scoreNumText2.setFillColor(sf::Color::White);
	scoreNumText2.setPosition(highScorePointPosition_x, highScoreElementPosition_y - (highScoreElementDestance_y * 2));
	scoreNumText2.setCharacterSize(25);
	scoreNumText2.setString(scoreAra[1]);

	scoreNumText3.setFont(font);
	scoreNumText3.setFillColor(sf::Color::White);
	scoreNumText3.setPosition(highScorePointPosition_x, highScoreElementPosition_y - (highScoreElementDestance_y * 3));
	scoreNumText3.setCharacterSize(25);
	scoreNumText3.setString(scoreAra[2]);

	scoreNumText4.setFont(font);
	scoreNumText4.setFillColor(sf::Color::White);
	scoreNumText4.setPosition(highScorePointPosition_x, highScoreElementPosition_y - (highScoreElementDestance_y * 4));
	scoreNumText4.setCharacterSize(25);
	scoreNumText4.setString(scoreAra[3]);

	scoreNumText5.setFont(font);
	scoreNumText5.setFillColor(sf::Color::White);
	scoreNumText5.setPosition(highScorePointPosition_x, highScoreElementPosition_y - (highScoreElementDestance_y * 5));
	scoreNumText5.setCharacterSize(25);
	scoreNumText5.setString(scoreAra[4]);

	serialNumber1.setFont(font);
	serialNumber1.setFillColor(sf::Color::White);
	serialNumber1.setPosition(highScoreSerialPosition_x, highScoreElementPosition_y - (highScoreElementDestance_y * 1));
	serialNumber1.setCharacterSize(25);
	serialNumber1.setString("1.");

	serialNumber2.setFont(font);
	serialNumber2.setFillColor(sf::Color::White);
	serialNumber2.setPosition(highScoreSerialPosition_x, highScoreElementPosition_y - (highScoreElementDestance_y * 2));
	serialNumber2.setCharacterSize(25);
	serialNumber2.setString("2.");

	serialNumber3.setFont(font);
	serialNumber3.setFillColor(sf::Color::White);
	serialNumber3.setPosition(highScoreSerialPosition_x, highScoreElementPosition_y - (highScoreElementDestance_y * 3));
	serialNumber3.setCharacterSize(25);
	serialNumber3.setString("3.");

	serialNumber4.setFont(font);
	serialNumber4.setFillColor(sf::Color::White);
	serialNumber4.setPosition(highScoreSerialPosition_x, highScoreElementPosition_y - (highScoreElementDestance_y * 4));
	serialNumber4.setCharacterSize(25);
	serialNumber4.setString("4.");

	serialNumber5.setFont(font);
	serialNumber5.setFillColor(sf::Color::White);
	serialNumber5.setPosition(highScoreSerialPosition_x, highScoreElementPosition_y - (highScoreElementDestance_y * 5));
	serialNumber5.setCharacterSize(25);
	serialNumber5.setString("5.");


	while (window.isOpen()) {
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			if (evnt.type == evnt.Closed) {
				window.close();
			}

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace)) {
			return;
		}

		window.clear(sf::Color::Color(0, 0, 51));
		window.draw(scoreBoardSprite);
		window.draw(nameText);
		window.draw(highscoreText);
		window.draw(highscoreText1);
		window.draw(highscoreText2);
		window.draw(highscoreText3);
		window.draw(highscoreText4);
		window.draw(highscoreText5);
		window.draw(serialNumber1);
		window.draw(serialNumber2);
		window.draw(serialNumber3);
		window.draw(serialNumber4);
		window.draw(serialNumber5);
		window.draw(scoreText);
		window.draw(scoreNumText1);
		window.draw(scoreNumText2);
		window.draw(scoreNumText3);
		window.draw(scoreNumText4);
		window.draw(scoreNumText5);
		window.display();
	}
}

//this function is for show the window for game over.
void gameOver() {
	getHighscores();
	font.loadFromFile("arial.ttf");

	gameOverText.setString("Game Over");
	gameOverText.setFont(font);
	gameOverText.setFillColor(sf::Color::Color(255, 255, 255));
	gameOverText.setPosition(350, 310);
	gameOverText.setCharacterSize(50);

	commentInGameOver.setString("Press ENTER to continue");
	commentInGameOver.setFont(font);
	commentInGameOver.setFillColor(sf::Color::Color(255, 255, 255));
	commentInGameOver.setPosition(750, 600);
	commentInGameOver.setCharacterSize(20);

	while (window.isOpen()) {
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			if (evnt.type == evnt.Closed) {
				window.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				window.clear();
				return;
			}

		}


		window.clear(sf::Color::Color(0, 0, 51));
		window.draw(commentInGameOver);
		window.draw(gameOverText);
		window.display();
	}
}
