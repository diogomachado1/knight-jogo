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
	EnemyKnight(Knight* knightIn, Wall * wall, Scene* scene,int hard, int key);
	// construtor
	~EnemyKnight();						// destrutor
	
	Animation* anim;					
	Animation* animListRight[10];
	Animation* animListLeft[10];
	Knight* knight;
	float hard;
	int key = 0;
	bool attackButtonPress;
	bool stop;
	float count;
	
	float powerCooldown=0;
	float powerStageCooldown=0;
	int stage=1;
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
	int reviceAttack(float value);
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
	if (hard == 4) {
		anim->Draw(x, y, z, 2.0f, scale, *cor);
	}
	else {
		anim->Draw(x, y, z, 1.0f, 1.0, *cor);
	}
	stringstream text;
	text.str("");
	text << int(life);
	verdana->Draw(x, y-50, text.str(), Color(1.0f, 1.0f, 1.0f, 1.0f));
}

// ---------------------------------------------------------------------------------

#endif