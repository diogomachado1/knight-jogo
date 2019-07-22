/**********************************************************************************
// Knight (Arquivo de Cabe�alho)
//
// Cria��o:		20 Jan 2013
// Atualiza��o: 06 Jun 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Anima��o de uma explos�o
//
**********************************************************************************/

#ifndef _KNIGHT_H_
#define _KNIGHT_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"						// tipos espec�ficos da engine
#include "Object.h"						// interface de Object
#include "Animation.h"					// anima��o de sprites
#include "Font.h"
#include "Vector.h"
#include "Scene.h"
#include <sstream>
using std::stringstream;
//#include "sword.h"
// ---------------------------------------------------------------------------------



class Knight : public Object
{
private:
public:
	Knight();
	// construtor
	~Knight();						// destrutor
	Animation * anim;					// anima��o de explos�o
	Animation* animListRight[10];
	Animation* animListLeft[10];
	int shields=0;
	int swordItems = 0;
	Scene* scene;
	bool swordOpen;
	bool attackButtonPress;
	Font* verdana = nullptr;
	bool jumpController = false;
	float jumpTime = 0;
	bool side;
	int animGet;
	int kill = 0;
	float life = 100;
	float width;
	float height;
	void reviceAttack(float value);
	void ChangeTile(TileSet* tiles, bool loop);
	void jump();
	void OnCollision(Object* obj);
	void moving(int x, int y, bool sideCurrent);
	void SetAnimation(int animationNumber, bool sideCurrent);
	void Update();						// atualiza��o do objeto
	void Draw();						// desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline



// ---------------------------------------------------------------------------------

#endif