

#ifndef _HOME_H_
#define _HOME_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Sprite.h"
#include "Knight.h"
#include "Item.h"
#include "Scene.h"
#include "Mouse.h"

enum MenuID { PLAY, EXIT };
// ------------------------------------------------------------------------------

class Home : public Game
{
private:
	Sprite* backg = nullptr;		// background
	Sprite* title = nullptr;
	bool ctrlKeyESC = false;		// controla o pressionamento do ESC
public:
	Scene* scene = nullptr;		// cena do jogo
	Mouse* mouse = nullptr;		// objeto mouse
	static const int MaxItens = 2;
	int fase = 0;
	Item* menu[MaxItens] = { 0 };	// itens do menu
	Animation* anim;
	Knight* knight;
	void Init();				// inicializa jogo
	void Update();					// atualiza lógica do jogo
	void Draw();					// desenha jogo
	void Finalize();				// finaliza jogo
};

// -----------------------------------------------------------------------------

#endif