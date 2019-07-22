#ifndef _DOOR_H_
#define _DOOR_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"						// tipos espec�ficos da engine
#include "Object.h"						// interface de Object
#include "Animation.h"					// anima��o de sprites
#include "Sprite.h"
#include "Knight.h"
// ---------------------------------------------------------------------------------

class Door : public Object
{
private:
	//Sprite* platform;
	Sprite* sprite;
	Sprite* door;
	Sprite* wall;
public:
	Door(float posX, float posY, int level, int nextlevel, Knight* knight);
	// construtor
	~Door();						// destrutor
	float width;
	float height;
	float rotation;
	int nextLevel;
	Knight* knight;
	int currentLevel;
	int newLevel;
	void OnCollision(Object* obj);					// atualiza��o do objeto
	void Draw();
	void Update();
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void Door::Draw()
{
	sprite->Draw(x, y, z, 1,rotation);
}

// ---------------------------------------------------------------------------------

#endif