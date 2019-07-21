/**********************************************************************************
// Knight (C�digo Fonte)
//
// Cria��o:		20 Jan 2013
// Atualiza��o: 06 Jun 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Anima��o de uma explos�o
//
**********************************************************************************/

#include "Knight.h"
#include "Level1.h"
#include "EnemyKnight.h"
#include "Wall.h"
#include "Sword.h"
// ---------------------------------------------------------------------------------

Knight::Knight()
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
	MoveTo(200, 700);
	side = true;  //true = direta, false = esquerda
	bbox = new Rect(-width / 2.0f, -height / 2.0f, width / 2.0f, height / 2.0f);
	verdana = new Font("Resources/verdana12.png");
	verdana->Spacing("Resources/verdana12.dat");
	Scale(1.5f);
	width = this->width * scale;
	height = this->height * scale;
	//verdana->Draw(x, y, "Verdana 12", Color(0.0f, 0.0f, 0.0f, 1.0f));
	
}


// ---------------------------------------------------------------------------------

Knight::~Knight()
{
	delete anim;
}

// ---------------------------------------------------------------------------------

void Knight::ChangeTile(TileSet* tiles, bool loop)
{
	anim = new Animation(tiles, 0.060f, loop);
}


void Knight::OnCollision(Object* obj)
{

	//if (obj->Type() == ENEMY)
	//{
	//	EnemyKnight* enemyKnight = (EnemyKnight*)obj;
	//	enemyKnight->Stop();
	//	if (attackButtonPress && animGet == 3)
	//		if ((anim->Frame() == 6 && enemyKnight->animGet != 4)) //Se a espada estiver no completamente pra frente e o 
	//			if (enemyKnight->animGet != 1) {
	//				enemyKnight->SetAnimation(4, enemyKnight->side);
	//				kill++;
	//			}
	//			else if (enemyKnight->side == side) {
	//				if ((enemyKnight->x > x && side == true) || (enemyKnight->x < x && side == false)) {
	//					enemyKnight->SetAnimation(4, enemyKnight->side);
	//					kill++;
	//				}
	//			}
	//}
	if (obj->Type() == WALL) {
		/*Wall* wall = (Wall*)obj;
		float bordLeft = (wall->X() - wall->width / 2.0f);
		float bordRight = (wall->X() + wall->width / 2.0f);
		float bordTop = (wall->Y() - wall->height / 2.0f);
		float bordBottom = (wall->Y() + wall->height / 2.0f);
		float knightBorderRight = x + 25;
		float knightBorderLeft = x - 25;
		float knightBorderTop = y - 47;
		float knightBorderBottom = y + 47;
		if (knightBorderRight> bordLeft && knightBorderRight < bordLeft + 10) {
			MoveTo(bordLeft - 25, y);
		}
		if (knightBorderLeft< bordRight && knightBorderLeft > bordRight-10) {
			MoveTo(bordRight + 25, y);
		}
		if (knightBorderBottom> bordTop && knightBorderBottom < bordTop + 10) {			
			MoveTo(x, bordTop - 47);
			if (jumpTime <= 0) {
				jumpController = false;
			}
		}
		if (knightBorderTop < bordBottom && knightBorderTop > bordBottom - 30) {
			MoveTo(x, bordBottom + 47);
		}*/
	}
}

void Knight::moving(int x, int y, bool sideCurrent) {
	SetAnimation(2, sideCurrent);
	Translate(x * gameTime, y * gameTime);
}



void Knight::SetAnimation(int animationNumber, bool sideCurrent) {
	if (animGet != animationNumber || sideCurrent != side) {
		anim->Frame(0);
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
void Knight::jump()
{
	jumpTime = -400;

}

void Knight::reviceAttack(float value) {
	this->life -= value;
	if (life <= 0) {
		SetAnimation(4, side);
	}
}

void Knight::Draw()
{
	stringstream text;
	text.str("");
	text << int(life);
	anim->Draw(x, y, z, scale);
	verdana->Draw(x, y - 50, text.str(), Color(1.0f, 1.0f, 1.0f, 1.0f));
}

void Knight::Update()
{


	if (animGet == 3 && anim->Frame() == 4 && swordOpen == false) {
		Level1::scene->Add(new Sword(this, 35, 40), MOVING);
		swordOpen = true;
	}

	jumpTime = jumpTime + (500 * gameTime);
	Translate(0, jumpTime*gameTime);
	if (animGet == 4) {
		SetAnimation(4, side);
	}
	else {
		if (window->KeyDown(VK_SPACE))
		{
			SetAnimation(1, side);
			attackButtonPress = false;
		}

		if (window->KeyUp(VK_SPACE)) {
			if (animGet == 1) {
				SetAnimation(0, side);
			}
		}

		if (!attackButtonPress && window->KeyDown(0x47))
		{
			SetAnimation(3, side);
			anim->Frame(1);
			// Attack();
			attackButtonPress = true;
		}
		if (attackButtonPress && (anim->Frame() > 1 || window->KeyUp(0x47)))
		{
			SetAnimation(3, side);
			if (anim->Frame() == 9) {
				attackButtonPress = false;
				SetAnimation(0, side);
			}

		}
		if (animGet != 1 && animGet != 3) {
			if (window->KeyDown(0x44))
			{
				
					moving(200, 0, true);
				
			}
			if (window->KeyDown(0x41) )
			{
				
					moving(-200, 0, false);
			}
			if (window->KeyDown(0x57) && jumpController == false)
			{
				jumpController = true;	
				Translate(0, -5);
				jump();
			}
			/*if (jumpController) {
				if (jumpTime > 0) {
					anim->NextFrame();
					moving(0, -500, side);
					jumpTime = jumpTime - gameTime;

				}
				else {

				}
			}*/
			if (window->KeyDown(0x53))
			{
				
					moving(0, 200, side);
				
			}
			if (window->KeyUp(0x44) && window->KeyUp(0x41) && window->KeyUp(0x57) && window->KeyUp(0x53)) {
				SetAnimation(0, side);
			}
		}
	}
	//anim->NextFrame();
}

// ---------------------------------------------------------------------------------