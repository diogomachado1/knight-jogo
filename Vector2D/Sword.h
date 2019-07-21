#pragma once
#ifndef _SWORD_H_
#define _SWORD_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"						// tipos específicos da engine
#include "Object.h"						// interface de Object
#include "Animation.h"					// animação de sprites
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
	void OnCollision(Object* obj);					// atualização do objeto
	void Draw();
	void Update();
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Sword::Draw()
{
	//anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif