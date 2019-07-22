/**********************************************************************************
// Knight (Arquivo de Cabeçalho)
//
// Criação:		20 Jan 2013
// Atualização: 06 Jun 2019
// Compilador:	Visual C++ 2019
//
// Descrição:	Animação de uma explosão
//
**********************************************************************************/

#ifndef _KNIGHT_H_
#define _KNIGHT_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"						// tipos específicos da engine
#include "Object.h"						// interface de Object
#include "Animation.h"					// animação de sprites
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
	Animation * anim;					// animação de explosão
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
	void Update();						// atualização do objeto
	void Draw();						// desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline



// ---------------------------------------------------------------------------------

#endif