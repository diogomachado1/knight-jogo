/**********************************************************************************
// Wall (Código Fonte)
//
// Criação:		20 Jan 2013
// Atualização: 06 Jun 2019
// Compilador:	Visual C++ 2019
//
// Descrição:	Animação de uma explosão
//
**********************************************************************************/

#include "Wall.h"
#include "Level1.h"

// ---------------------------------------------------------------------------------


Wall::Wall(float sizeX,float sizeY, float posX, float posY)
{
	if (sizeX <= 51) {
		if(sizeY<250)
		 sprite = new Sprite("Resources/wallY200.png");
		else if (sizeY < 550)
		 sprite = new Sprite("Resources/wallY500.png");
		else
		 sprite = new Sprite("Resources/wallY1500.png");
	}
	else {
		if (sizeX < 250)
			sprite = new Sprite("Resources/wallX200.png");
		else if (sizeX < 550)
			sprite = new Sprite("Resources/wallX500.png");
		else
			sprite = new Sprite("Resources/wallX1500.png");
	}
	width = sizeX;
	height = sizeY;
	bbox = new Rect(-sizeX/2.0f, -sizeY / 2.0f, sizeX / 2.0f, sizeY / 2.0f);
	type = WALL;
	MoveTo(posX, posY);
}


// ---------------------------------------------------------------------------------

Wall::~Wall()
{
	//delete anim;
}

// ---------------------------------------------------------------------------------

void Wall::OnCollision(Object* obj)
{
	if (obj->Type() == PLAYER) {
		float borderX = width / 2;
		float borderY = height / 2;
		Knight* player = (Knight*)obj;
		if (X() > player->X() && Y() < player->Y()) { //inferior esquerdo
			if ((X() - borderX+10) > (player->X() + player->width / 2)) {
				player->MoveTo((X() - borderX) - player->width/2, player->y);//inferior
			}
			else {
				player->MoveTo(player->x, (y + borderY) + player->height / 2);//esquerdo
				player->jumpTime = 0;
			}
		}
		if (X() > player->X() && Y() > player->Y()) { //superior esquerdo
			if ((X() - borderX+10) > (player->X() + player->width / 2)) {
				player->MoveTo((X() - borderX) - player->width / 2, player->y);//superior
			}
			else {
				player->MoveTo(player->x, (y - borderY) - player->height / 2);//esquerdo
				player->jumpTime = 0;
				player->jumpController = false;
			}
		}
		if (X() <= player->X() && Y() < player->Y()) { //inferior direito
			if ((X() + borderX-10) < (player->X() - player->width / 2)) {
				player->MoveTo((X() + borderX) + player->width / 2, player->y);//inferior
			}
			else {
				player->MoveTo(player->x, (y + borderY) + player->height / 2);//direito
				player->jumpTime = 0;
			}
		}
		if (X() <= player->X() && Y() > player->Y()) {//superior  direito
			if ((X() + borderX-10) < (player->X() - player->width/2)) {
				player->MoveTo((X() + borderX) + player->width / 2, player->y);//direto
			}
			else {
				player->MoveTo(player->x, (y - borderY) - player->height / 2);//superior
				player->jumpTime = 0;
				player->jumpController = false;
			}
		}
	}

	if (obj->Type() == ENEMY) {
		float borderX = width / 2;
		float borderY = height / 2;
		EnemyKnight* player = (EnemyKnight*)obj;
		if (X() > player->X() && Y() < player->Y()) { //inferior esquerdo
			if ((X() - borderX + 10) > (player->X() + player->width / 2)) {
				player->MoveTo((X() - borderX) - player->width / 2, player->y);
			}
			else {
				player->MoveTo(player->x, (y + borderY) + player->height / 2);
				player->gravity = 0;
			}
		}
		if (X() > player->X() && Y() > player->Y()) { //superior esquerdo
			if ((X() - borderX + 10) > (player->X() + player->width / 2)) {
				player->MoveTo((X() - borderX) - player->width / 2, player->y);
			}
			else {
				player->MoveTo(player->x, (y - borderY) - player->height / 2);
				player->gravity = 0;
				//player->jumpController = false;
			}
		}
		if (X() <= player->X() && Y() < player->Y()) { //inferior direito
			if ((X() + borderX - 10) < (player->X() - player->width / 2)) {
				player->MoveTo((X() + borderX) + player->width / 2, player->y);
			}
			else {
				player->MoveTo(player->x, (y + borderY) + player->height / 2);
				player->gravity = 0;
			}
		}
		if (X() <= player->X() && Y() > player->Y()) {//superior  direito
			if ((X() + borderX - 10) < (player->X() - player->width / 2)) {
				player->MoveTo((X() + borderX) + player->width / 2, player->y);
			}
			else {
				player->MoveTo(player->x, (y - borderY) - player->height / 2);
				player->gravity = 0;
				//player->jumpController = false;
			}
		}
	}

}

void Wall::Update()
{
}

// ---------------------------------------------------------------------------------