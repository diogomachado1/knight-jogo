/**********************************************************************************
// SwordItem (Arquivo de Cabe�alho)
//
// Cria��o:		21 Abr 2012
// Atualiza��o:	04 Jul 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Plataformas do jogo
//
**********************************************************************************/

#ifndef _SWORDITEM_H_
#define _SWORDITEM_H_

// ---------------------------------------------------------------------------------

#include "Types.h"										// tipos espec�ficos da engine
#include "Object.h"										// interface de Object
#include "Sprite.h"										// desenho de sprites
#include "Scene.h"
// ---------------------------------------------------------------------------------


// ---------------------------------------------------------------------------------

class SwordItem : public Object
{
private:
	Sprite* swordItem;									// sprite da plataforma

public:
	SwordItem(float posX, float posY, Scene* scene, int number);	// construtor	
	~SwordItem();
	// destrutor
	Scene* scene;
	int number;
	void OnCollision(Object* obj);
	void Update();										// atualiza��o do objeto
	void Draw();										// desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void SwordItem::Draw()
{
	swordItem->Draw(x, y, z, 1);
}

// ---------------------------------------------------------------------------------

#endif