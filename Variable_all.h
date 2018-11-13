#define screen_hight  640
#define screen_width  1024
#define highScoreNamePosition_x 370
#define highScorePointPosition_x 520
#define highScoreElementPosition_y 200
#define highScoreElementDestance_y -40
#define highScoreSerialPosition_x 340
#define replacement(variable_name , replaced_position)  variable_name = replaced_position
#define MenuFile  fscanf(file_menu, "%s" , menu_image_Ara)
#define MenuFile2  fscanf(file_menu, "%s %d %d" , menu_image_Ara, & menuReceiver[0], &menuReceiver[1])

int flag = 1;
int receiverFromFile;
int menuReceiver[2];
int position_x = 10, position_y = 415;//it's jerry's position
int jumpPosition_y;
int jumpPosition_x = 0;
int coin1Position_x = 1024, coin2Position_x = (1024 + 40), coin3Position_x = (1024 + 80), coinPosition_y = 435;
int heartPosition_x = 1025, heartPosition_y = 415 - 60;
int backgroundPosition1_x = 0, backgroundPosition_y = 0; 
int welcomePageState = 0;
int birdPosition_x = 1040, birdPosition_y = 370;
int fireballPosition_x = position_x, fireballPosition_y = 373;
int fireballState = 0;
int fire_count = 40;
int stonePosition_x = screen_width + 50, stonePosition_y = 430;
int boxPosition_x = screen_width + 50, boxPosition_y;
int tomPosition_x = -120, tomPosition_y = 380;
int backgroundPosition2_x = 1023;
int levelCount = 0;
int level1Count;
int level2Count;
int coinState1 = 0, coinState2 = 0, coinState3 = 0;
int sotneState1 = 0;
int boxState = 0;
int heartState = 0;
int lifeState = 0;
int downJerryState = 0;
int point = 0;
int intPoint;
int life = 1;
int gameState = 1;
int blockPosition_x = 1027, blockPosition_y = 478;
int block2Position_x;
int blockState1 = 0;
int jumpState = 0;
int birdState = 0;
char pointAra[100], lifeAra[100], fireSymbolAra[100];
int jerryIndex = 0;
int tomIndex = 0;
int birdIndex = 0;
int levelState = 0;
char jerryAra[][100] = { "1.png", "1.png", "2.png", "2.png", "3.png", "3.png", "4.png", "4.png", "3.png", "3.png" };
char tomAra[][100] = { "tom1.png", "tom1.png", "tom2.png", "tom2.png", "tom3.png", "tom3.png", "tom4.png", "tom4.png", "tom5.png", "tom5.png", "tom6.png", "tom6.png", "tom7.png", "tom7.png" };
char birdAra[][100] = { "bird1.png", "bird1.png", "bird2.png", "bird2.png", "bird3.png", "bird3.png" };
int x = 0;//Jer Sprite Num
int y = 0;//Tom Sprite Num
int z = 0;//Tiger Sprite Num
int v = 0;//Fire Sprite Num

int variable()
{
	flag = 1;
	receiverFromFile;
	position_x = 10, position_y = 415;//it's jerry's position
	jumpPosition_y;
	gameState = 1;
	jumpPosition_x = 0;
	coin1Position_x = 1024, coin2Position_x = (1024 + 40), coin3Position_x = (1024 + 80), coinPosition_y = 435;
	heartPosition_x = 1025, heartPosition_y = 415 - 60;
	//int heart2Position_x;
	backgroundPosition1_x = 0, backgroundPosition_y = 0;
	welcomePageState = 0;
	//getHighscores();


	birdPosition_x = 1040, birdPosition_y = 370;
	stonePosition_x = screen_width + 50, stonePosition_y = 430;
	boxPosition_x = screen_width + 120, boxPosition_y = 419+20;
	tomPosition_x = -120, tomPosition_y = 380;
	backgroundPosition2_x = 1023;
	levelCount = 0;
	level1Count = 4;
	level2Count = level1Count;
	coinState1 = 0, coinState2 = 0, coinState3 = 0;
	sotneState1 = 0;
	boxState = 0;
	heartState = 0;
	downJerryState = 0;
	intPoint;
	gameState = 1;
	blockPosition_x = 1027, blockPosition_y = 478;
	block2Position_x;
	blockState1 = 0;
	jumpState = 0;
	lifeState = 0;
	birdState = 0; jerryIndex = 0;
	tomIndex = 0;
	birdIndex = 0;
	levelState = 0;
	x = 0;//Jer Sprite Num
	y = 0;//Tom Sprite Num
	z = 0;//Tiger Sprite Num
	v = 0;//Fire Sprite Num
	return 0;
}