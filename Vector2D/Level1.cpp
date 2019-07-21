#include "Level1.h"
#include "Level2.h"
#include "TSOTD.h"
#include "Home.h"	
#include "Wall.h"
#include "Engine.h"
#include "Shield.h"

// -----------------------------------------------------------------------------

Scene* Level1::scene = nullptr;


// -----------------------------------------------------------------------------

void Level1::Init()
{
	scene = new Scene();

	//backg = new Sprite("Resources/background.png");
	keyCtrl = false;
	this->knight = TSOTD::knight;
	this->knight->scene = scene;
	scene->Add(knight, MOVING);
	knight->MoveTo(window->CenterX() - 300, window->CenterY());
	for (int i = 0; i < 2000; i += 50) {
		scene->Add(new Wall(10, 10, i, 200), STATIC);
	}

	Wall* floor1 = new Wall(600, 50, 300, 450);
	scene->Add(floor1, STATIC);
	EnemyKnight* enemyKnight = new EnemyKnight(knight, floor1,scene, 0.100f, 1);
	scene->Add(enemyKnight, MOVING);


	Wall* floor2 = new Wall(600, 50, 1150, 450);
	scene->Add(floor2, STATIC);
	EnemyKnight* enemyKnight2 = new EnemyKnight(knight, floor2, scene, 0.100f, 1);
	scene->Add(enemyKnight2, MOVING);

	scene->Add(new Shield(320, 500), STATIC);
	scene->Add(new Wall(1400, 50, 500, 700), STATIC);
	scene->Add(new Wall(50, 2000, -25, 0), STATIC);
	//scene->Add(new Wall(1000, 50, 500, 700), STATIC);
	scene->Add(new Wall(100, 50, 650, 600), STATIC);
	scene->Add(new Wall(50, 50, 500, 650), STATIC);
	scene->Add(new Wall(50, 50, 500, 650), STATIC);
	//knight->MoveTo(500, 0);

}

// ------------------------------------------------------------------------------

void Level1::Update()
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
	if (ctrlKeyB && window->KeyDown('M'))
	{
		ctrlKeyB = false;
		TSOTD::NextLevel<Level2>();
	}
}

// ------------------------------------------------------------------------------

void Level1::Draw()
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

void Level1::Finalize()
{
	delete backg;
	scene->Remove(knight, MOVING);
	//knight = nullptr;
	delete scene;
}