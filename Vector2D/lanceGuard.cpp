#include "Level1.h"
#include "lanceGuard.h"

// ---------------------------------------------------------------------------------

LanceGuard::LanceGuard(Knight* knightIn)
{
	animListRight[0] = new Animation(new TileSet("Resources/spearGuard/doppIdleR.png", 210, 210, 4, 4), 0.150f, true);
	animListRight[1] = new Animation(new TileSet("Resources/doppelganger/doppBlockR.png", 210, 210, 7, 7), 0.050f, false);
	animListRight[2] = new Animation(new TileSet("Resources/doppelganger/doppWalkR.png", 210, 210, 8, 8), 0.090f, false);
	animListRight[3] = new Animation(new TileSet("Resources/doppelganger/doppAttackR.png", 400, 400, 10, 10), 0.090f, false);
	animListRight[4] = new Animation(new TileSet("Resources/doppelganger/doppDeathR.png", 210, 210, 9, 9), 0.180f, false);

	animListLeft[0] = new Animation(new TileSet("Resources/doppelganger/doppIdleL.png", 210, 210, 4, 4), 0.150f, true);
	animListLeft[1] = new Animation(new TileSet("Resources/doppelganger/doppBlockL.png", 210, 210, 7, 7), 0.050f, false);
	animListLeft[2] = new Animation(new TileSet("Resources/doppelganger/doppWalkL.png", 210, 210, 8, 8), 0.090f, false);
	animListLeft[3] = new Animation(new TileSet("Resources/doppelganger/doppAttackL.png", 400, 400, 10, 10), 0.090f, false);
	animListLeft[4] = new Animation(new TileSet("Resources/doppelganger/doppDeathL.png", 210, 210, 9, 9), 0.180f, false);

	knight = knightIn;
	anim = animListRight[0];
	animGet = 0;
	attackButtonPress = false;
	side = true;  //true = direta, false = esquerda
	count = 0;
	bbox = new Rect(-25.0f, -100.0f, 100.0f, 25.0f);
	type = ENEMY;
	stop = false;
	MoveTo(300, 300);
}


// ---------------------------------------------------------------------------------

LanceGuard::~LanceGuard()
{
	delete anim;
}

// ---------------------------------------------------------------------------------

void LanceGuard::ChangeTile(TileSet* tiles, bool loop)
{
	anim = new Animation(tiles, 0.060f, loop);
}

void LanceGuard::Stop()
{
	stop = true;
}


void LanceGuard::SetAnimation(int animationNumber, bool sideCurrent) {
	if (animGet != animationNumber || sideCurrent != side) {
		anim->Select(0);
		side = sideCurrent;
		animGet = animationNumber;
		if (side == true) {
			anim = animListRight[animGet];
		}
		else {
			anim = animListLeft[animGet];
		}
	}
	else if (animGet == 1) {
		if (anim->Frame() < 6) {
			anim->NextFrame();
		}
	}
	else {
		anim->NextFrame();
	}
	if (animGet == 4 && anim->Frame() == 8) {
		Level1::scene->Delete();
	}

}

void LanceGuard::OnCollision(Object* obj)
{
	// bola colidiu com o player
	if (obj->Type() == PLAYER)
	{
		Knight* knight = (Knight*)obj;
		if (attackButtonPress)
			if (anim->Frame() == 6 && knight->animGet != 1) //Se a espada estiver no completamente pra frente e o 
				knight->SetAnimation(4, knight->side);
	}
}

void LanceGuard::Update()
{
	targetX = knight->x;
	targetY = knight->y;
	bool sideCurrent;
	if (animGet == 4) {
		SetAnimation(4, side);
	}
	else {
		if (targetX >= x) {
			sideCurrent = true;
		}
		else {
			sideCurrent = false;
		}

		float delta = abs((targetX - x)) + abs((targetY - y));
		if (stop == false && attackButtonPress == false) {
			count = 0;
			SetAnimation(2, sideCurrent);
			Translate((((targetX - x) / delta) * 100) * gameTime, (((targetY - y) / delta) * 100) * gameTime);
		}
		else {
			count += gameTime;
			if (count >= 1) {
				SetAnimation(3, sideCurrent);
				attackButtonPress = true;
				if (anim->Frame() == 9) {
					attackButtonPress = false;
					SetAnimation(0, sideCurrent);
					count = 0;
				}
			}
			else {
				SetAnimation(1, sideCurrent);
			}
		}
	}

	stop = false;
}

// ---------------------------------------------------------------------------------