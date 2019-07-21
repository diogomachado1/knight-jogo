

#ifndef _HOME_H_
#define _HOME_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Sprite.h"
#include "Knight.h"

// ------------------------------------------------------------------------------

class Home : public Game
{
private:
	Sprite* backg = nullptr;		// background
	bool ctrlKeyESC = false;		// controla o pressionamento do ESC

public:
	Knight* knight;
	void Init();
	void Init(Knight* Knight);					// inicializa jogo
	void Update();					// atualiza l�gica do jogo
	void Draw();					// desenha jogo
	void Finalize();				// finaliza jogo
};

// -----------------------------------------------------------------------------

#endif