#ifndef _WALL_H_
#define _WALL_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"						// tipos espec�ficos da engine
#include "Object.h"						// interface de Object
#include "Animation.h"					// anima��o de sprites

// ---------------------------------------------------------------------------------

class Wall : public Object
{
private:
	//Sprite* platform;
public:
	Wall(float sizeX, float sizeY, float posX, float posY);
	// construtor
	~Wall();						// destrutor

	float width;
	float height;
	void OnCollision(Object* obj);					// atualiza��o do objeto
	void Draw();
	void Update();	
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void Wall::Draw()
{
	//anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif