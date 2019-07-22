#ifndef _DOOR_H_
#define _DOOR_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"						// tipos específicos da engine
#include "Object.h"						// interface de Object
#include "Animation.h"					// animação de sprites
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
	void OnCollision(Object* obj);					// atualização do objeto
	void Draw();
	void Update();
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Door::Draw()
{
	sprite->Draw(x, y, z, 1,rotation);
}

// ---------------------------------------------------------------------------------

#endif