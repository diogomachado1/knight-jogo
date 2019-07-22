#include "Level2.h"
#include "Level2.h"
#include "TSOTD.h"
#include "Home.h"	
#include "Wall.h"
#include "Engine.h"

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
	int enemy, hard;

	ifstream fin;

	fin.open("Resources/Level2.txt");
	fin >> sizeX;
	while (!fin.eof())
	{
		if (fin.good())
		{
			// lê linha com informações da plataforma
			fin >> sizeY; fin >> posX; fin >> posY; fin >> enemy; fin >> hard;
			wall = new Wall(sizeX, sizeY, posX, posY);
			scene->Add(wall, STATIC);
			if (enemy == 1) {
				EnemyKnight* enemyKnight = new EnemyKnight(knight, wall, scene, hard);
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

}

// ------------------------------------------------------------------------------

void Level2::Draw()
{
	//backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
	scene->Draw();
	counter->Draw(float(window->CenterX()), 50, Layer::BACK);
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