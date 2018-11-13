typedef struct stateCondition2 {
	int state : 1;
	int position_x : 16;
	int position_y : 16;
}state_Level2;

#define imageFile2  fscanf(fileImage2, "%s" , imageAra2)
#define variableFileLevel2 fscanf(fileImage2, "%d", &receiverFromFile)

void finish(){
	srand(time(0));

	finishTexture.loadFromFile("finish.jpg");
	finishSprite.setTexture(finishTexture);
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
			return;
		}
		window.clear();
		window.draw(finishSprite);
		window.display();
	}


}
void Game_level_2() {
	variable();
	gameState = 1;
	srand(time(NULL));

	position_y += 7;
	blockPosition_y += 7;
	coinPosition_y += 7;
	birdPosition_y += 7;
	heartPosition_y += 7;
	tomPosition_y += 10;
	boxPosition_y += 7;

	sf::Clock clock;
	sf::Time time = sf::microseconds(20);

	sf::Clock clock1;
	sf::Time time1 = sf::milliseconds(500);

	sf::Clock gameOverClock;
	sf::Time gameOverTime = sf::milliseconds(1000);

	state_Level2 structPoint, structLife;

	//---->>>>Loading pictures from image file

	FILE *fileImage2;
	fileImage2 = fopen("JR_imagefile2.txt", "r");
	if (fileImage2 == NULL)
	{
		printf("File can't be opened -----> fp\n");
	}
	char imageAra2[1000];


	imageFile2;
	background.loadFromFile(imageAra2);
	backgroundSprite.setTexture(background);


	background1.loadFromFile(imageAra2);
	backgroundSprite1.setTexture(background1);

	imageFile2;
	coin.loadFromFile(imageAra2);
	coinSprite1.setTexture(coin);
	coinSprite2.setTexture(coin);
	coinSprite3.setTexture(coin);

	imageFile2;
	heart.loadFromFile(imageAra2);
	heartSprite.setTexture(heart);

	imageFile2;
	block2.loadFromFile(imageAra2);
	blockSprite2.setTexture(block2);

	imageFile2;
	stone1.loadFromFile(imageAra2);
	stoneSprite1.setTexture(stone1);

	imageFile2;
	box.loadFromFile(imageAra2);
	boxSprite.setTexture(box);

	pause.loadFromFile("set.png");
	pauseSprite.setTexture(pause);
	pauseSprite.setPosition(10, 50);

	resume.loadFromFile("reset.png");
	resumeSprite.setTexture(resume);
	resumeSprite.setPosition(100, 50);

	go_to_menu.loadFromFile("GEM.png");
	go_to_menuSprite.setTexture(go_to_menu);
	go_to_menuSprite.setPosition(180, 50);

	imageFile2;
	font.loadFromFile(imageAra2);

	pointText.setFont(font);
	pointText.setFillColor(sf::Color::Black);
	variableFileLevel2;
	structPoint.position_x = receiverFromFile;
	structPoint.position_y = receiverFromFile;
	pointText.setPosition(structPoint.position_x, structPoint.position_y);
	pointText.setCharacterSize(25);

	lifeText.setFont(font);
	lifeText.setFillColor(sf::Color::Black);
	variableFileLevel2;
	structLife.position_x = receiverFromFile;
	variableFileLevel2;
	structLife.position_y = receiverFromFile;
	lifeText.setPosition(structLife.position_x, structLife.position_y);
	lifeText.setCharacterSize(25);


	char backState[] = { "b1.png" };


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
		int random = rand() % 100;
		if ((mousePos.x >= 10 && mousePos.x <= 85 && mousePos.y >= 50 && mousePos.y <= 122)) {


			flag = 0;


		}
		if ((mousePos.x >= 100 && mousePos.x <= 159 && mousePos.y >= 50 && mousePos.y <= 122)) {


			flag = 1;


		}
		if ((mousePos.x >= 180 && mousePos.x <= 270 && mousePos.y >= 50 && mousePos.y <= 122)) {

			return;


		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {

			flag = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {

			flag = 1;
		}

		if (clock.getElapsedTime() > time && gameState == 1) {

			backgroundSprite1.setPosition(backgroundPosition2_x, 0);
			backgroundSprite.setPosition(backgroundPosition1_x, 0);
			coinSprite1.setPosition(coin1Position_x, coinPosition_y);
			coinSprite2.setPosition(coin2Position_x, coinPosition_y);
			coinSprite3.setPosition(coin3Position_x, coinPosition_y);
			heartSprite.setPosition(heartPosition_x, heartPosition_y);
			blockSprite2.setPosition(block2Position_x, blockPosition_y);
			stoneSprite1.setPosition(stonePosition_x, stonePosition_y);
			boxSprite.setPosition(boxPosition_x, boxPosition_y);

			//------>>>>Stone Contact
			if (position_x >= stonePosition_x && position_x <= (stonePosition_x + 15) && jumpState == 0) {
				life--;
				lifeState = 1;
				tomPosition_x += 15;
			}

			//------>>>>Box Contact
			if (position_x >= boxPosition_x && position_x <= (boxPosition_x + 15) && jumpState == 0) {
				life--;
				lifeState = 1;
				tomPosition_x += 15;
			}

			if (life < 1) {
				gameState = 0;
				gameOverClock.restart();
			}

			//------>>>>Point contact---1---2---3
			if (position_x >= coin1Position_x && position_x < (coin1Position_x + 8) && jumpState == 0) {
				point++;
				replacement(coin1Position_x, -50);
			}
			if (position_x >= coin2Position_x && position_x < (coin2Position_x + 8) && jumpState == 0) {
				point++;
				replacement(coin2Position_x, -50);
			}
			if (position_x >= coin3Position_x && position_x < (coin3Position_x + 8) && jumpState == 0) {
				point++;
				replacement(coin3Position_x, -50);
			}

			//----->>>>Life
			if (position_x >= heartPosition_x && position_x <= (heartPosition_x + 12) && jumpState == 1) {
				life++;
				replacement(heartPosition_x, -50);
				tomPosition_x -= 15;
			}

			//---->>>>Block replacement
			if (block2Position_x < -100) {
				replacement(block2Position_x, screen_width + 10);
				blockState1 = 0;
			}
			//--->>>Box replacement
			if (boxPosition_x < -70) {
				replacement(boxPosition_x, screen_width + 50);
				boxState = 0;
			}
			//------>>>>Point + Life + Fire Text
			sprintf_s(pointAra, "Point : %d", point);
			pointText.setString(pointAra);

			sprintf_s(lifeAra, "Life : %d", life);
			lifeText.setString(lifeAra);
			sf::Texture jerry;
			sf::Sprite jerrySprite;

			if (x > 9)
				x = 0;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				jerry.loadFromFile("downJerry.png");
				jerrySprite.setPosition(position_x + 30, position_y + 25);

			}

			//it,s for jump----->>>>	
			else if (clock1.getElapsedTime() > time1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

				jumpState = 1;

			}

			else {

				jerry.loadFromFile(jerryAra[x]);
				jerrySprite.setPosition(position_x, position_y);
			}
			if (jumpState == 1) {
				jerry.loadFromFile("1.png");
				jumpPosition_x += 10;
				jumpPosition_y = 1.5 * (jumpPosition_x - ((9.8*jumpPosition_x*jumpPosition_x) / 1000 * (.5)));
				jerrySprite.setPosition(position_x, position_y - jumpPosition_y);
				clock1.restart();
			}

			if (jumpPosition_x > 190) {
				jumpState = 0;
				jumpPosition_x = 0;
			}
			if (flag == 1) x += 1;
			jerrySprite.setTexture(jerry);

			levelState = 0;//--->>>After level complete fixed background

			//----->>>>Tom Sprite + Texture
			sf::Texture tom;
			sf::Sprite tomSprite;
			if (flag == 1) y++;
			if (y > 13) {
				y = 0;
			}


			//----->>>>Bird Sprite + Texture
			sf::Texture bird;
			sf::Sprite birdSprite;
			bird.loadFromFile(birdAra[birdIndex]);
			birdSprite.setPosition(birdPosition_x, birdPosition_y);
			birdSprite.setTexture(bird);
			if (birdState == 1) {

				birdPosition_x -= 30;
			}
			if (birdPosition_x < -50) {
				replacement(birdPosition_x, screen_width + 100);
				birdState = 0;
			}
			if (flag == 1) birdIndex++;
			if (birdIndex > 5) {
				birdIndex = 0;
			}
			//--->>>Coin replacement---1----2----3--
			if (coin1Position_x < -100) {
				replacement(coin1Position_x, screen_width);
				coinState1 = 0;
			}
			if (coin2Position_x < -100) {
				replacement(coin2Position_x, screen_width + 40);
				coinState2 = 0;
			}
			if (coin3Position_x < -100) {
				replacement(coin3Position_x, screen_width + 80);
				coinState3 = 0;
			}

			//--->>>Heart replacement
			if (heartPosition_x < 0) {
				replacement(heartPosition_x, screen_width + 100);
				heartState = 0;
			}

			//--->>>Stone replacement
			if (stonePosition_x < -70) {
				replacement(stonePosition_x, screen_width + 50);
				sotneState1 = 0;
			}

			//--->>>Box replacement
			if (boxPosition_x < -70) {
				replacement(boxPosition_x, screen_width + 750);
				boxState = 0;
			}
			//------>>>>>Animation
			if (position_x > 320 && levelCount < level2Count && flag == 1) { // || _level_state == 0) {

				backgroundPosition1_x -= 10;
				backgroundPosition2_x -= 10;

				if (heartState == 1) {
					heartPosition_x -= 10;
				}
				if (sotneState1 == 1) {
					stonePosition_x -= 10;
				}
				if (boxState == 1) {
					boxPosition_x -= 10;
				}
				if (coinState1 == 1) {
					coin1Position_x -= 10;
				}
				if (coinState3 == 1) {
					coin3Position_x -= 10;
				}
				if (coinState2 == 1) {
					coin2Position_x -= 10;
				}
				if ((blockState1 == 1)) {
					block2Position_x -= 10;
				}

				if (backgroundPosition1_x < -1024)
					replacement(backgroundPosition1_x, backgroundPosition2_x + 1023), levelCount++;//---->>>>Level = No of background shift;

				if (backgroundPosition2_x < -1024)
					replacement(backgroundPosition2_x, backgroundPosition1_x + 1023), levelCount++;//---->>>>Level = No of background shift


				if (levelCount >= level2Count) {
					levelState = 0;
				}
			}

			else if (levelState == 0 && flag == 1)
				position_x += 10, tomPosition_x += 10;



			if (position_x > 1015) { 
				getHighscores();
				finish();
				return;

			}



			//----->>>>Jerry falling into hole
			if (position_x >= block2Position_x && position_x <= (block2Position_x + 100) && jumpState == 0) {
				jerrySprite.setPosition(block2Position_x + 20, position_y + 90);
				gameState = 0;
				gameOverClock.restart();
			}

			//--->>>>Tom animation
			if ((tomPosition_x >= (stonePosition_x - 100) && tomPosition_x <= (stonePosition_x + 70)) || (tomPosition_x >= (block2Position_x - 100) && tomPosition_x <= (block2Position_x + 100) || (tomPosition_x >= boxPosition_x - 50 && tomPosition_x <= boxPosition_x + 50))) {

				tom.loadFromFile("tom5.png");
				tomSprite.setPosition(tomPosition_x, tomPosition_y - 40);
				//window.clear();
			}
			else {
				tom.loadFromFile(tomAra[y]);
				tomSprite.setPosition(tomPosition_x, tomPosition_y);
			}

			tomSprite.setTexture(tom);

			//---->>>Jerry going down
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				jerry.loadFromFile("downJerry.png");
				jerrySprite.setPosition(position_x + 30, position_y + 25);

			}
			//---->>>Jerry - Bird clash
			else if (position_x >= birdPosition_x && position_x <= birdPosition_x + 10) {
				life--;
				lifeState = 1;
				tomPosition_x += 10;
			}
			window.clear();
			window.draw(backgroundSprite);
			window.draw(backgroundSprite1);



			if (random == 33 || coinState1 == 1) {
				window.draw(coinSprite1);
				coinState1 = 1;
			}
			if (random == 33 || coinState2 == 1) {
				window.draw(coinSprite2);
				coinState2 = 1;
			}
			if (random == 33 || coinState3 == 1) { // && level < level1) {
				window.draw(coinSprite3);
				coinState3 = 1;
			}
			if ((random == 13 || heartState == 1) && life < 3) { // && life < 3 && level < level1) {
				window.draw(heartSprite);
				heartState = 1;
			}

			//---->>>>Avoid box & stone from Block
			if (!(stonePosition_x >= block2Position_x - 100 && stonePosition_x <= (block2Position_x + 200)) && !(boxPosition_x >= block2Position_x - 100 && boxPosition_x <= block2Position_x + 200)) {

				if ((random == 13 || blockState1 == 1)) { // && level < level1) {
					window.draw(blockSprite2);
					blockState1 = 1;
				}
			}
			//window.draw(blockSprite1);
			if (!(position_x >= stonePosition_x && position_x <= (stonePosition_x + 25) && jumpState == 0) && !(position_x >= birdPosition_x && position_x <= (birdPosition_x + 10) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))) && !(position_x >= boxPosition_x && position_x <= (boxPosition_x + 25) && jumpState == 0)) {
				window.draw(jerrySprite);
			}
			if ((random == 10 || sotneState1 == 1)) {
				window.draw(stoneSprite1);
				sotneState1 = 1;
			}
			if (((blockState1 == 0 && sotneState1 == 0 && boxState == 0) && random == 23) || birdState == 1) {
				window.draw(birdSprite);
				birdState = 1;
			}
			if (!(stonePosition_x >= boxPosition_x - 300 && stonePosition_x <= (boxPosition_x + 300))) {

				if ((random == 17 || boxState == 1)) {
					window.draw(boxSprite);
					boxState = 1;
				}
			}

			window.draw(tomSprite);
			window.draw(pointText);
			window.draw(lifeText);
			window.draw(fireText);
			window.draw(pauseSprite);
			window.draw(resumeSprite);
			window.draw(go_to_menuSprite);
			window.display();
			clock.restart();
		}

		if (gameState == 0 && gameOverClock.getElapsedTime() > gameOverTime) {
			window.clear();
			gameOver();
			return;

		}
	}
}
