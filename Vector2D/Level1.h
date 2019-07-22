#ifndef _LEVEL3_H_
#define _LEVEL3_H_

#include "Game.h"
#include "Scene.h"
#include "Sprite.h"
#include "TileSet.h"
#include "Knight.h"
#include "EnemyKnight.h"
#include "Door.h"
#include "TSOTD.h"



class Level1 : public Game
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
	Sprite* gameOver = new Sprite("Resources/game over.png");
	int death = 0;

public:
	static Scene* scene;			// gerenciador de cena
	Door* door;
	void Init();					// inicializa jogo
	void Update();					// atualiza l�gica do jogo
	void Draw();					// desenha jogo
	void Finalize();				// finaliza jogo
};

// ---------------------------------------------------------------------------------

#endif
