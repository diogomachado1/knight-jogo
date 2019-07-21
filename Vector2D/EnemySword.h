#pragma once
#ifndef _ENEMYSWORD_H_
#define _ENEMYSWORD_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"						// tipos espec�ficos da engine
#include "Object.h"						// interface de Object
#include "Animation.h"					// anima��o de sprites
#include "EnemyKnight.h"

// ---------------------------------------------------------------------------------

class EnemySword : public Object
{
private:
public:
	EnemySword(EnemyKnight* knightIn, float sizeX, float sizeY);
	// construtor
	~EnemySword();						// destrutor

	EnemyKnight* knight;
	bool hit = false;
	float width;
	float height;
	void OnCollision(Object* obj);					// atualiza��o do objeto
	void Draw();
	void Update();
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void EnemySword::Draw()
{
	//anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif