/**********************************************************************************
// BossPower (Arquivo de Cabe�alho)
//
// Cria��o:		21 Abr 2012
// Atualiza��o:	04 Jul 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Plataformas do jogo
//
**********************************************************************************/

#ifndef _BOSSPOWER_H_
#define _BOSSPOWER_H_

// ---------------------------------------------------------------------------------

#include "Types.h"										// tipos espec�ficos da engine
#include "Object.h"										// interface de Object
#include "Sprite.h"										// desenho de sprites
#include "Scene.h"
// ---------------------------------------------------------------------------------


// ---------------------------------------------------------------------------------

class BossPower : public Object
{
private:
	Sprite* swordItem;									// sprite da plataforma

public:
	BossPower(float posX, float posY);	// construtor	
	~BossPower();
	// destrutor
	bool hit=false;
	void OnCollision(Object* obj);
	void Update();										// atualiza��o do objeto
	void Draw();										// desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void BossPower::Draw()
{
	swordItem->Draw(x, y, z, 1,180);
}

// ---------------------------------------------------------------------------------

#endif