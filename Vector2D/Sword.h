#pragma once
#ifndef _SWORD_H_
#define _SWORD_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"						// tipos espec�ficos da engine
#include "Object.h"						// interface de Object
#include "Animation.h"					// anima��o de sprites
#include "Knight.h"

// ---------------------------------------------------------------------------------

class Sword : public Object
{
private:
public:
	Sword(Knight* knightIn,float sizeX, float sizeY);
	// construtor
	~Sword();						// destrutor

	Knight * knight;
	bool hit=false;
	float width;
	float height;
	void OnCollision(Object* obj);					// atualiza��o do objeto
	void Draw();
	void Update();
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void Sword::Draw()
{
	//anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif