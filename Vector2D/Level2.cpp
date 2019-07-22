#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Level4.h"
#include "TSOTD.h"
#include "Home.h"	
#include "Wall.h"
#include "Engine.h"
#include "Shield.h"
#include "SwordItem.h"
#include "Door.h"

#include "fstream"
using std::ifstream;
// -----------------------------------------------------------------------------

Scene* Level2::scene = nullptr;


// -----------------------------------------------------------------------------

void Level2::Init()
{
	scene = new Scene();
	//window = Engine::window;
	//backg = new Sprite("Resources/background.png");
	keyCtrl = false;
	this->knight = TSOTD::knight;
	this->knight->scene = scene;
	scene->Add(knight, MOVING);
	knight->MoveTo(window->CenterX() - 300, window->CenterY());
	
	scene = new Scene();

	//backg = new Sprite("Resources/background.png");
	keyCtrl = false;
	this->knight = TSOTD::knight;
	this->knight->scene = scene;
	scene->Add(knight, MOVING);
	knight->MoveTo(window->CenterX() - 300, window->CenterY());

	Wall* wall;
	float sizeX, sizeY, posX, posY;
	int enemy, hard, key;

	ifstream fin;

	fin.open("Resources/Level2.txt");
	fin >> sizeX;
	while (!fin.eof())
	{
		if (fin.good())
		{
			// lê linha com informações da plataforma
			fin >> sizeY; fin >> posX; fin >> posY; fin >> enemy; fin >> hard; fin >> key;
			wall = new Wall(sizeX, sizeY, posX, posY);
			scene->Add(wall, STATIC);
			if (enemy == 1) {
				EnemyKnight* enemyKnight = new EnemyKnight(knight, wall, scene, hard,key);
				scene->Add(enemyKnight, MOVING);
			}
		}
		else
		{
			// ignora comentários
			fin.clear();
			char temp[80];
			fin.getline(temp, 80);
		}

		fin >> sizeX;
	}
	fin.close();

	door = new Door(25, 100, 2, 1, knight);
	scene->Add(door, STATIC);
	
	door2 = new Door(1175, 100, 2, 3, knight);
	scene->Add(door2, STATIC);

	door3 = new Door(1175, 700, 2, 4, knight);
	scene->Add(door3, STATIC);

	door4 = new Door(1175, 350, 2, 5, knight);
	scene->Add(door4, STATIC);


	scene->Add(new Shield(1100, 100, scene, 1), STATIC);
	scene->Add(new SwordItem(1100, 650, scene, 1), STATIC);

}

// ------------------------------------------------------------------------------

void Level2::Update()
{
	window->CloseOnEscape();
	scene->Begin();
	scene->Next();


	if (knight->animGet == 4) {
		knightDied = true;
	}

	if (knightDied == true)
		gameOver->Draw(float(window->CenterX()), float(window->CenterY()), Layer::FRONT);


	scene->Update();
	scene->CollisionDetection();
	if (window->KeyUp('B'))
		ctrlKeyB = true;

	if (ctrlKeyB && window->KeyDown('B'))
	{
		ctrlKeyB = false;
		TSOTD::NextLevel<Home>();
	}
	else if (door->newLevel == 1) {
		ctrlKeyB = false;
		TSOTD::NextLevel<Level1>();
	}
	else if (door2->newLevel == 3) {
		ctrlKeyB = false;
		TSOTD::NextLevel<Level3>();
	}
	else if (door3->newLevel == 4) {
		ctrlKeyB = false;
		TSOTD::NextLevel<Level4>();
	}
	else if (door4->newLevel == 5) {
		ctrlKeyB = false;
		TSOTD::NextLevel<Home>();
	}

}

// ------------------------------------------------------------------------------

void Level2::Draw()
{
	//backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
	scene->Draw();
	Engine::renderer->BeginPixels();
	scene->Begin();
	Object* obj = nullptr;
	while (obj = scene->Next())
		if (obj->bbox)
			Engine::renderer->Draw(obj->bbox, 0xffff00ff);
	Engine::renderer->EndPixels();
}

// ------------------------------------------------------------------------------

void Level2::Finalize()
{
	delete backg;
	scene->Remove(knight, MOVING);
	delete scene;
}