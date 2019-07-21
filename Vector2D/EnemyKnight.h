#ifndef _ENEMYKNIGHT_H_
#define _ENEMYKNIGHT_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"						// tipos espec�ficos da engine
#include "Object.h"						// interface de Object
#include "Animation.h"					// anima��o de sprites
#include "Font.h"
#include "Knight.h"
#include "Wall.h"
#include "Scene.h"
#include <sstream>
using std::stringstream;

// ---------------------------------------------------------------------------------

class EnemyKnight : public Object
{
private:
public:
	EnemyKnight(Knight* knightIn, Wall * wall, Scene* scene,float velAtk, float velMov);
	// construtor
	~EnemyKnight();						// destrutor
	
	Animation* anim;					
	Animation* animListRight[10];
	Animation* animListLeft[10];
	Knight* knight;
	float interAtck = 4;
	bool attackButtonPress;
	bool stop;
	float count;
	
	Scene* scene;
	Font* verdana = nullptr;
	bool swordOpen = false;
	float life = 100;
	Wall* wall;
	float width;
	float height;
	float gravity;
	bool side;
	int animGet;
	float targetX;
	float targetY;
	void reviceAttack(float value);
	void ChangeTile(TileSet* tiles, bool loop);
	void Stop();
	void SetAnimation(int animationNumber, bool sideCurrent);
	void OnCollision(Object* obj);
	//void SetAnimation(int animationNumber);
	void Update();						// atualiza��o do objeto
	void Draw();						// desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void EnemyKnight::Draw()
{
	stringstream text;
	text.str("");
	text << int(life);
	anim->Draw(x, y, z); anim->Draw(x, y, z); verdana->Draw(x, y-50, text.str(), Color(1.0f, 1.0f, 1.0f, 1.0f));
}

// ---------------------------------------------------------------------------------

#endif