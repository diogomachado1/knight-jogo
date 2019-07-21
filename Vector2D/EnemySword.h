#pragma once
#ifndef _ENEMYSWORD_H_
#define _ENEMYSWORD_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"						// tipos específicos da engine
#include "Object.h"						// interface de Object
#include "Animation.h"					// animação de sprites
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
	void OnCollision(Object* obj);					// atualização do objeto
	void Draw();
	void Update();
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void EnemySword::Draw()
{
	//anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif