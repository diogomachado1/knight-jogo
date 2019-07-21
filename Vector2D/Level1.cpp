#include "Level1.h"
#include "Level2.h"
#include "Engine.h"
#include "Home.h"	
#include "Wall.h"

// -----------------------------------------------------------------------------

Scene* Level1::scene = nullptr;


// -----------------------------------------------------------------------------

void Level1::Init(Knight* knight)
{
	scene = new Scene();

	//backg = new Sprite("Resources/background.png");
	keyCtrl = false;
	this->knight = knight;
	scene->Add(knight, MOVING);
	knight->MoveTo(window->CenterX() - 300, window->CenterY());
	for (int i = 0; i < 2000; i += 50) {
		scene->Add(new Wall(10, 10, i, 200), STATIC);
	}

	Wall* floor1 = new Wall(600, 50, 300, 450);
	scene->Add(floor1, STATIC);
	EnemyKnight* enemyKnight = new EnemyKnight(knight, floor1, 0.100f, 1);
	scene->Add(enemyKnight, MOVING);


	Wall* floor2 = new Wall(600, 50, 1150, 450);
	scene->Add(floor2, STATIC);
	EnemyKnight* enemyKnight2 = new EnemyKnight(knight, floor2, 0.100f, 1);
	scene->Add(enemyKnight2, MOVING);

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
	//if ((death < knight->kill)) {
	//	if (knight->kill < 9) {
	//		EnemyKnight* enemyKnight1;
	//		EnemyKnight* enemyKnight2;
	//		EnemyKnight* enemyKnight3;
	//		EnemyKnight* enemyKnight4;
	//		switch (knight->kill)
	//		{
	//		case 1:
	//			///enemyKnight1 = new EnemyKnight(knight, 0.100f, 1);
	//			scene->Add(enemyKnight1, MOVING);
	//			enemyKnight1->MoveTo(window->Width() + 200, 300);
	//			counter->Select(knight->kill);
	//			death = knight->kill;
	//			break;
	//		case 2:
	//			//enemyKnight1 = new EnemyKnight(knight, 0.100f, 1);
	//			scene->Add(enemyKnight1, MOVING);
	//			enemyKnight1->MoveTo(-200, 300);
	//			counter->Select(knight->kill);
	//			death = knight->kill;
	//			break;
	//		case 3:
	//			//enemyKnight1 = new EnemyKnight(knight, 0.100f, 1);
	//			scene->Add(enemyKnight1, MOVING);
	//			enemyKnight1->MoveTo(window->Width() + 200, 300);

	//			//enemyKnight2 = new EnemyKnight(knight, 0.100f, 1);
	//			scene->Add(enemyKnight2, MOVING);
	//			enemyKnight2->MoveTo(-200, 300);
	//			death = knight->kill;
	//			counter->Select(3);
	//			break;
	//		case 5:
	//			counter->Select(knight->kill);
	//			//enemyKnight1 = new EnemyKnight(knight, 0.100f, 1);
	//			scene->Add(enemyKnight1, MOVING);
	//			enemyKnight1->MoveTo(window->Width() + 200, 300);

	//			//enemyKnight2 = new EnemyKnight(knight, 0.100f, 1);
	//			scene->Add(enemyKnight2, MOVING);
	//			enemyKnight2->MoveTo(-200, 300);

	//			//enemyKnight3 = new EnemyKnight(knight, 0.100f, 1);
	//			scene->Add(enemyKnight3, MOVING);
	//			enemyKnight3->MoveTo(window->CenterX(), window->Height() + 550);

	//			//enemyKnight4 = new EnemyKnight(knight, 0.100f, 1);
	//			scene->Add(enemyKnight4, MOVING);
	//			enemyKnight4->MoveTo(window->CenterX(), -550);
	//			death = knight->kill;
	//			counter->Select(4);
	//			break;


	//		}

	//	}
	//	else {
	//		if (death == 5 && knight->kill == 9) {
	//			counter = new Animation(new TileSet("Resources/boss.png", 280, 100, 1, 1), 0.090f, false);
	//			//EnemyKnight* enemyKnight = new EnemyKnight(knight, 0.060f, 0.70f);
	//			//scene->Add(enemyKnight, MOVING);
	//			//enemyKnight->MoveTo(window->Width() + 200, 300);
	//			counter->Select(0);
	//			death = knight->kill;
	//		}
	//		if (knight->kill == 10) {
	//			counter = new Animation(new TileSet("Resources/congratulations.png", 945, 100, 1, 1), 0.090f, false);
	//			death = knight->kill;
	//		}
	//		counter->Select(0);
	//	}
	//}



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
		Engine::Next<Home>(knight);
	}
	if (ctrlKeyB && window->KeyDown('M'))
	{
		ctrlKeyB = false;
		Engine::Next<Level2>(knight);
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
	delete scene;
}