/**********************************************************************************
// Shield (Arquivo de Cabeçalho)
//
// Criação:		21 Abr 2012
// Atualização:	04 Jul 2019
// Compilador:	Visual C++ 2019
//
// Descrição:	Plataformas do jogo
//
**********************************************************************************/

#ifndef _SHIELD_H_
#define _SHIELD_H_

// ---------------------------------------------------------------------------------

#include "Types.h"										// tipos específicos da engine
#include "Object.h"										// interface de Object
#include "Sprite.h"										// desenho de sprites
#include "Scene.h"
// ---------------------------------------------------------------------------------


// ---------------------------------------------------------------------------------

class Shield : public Object
{
private:
	Sprite* shield;									// sprite da plataforma

public:
	Shield(float posX, float posY, Scene* scene, int number);	// construtor	
	~Shield();	
	// destrutor
	int number;
	Scene* scene;
	void OnCollision(Object* obj);
	void Update();										// atualização do objeto
	void Draw();										// desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Shield::Draw()
{
	shield->Draw(x, y, z,0.3);
}

// ---------------------------------------------------------------------------------

#endif