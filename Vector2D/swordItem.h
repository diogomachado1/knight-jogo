/**********************************************************************************
// SwordItem (Arquivo de Cabeçalho)
//
// Criação:		21 Abr 2012
// Atualização:	04 Jul 2019
// Compilador:	Visual C++ 2019
//
// Descrição:	Plataformas do jogo
//
**********************************************************************************/

#ifndef _SWORDITEM_H_
#define _SWORDITEM_H_

// ---------------------------------------------------------------------------------

#include "Types.h"										// tipos específicos da engine
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
	void Update();										// atualização do objeto
	void Draw();										// desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void SwordItem::Draw()
{
	swordItem->Draw(x, y, z, 1);
}

// ---------------------------------------------------------------------------------

#endif