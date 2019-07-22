
/**********************************************************************************
// Door (Código Fonte)
//
// Criação:		20 Jan 2013
// Atualização: 06 Jun 2019
// Compilador:	Visual C++ 2019
//
// Descrição:	Animação de uma explosão
//
**********************************************************************************/

#include "Door.h"
#include "TSOTD.h"
#include "Level2.h"

// ---------------------------------------------------------------------------------


Door::Door(float posX, float posY, int level, int nextLevel, Knight* knight)
{
	currentLevel = level;
	newLevel = level;
	this->nextLevel = nextLevel;
	this->knight = knight;
	if (posX < 700) {
		rotation = 180.0f;
	}
	door = new Sprite("Resources/door.png");
	wall = new Sprite("Resources/wallY200.png");
	sprite = wall;
	width = 50;
	height = 200;
	bbox = new Rect(-width / 2.0f, -height / 2.0f, width / 2.0f, height / 2.0f);
	MoveTo(posX, posY);
}


// ---------------------------------------------------------------------------------

Door::~Door()
{
	//delete anim;
}

// ---------------------------------------------------------------------------------

void Door::OnCollision(Object* obj)
{
	if (obj->Type() == PLAYER) {
		if (knight->keys[nextLevel] == true) {
			newLevel = nextLevel;
		}
		else {
			float borderX = width / 2;
			float borderY = height / 2;
			Knight* player = (Knight*)obj;
			if (X() > player->X() && Y() < player->Y()) { //inferior esquerdo
				if ((X() - borderX + 10) > (player->X() + player->width / 2)) {
					player->MoveTo((X() - borderX) - player->width / 2, player->y);//inferior
				}
				else {
					player->MoveTo(player->x, (y + borderY) + player->height / 2);//esquerdo
					player->jumpTime = 0;
				}
			}
			if (X() > player->X() && Y() > player->Y()) { //superior esquerdo
				if ((X() - borderX + 10) > (player->X() + player->width / 2)) {
					player->MoveTo((X() - borderX) - player->width / 2, player->y);//superior
				}
				else {
					player->MoveTo(player->x, (y - borderY) - player->height / 2);//esquerdo
					player->jumpTime = 0;
					player->jumpController = false;
				}
			}
			if (X() <= player->X() && Y() < player->Y()) { //inferior direito
				if ((X() + borderX - 10) < (player->X() - player->width / 2)) {
					player->MoveTo((X() + borderX) + player->width / 2, player->y);//inferior
				}
				else {
					player->MoveTo(player->x, (y + borderY) + player->height / 2);//direito
					player->jumpTime = 0;
				}
			}
			if (X() <= player->X() && Y() > player->Y()) {//superior  direito
				if ((X() + borderX - 10) < (player->X() - player->width / 2)) {
					player->MoveTo((X() + borderX) + player->width / 2, player->y);//direto
				}
				else {
					player->MoveTo(player->x, (y - borderY) - player->height / 2);//superior
					player->jumpTime = 0;
					player->jumpController = false;
				}
			}
		}
	}

}

void Door::Update()
{
	if (knight->keys[nextLevel]==true) {
		sprite = door;
	}
	else {
		sprite = wall;
	}

}

// ---------------------------------------------------------------------------------