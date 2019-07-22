#include "Level4.h"
#include "Level2.h"
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

Scene* Level4::scene = nullptr;


// -----------------------------------------------------------------------------

void Level4::Init()
{
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

	fin.open("Resources/Level4.txt");
	fin >> sizeX;
	while (!fin.eof())
	{
		if (fin.good())
		{
			fin >> sizeY; fin >> posX; fin >> posY; fin >> enemy; fin >> hard; fin >> key;
			wall = new Wall(sizeX, sizeY, posX, posY);
			scene->Add(wall, STATIC);
			if (enemy == 1) {
				EnemyKnight* enemyKnight = new EnemyKnight(knight, wall, scene, hard, key);
				scene->Add(enemyKnight, MOVING);

			}
		}
		else
		{
			fin.clear();
			char temp[80];
			fin.getline(temp, 80);
		}

		fin >> sizeX;
	}
	fin.close();

	door = new Door(25, 100, 4, 2, knight);
	scene->Add(door, STATIC);


	scene->Add(new Shield(1100, 125, scene, 3), STATIC);
	scene->Add(new SwordItem(750, 500, scene, 3), STATIC);
	scene->Add(new Shield(50, 725, scene, 4), STATIC);
	scene->Add(new SwordItem(1100, 725, scene, 4), STATIC);

}

// ------------------------------------------------------------------------------

void Level4::Update()
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
	else if (door->newLevel == 2) {
		ctrlKeyB = false;
		TSOTD::NextLevel<Level2>();
	}


}

// ------------------------------------------------------------------------------

void Level4::Draw()
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

void Level4::Finalize()
{
	delete backg;
	scene->Remove(knight, MOVING);
	//knight = nullptr;
	delete scene;
}