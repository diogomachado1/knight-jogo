#ifndef _WALL_H_
#define _WALL_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"						// tipos específicos da engine
#include "Object.h"						// interface de Object
#include "Animation.h"					// animação de sprites
#include "Sprite.h"
// ---------------------------------------------------------------------------------

class Wall : public Object
{
private:
	//Sprite* platform;
	Sprite* sprite;
public:
	Wall(float sizeX, float sizeY, float posX, float posY);
	// construtor
	~Wall();						// destrutor
	float width;
	float height;
	void OnCollision(Object* obj);					// atualização do objeto
	void Draw();
	void Update();	
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Wall::Draw()
{
	sprite->Draw(x, y, z, 1);
}

// ---------------------------------------------------------------------------------

#endif