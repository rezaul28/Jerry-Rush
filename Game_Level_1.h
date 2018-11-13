typedef struct stateCondition {
	int state : 1;
	int position_x : 16;
	int position_y : 16;
}state_Level1;

#define imageFile  fscanf(fileImage, "%s" , imageAra)
#define level1VariableFile fscanf(fileImage, "%d", &receiverFromFile)

#define Pause_position_x 10
#define Pause_position_y 50
#define Resume_position_x 100
#define Resume_position_y 50
#define menu_back_position_x 180
#define menu_back_position_y 50
#define text_size 25


void Game_level_1() {
	variable();
	entername();
	srand(time(0));
	srand(time(NULL));
	sf::Clock clock;
	sf::Time time = sf::microseconds(200);

	sf::Clock clock1;
	sf::Time time1 = sf::milliseconds(500);

	sf::Clock gameOverClock;
	sf::Time gameOverTime = sf::milliseconds(1000);

	state_Level1 StrauctPoint, StructLife;

	//---->>>>Loading pictures from image file

	FILE *fileImage;
	fileImage = fopen("JR_imagefile.txt", "r");
	if (fileImage == NULL)
	{
		printf("File can't be opened -----> fp\n");
	}
	char imageAra[1000];

	imageFile;
	background.loadFromFile(imageAra);
	backgroundSprite.setTexture(background);


	background1.loadFromFile(imageAra);
	backgroundSprite1.setTexture(background1);

	imageFile;
	coin.loadFromFile(imageAra);
	coinSprite1.setTexture(coin);
	coinSprite2.setTexture(coin);
	coinSprite3.setTexture(coin);

	imageFile;
	heart.loadFromFile(imageAra);
	heartSprite.setTexture(heart);

	imageFile;
	block1.loadFromFile(imageAra);
	blockSprite1.setTexture(block1);

	imageFile;
	stone1.loadFromFile(imageAra);
	stoneSprite1.setTexture(stone1);

	imageFile;
	box.loadFromFile(imageAra);
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


	imageFile;
	font.loadFromFile(imageAra);

	pointText.setFont(font);
	pointText.setFillColor(sf::Color::Black);
	level1VariableFile;
	StrauctPoint.position_x = receiverFromFile;
	StrauctPoint.position_y = receiverFromFile;
	pointText.setPosition(StrauctPoint.position_x, StrauctPoint.position_y);
	pointText.setCharacterSize(25);

	lifeText.setFont(font);
	lifeText.setFillColor(sf::Color::Black);
	level1VariableFile;
	StructLife.position_x = receiverFromFile;
	level1VariableFile;
	StructLife.position_y = receiverFromFile;
	lifeText.setPosition(StructLife.position_x, StructLife.position_y);
	lifeText.setCharacterSize(25);

	char backState[] = { "b1.png" };


	while (window.isOpen()) {
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			if (evnt.type == evnt.Closed) {
				window.close();
			}

		}
		int random = rand() % 100;
		sf::Vector2i mousePos;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			mousePos = sf::Mouse::getPosition(window);
		}
		if ((mousePos.x >= 10 && mousePos.x <= 85 && mousePos.y >= 50 && mousePos.y <= 122)){
			gameState = 2;
		}
		if ((mousePos.x >= 100 && mousePos.x <= 159 && mousePos.y >= 50 && mousePos.y <= 122)) {
			gameState = 1;
		}
		if ((mousePos.x >= 180 && mousePos.x <= 270 && mousePos.y >= 50 && mousePos.y <= 122)) {
			return;
		}
		if (clock.getElapsedTime() > time && gameState == 1) {

			backgroundSprite1.setPosition(backgroundPosition2_x, 0);
			backgroundSprite.setPosition(backgroundPosition1_x, 0);

			coinSprite1.setPosition(coin1Position_x, coinPosition_y);
			coinSprite2.setPosition(coin2Position_x, coinPosition_y);
			coinSprite3.setPosition(coin3Position_x, coinPosition_y);

			heartSprite.setPosition(heartPosition_x, heartPosition_y);
			blockSprite1.setPosition(blockPosition_x, blockPosition_y);
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
			if (position_x >= heartPosition_x && position_x <= (heartPosition_x + 8) && jumpState == 1) {
				life++;
				tomPosition_x -= 15;
				replacement(heartPosition_x, -50);
			}

			//---->>>>Block replacement
			if (blockPosition_x < -100) {
				replacement(blockPosition_x, screen_width + 10);
				blockState1 = 0;
			}

			if (life < 1) {
				gameState = 0;
				gameOverClock.restart();
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

			levelState = 1;//--->>>After level complete fixed background

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

				birdPosition_x -= 20;
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
				replacement(coin1Position_x, screen_width+10);
				coinState1 = 0;
			}
			if (coin2Position_x < -100) {
				replacement(coin2Position_x, screen_width + 50);
				coinState2 = 0;
			}
			if (coin3Position_x < -100) {
				replacement(coin3Position_x, screen_width + 90);
				coinState3 = 0;
			}
			//--->>>Heart replacement
			if (heartPosition_x < 0) {
				replacement(heartPosition_x, screen_width);
				heartState = 0;
			}

			//--->>>Stone replacement
			if (stonePosition_x < -70) {
				replacement(stonePosition_x, screen_width + 50);
				sotneState1 = 0;
			}

			//--->>>Box replacement
			if (boxPosition_x < -70) {
				replacement(boxPosition_x, screen_width + 50);
				boxState = 0;
			}
			//------>>>>>Animation
			if (position_x > 320 && levelCount < level1Count && flag == 1) {
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

				/*if (tigerState = 1) {
				tigerPosition_x -= 20;
				}*/
				if (coinState1 == 1) {

					coin1Position_x -= 10;
				}
				if (coinState2 == 1) {
					coin2Position_x -= 10;
				}
				if (coinState3 == 1) {
					coin3Position_x -= 10;
				}
				if ((blockState1 == 1)) {
					blockPosition_x -= 10;
				}

				if (backgroundPosition1_x < -1024)
					replacement(backgroundPosition1_x, backgroundPosition2_x + 1023), levelCount++;//---->>>>Level = No of background shift;

				if (backgroundPosition2_x < -1024)
					replacement(backgroundPosition2_x, backgroundPosition1_x + 1023), levelCount++;//---->>>>Level = No of background shift


				if (levelCount >= level1Count) {
					levelState = 1;
				}
			}

			else if (levelState == 1 && flag == 1)
				position_x += 10, tomPosition_x += 10;

			
			sprintf_s(fireSymbolAra, "Fire : %d", fire_count);
			fireText.setString(fireSymbolAra);

			//----->>>>Jerry falling into hole
			if (position_x >= blockPosition_x && position_x <= (blockPosition_x + 100) && jumpState == 0) {
				jerrySprite.setPosition(blockPosition_x + 20, position_y + 90);
				gameState = 0;
				gameOverClock.restart();
			}

			//--->>>>Tom animation
			if ((tomPosition_x >= (stonePosition_x - 100) && tomPosition_x <= (stonePosition_x + 70)) || (tomPosition_x >= (blockPosition_x - 100) && tomPosition_x <= (blockPosition_x + 100)) || (tomPosition_x>=boxPosition_x-50 && tomPosition_x<=boxPosition_x+50)) {

				tom.loadFromFile("tom5.png");
				tomSprite.setPosition(tomPosition_x, tomPosition_y - 40);
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
			if (random == 33 || coinState3 == 1) {

				window.draw(coinSprite3);
				coinState3 = 1;


			}
			if ((random == 17 || heartState == 1) && life<3) {
				window.draw(heartSprite);
				heartState = 1;
			}

			//---->>>>Avoid block & stone 
			if (!(stonePosition_x >= blockPosition_x - 300 && stonePosition_x <= (blockPosition_x + 300)) && !(boxPosition_x >= blockPosition_x - 300 && boxPosition_x <= (blockPosition_x + 300))) {

				if ((random == 13 || random==5 || blockState1 == 1)) {
					window.draw(blockSprite1);
					blockState1 = 1;
				}
			}
			//---->>>>Avoid box & stone 
			


			if (!(position_x >= stonePosition_x && position_x <= (stonePosition_x + 25) && jumpState == 0) && !(position_x >= birdPosition_x && position_x <= (birdPosition_x + 10) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))) && !(position_x >= boxPosition_x && position_x <= (boxPosition_x + 25) && jumpState == 0)) {
				window.draw(jerrySprite);
			}
			

			if ((random == 10 || sotneState1 == 1)) {
				window.draw(stoneSprite1);
				sotneState1 = 1;
			}

			if (!(stonePosition_x >= boxPosition_x - 300 && stonePosition_x <= (boxPosition_x + 300))) {

				if ((random == 17 || boxState == 1)) {
					window.draw(boxSprite);
					boxState = 1;
				}
			}

			if (((blockState1 == 0 && sotneState1 == 0 && boxState == 0) && random == 23) || birdState == 1) {
				window.draw(birdSprite);
				birdState = 1;
			}

			if (position_x > 1015) {

				fclose(fileImage);
				position_x = 155;
				tomPosition_x = 40;
				fireballPosition_x = 155;
				block2Position_x = 1050;
				//Game_level_2();
				finish();
				return;
			}

			window.draw(tomSprite);
			window.draw(pointText);
			window.draw(lifeText);
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
