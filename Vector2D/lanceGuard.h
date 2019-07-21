#ifndef _lanceGuard_H_
#define _lanceGuard_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"						// tipos específicos da engine
#include "Object.h"						// interface de Object
#include "Animation.h"					// animação de sprites
#include "Knight.h"

// ---------------------------------------------------------------------------------

class LanceGuard : public Object
{
private:
	Animation* anim;
	Animation* animListRight[10];
	Animation* animListLeft[10];
	Knight* knight;
	bool attackButtonPress;
	bool stop;
	float count;
public:
	LanceGuard(Knight* knightIn);
	// construtor
	~LanceGuard();						// destrutor

	bool side;
	int animGet;
	float targetX;
	float targetY;
	void ChangeTile(TileSet* tiles, bool loop);
	void Stop();
	void SetAnimation(int animationNumber, bool sideCurrent);
	void OnCollision(Object* obj);
	void SetAnimation(int animationNumber);
	void Update();						// atualização do objeto
	void Draw();						// desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void LanceGuard::Draw()
{
	anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif
