#ifndef _ENEMYKNIGHT_H_
#define _ENEMYKNIGHT_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"						// tipos específicos da engine
#include "Object.h"						// interface de Object
#include "Animation.h"					// animação de sprites
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
	EnemyKnight(Knight* knightIn, Wall * wall, Scene* scene,int hard);
	// construtor
	~EnemyKnight();						// destrutor
	
	Animation* anim;					
	Animation* animListRight[10];
	Animation* animListLeft[10];
	Knight* knight;
	float hard;
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
	void Update();						// atualização do objeto
	void Draw();						// desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void EnemyKnight::Draw()
{
	Color* cor;
	if (hard == 1) {
		cor = &Color(0.0f, 0.5f, 0.0f, 1.0f);
	}
	else if (hard == 2){
		cor = &Color(0.0f, 0.0f, 0.5f, 1.0f);
	}
	else {
		cor = &Color(0.5f, 0.0f, 0.0f, 1.0f);
	}
	stringstream text;
	text.str("");
	text << int(life);
	anim->Draw(x, y, z, 1.0f, 0.0f, *cor);
	verdana->Draw(x, y-50, text.str(), Color(1.0f, 1.0f, 1.0f, 1.0f));
}

// ---------------------------------------------------------------------------------

#endif