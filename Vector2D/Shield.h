/**********************************************************************************
// Shield (Arquivo de Cabe�alho)
//
// Cria��o:		21 Abr 2012
// Atualiza��o:	04 Jul 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Plataformas do jogo
//
**********************************************************************************/

#ifndef _SHIELD_H_
#define _SHIELD_H_

// ---------------------------------------------------------------------------------

#include "Types.h"										// tipos espec�ficos da engine
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
	void Update();										// atualiza��o do objeto
	void Draw();										// desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void Shield::Draw()
{
	shield->Draw(x, y, z,0.3);
}

// ---------------------------------------------------------------------------------

#endif