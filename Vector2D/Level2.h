#ifndef _LEVEL2_H_
#define _LEVEL2_H_

#include "Game.h"
#include "Scene.h"
#include "Sprite.h"
#include "TileSet.h"
#include "Knight.h"
#include "EnemyKnight.h"
#include "TSOTD.h"



class Level2 : public Game
{
private:
	Sprite* backg = nullptr;		// sprite de fundo
	bool keyCtrl = false;			// controla pressionamento de teclas
	bool viewBBox = true;
	bool knightDied = false;
	Knight* knight = nullptr;
	//EnemyKnight* enemyKnight = nullptr;
	float timer = 0;
	bool ctrlKeyB = true;
	bool ctrlKeyV = true;
	Animation* counter = new Animation(new TileSet("Resources/counter.png", 70, 100, 5, 5), 0.090f, false);
	Sprite* gameOver = new Sprite("Resources/game over.png");
	int death = 0;

public:
	static Scene* scene;			// gerenciador de cena

	void Init(Knight* knight);					// inicializa jogo
	void Update();					// atualiza lógica do jogo
	void Draw();					// desenha jogo
	void Finalize();				// finaliza jogo
};

// ---------------------------------------------------------------------------------

#endif
