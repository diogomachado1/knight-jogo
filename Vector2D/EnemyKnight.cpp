/**********************************************************************************
// Knight (Código Fonte)
//
// Criação:		20 Jan 2013
// Atualização: 06 Jun 2019
// Compilador:	Visual C++ 2019
//
// Descrição:	Animação de uma explosão
//
**********************************************************************************/

#include "Level1.h"
#include "EnemyKnight.h"
#include "EnemySword.h"

// ---------------------------------------------------------------------------------

EnemyKnight::EnemyKnight(Knight* knightIn, Wall* wall, float velAtk, float velMov)
{

	animListRight[0] = new Animation(new TileSet("Resources/newKnight/knightIdleR.png", 100, 100, 4, 4), 0.150f, true);
	animListRight[1] = new Animation(new TileSet("Resources/newKnight/knightBlockR.png", 100, 100, 7, 7), 0.050f, false);
	animListRight[2] = new Animation(new TileSet("Resources/newKnight/knightWalkR.png", 100, 100, 8, 8), 0.090f, false);
	animListRight[3] = new Animation(new TileSet("Resources/newKnight/knightAttackR.png", 100, 100, 10, 10), 0.090f, false);
	animListRight[4] = new Animation(new TileSet("Resources/newKnight/knightDeathR.png", 100, 100, 9, 9), 0.180f, false);

	animListLeft[0] = new Animation(new TileSet("Resources/newKnight/knightIdleL.png", 100, 100, 4, 4), 0.150f, true);
	animListLeft[1] = new Animation(new TileSet("Resources/newKnight/knightBlockL.png", 100, 100, 7, 7), 0.050f, false);
	animListLeft[2] = new Animation(new TileSet("Resources/newKnight/knightWalkL.png", 100, 100, 8, 8), 0.090f, false);
	animListLeft[3] = new Animation(new TileSet("Resources/newKnight/knightAttackL.png", 100, 100, 10, 10), 0.090f, false);
	animListLeft[4] = new Animation(new TileSet("Resources/newKnight/knightDeathL.png", 100, 100, 9, 9), 0.180f, false);
	height = 95;
	width = 35;
	anim = animListRight[0];
	animGet = 0;
	attackButtonPress = false;
	this->wall = wall;
	side = true;  //true = direta, false = esquerda
	bbox = new Rect(-width / 2.0f, -height / 2.0f, width / 2.0f, height / 2.0f);
	gravity = 0;
	interAtck = velMov;
	knight = knightIn;
	type = ENEMY;
	stop = false;
	verdana = new Font("Resources/verdana12.png");
	verdana->Spacing("Resources/verdana12.dat");
	MoveTo(wall->x, wall->y-(wall->height/2 + this->height/2));
}


// ---------------------------------------------------------------------------------

EnemyKnight::~EnemyKnight()
{
	delete anim;
}

// ---------------------------------------------------------------------------------

void EnemyKnight::ChangeTile(TileSet* tiles, bool loop)
{
	anim = new Animation(tiles, 0.060f, loop);
}

void EnemyKnight::Stop()
{
	stop = true;
}


void EnemyKnight::SetAnimation(int animationNumber, bool sideCurrent) {
	if (animGet != animationNumber || sideCurrent != side) {
		side = sideCurrent;
		animGet = animationNumber;
		if (side == true) {
			anim = animListRight[animGet];
		}
		else {
			anim = animListLeft[animGet];
		}
		anim->Restart();
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

void EnemyKnight::OnCollision(Object* obj)
{
	
	// bola colidiu com o player
	//if (obj->Type() == PLAYER)
	//{
	//	Knight* knight = (Knight*)obj;
	//	if (attackButtonPress && animGet == 3)
	//		if (anim->Frame() == 6) //Se a espada estiver no completamente pra frente e o 
	//			if (knight->animGet != 1) {
	//				knight->reviceAttack(10);

	//			} else if(knight->side == side )
 //                   if((knight->x > x && side == true) ||(knight->x < x && side == false))
	//					knight->SetAnimation(4, knight->side);
	//}
}

void EnemyKnight::reviceAttack(float value) {
	this->life -= value;
	if (life <= 0) {
		life = 0;
		SetAnimation(4, side);
	}
}

void EnemyKnight::Update()
{
	if (animGet == 3 && anim->Frame() == 4 && swordOpen == false) {
		Level1::scene->Add(new EnemySword(this, 35, 40), MOVING);
		swordOpen = true;
	}
	targetX = knight->x;
	targetY = knight->y;
	gravity = gravity + (5 * gameTime);
	Translate(0, gravity);
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
		if ((targetX+(knight->width/2)) >(wall->x- (wall->width/2)) && (targetX - (knight->width / 2)) < (wall->x + (wall->width / 2)) && targetY < (y+height/2) && targetY > (y - height / 2)) {
			float delta = abs((targetX - x));
			if (delta >55 && animGet != 3) {
				count = 0;
				SetAnimation(2, sideCurrent);
				Translate((((targetX - x) / delta) * 100) * gameTime, 0);
			}
			else {
				count += gameTime;
				if (count >= interAtck) {
					if (anim->Frame() >= 10) {
						count = 0;
					}
					else {
						SetAnimation(3, sideCurrent);
					}
				}
				else {
					SetAnimation(1, sideCurrent);
				}
			}
		}
		else {
					SetAnimation(0, sideCurrent);
		}
	}

	stop = false;
}

// ---------------------------------------------------------------------------------