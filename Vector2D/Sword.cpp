#pragma once
/**********************************************************************************
// Sword (C�digo Fonte)
//
// Cria��o:		20 Jan 2013
// Atualiza��o: 06 Jun 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Anima��o de uma explos�o
//
**********************************************************************************/

#include "sword.h"
#include "level1.h"

// ---------------------------------------------------------------------------------


Sword::Sword(Knight* knightIn, float sizeX, float sizeY)
{
	knight = knightIn;
	width = sizeX;
	height = sizeY;
	bbox = new Rect(-sizeX / 2.0f, -sizeY / 2.0f, sizeX / 2.0f, sizeY / 2.0f);
	type = SWORD;
}


// ---------------------------------------------------------------------------------

Sword::~Sword()
{
	knight->swordOpen = false;
}

// ---------------------------------------------------------------------------------

void Sword::OnCollision(Object* obj)
{

	if (obj->Type() == ENEMY && hit == false)
	{
		EnemyKnight* enemyKnight = (EnemyKnight*)obj;
		if (enemyKnight->animGet != 4) {
			if (enemyKnight->animGet != 1) {
				hit = true;
				int dead = enemyKnight->reviceAttack(30 * (1 + (float(knight->swordItems) / 5)));

				knight->life += (30 * (1 + (float(knight->swordItems) / 5)) / 3);
				if (knight->life > 100) {
					knight->life = 100;
				}
				if (dead >= 0) {
					knight->kill += enemyKnight->hard * 2;
					knight->keys[dead] = true;
				}
			}
			else if (enemyKnight->side == knight->side) {
				if ((enemyKnight->x > x && knight->side == true) || (enemyKnight->x < x && knight->side == false)) {
					hit = true;
					int dead = enemyKnight->reviceAttack(60 * (1 + (float(knight->swordItems) / 5)));
					knight->life += (30 * (1 + (float(knight->swordItems) / 5)) / 3);
					if (dead >= 0) {
						knight->kill += enemyKnight->hard * 2;
						knight->keys[dead] = true;
					}
				}
			}
			else {
				TSOTD::audio->Play(BLOCK);
			}
		}

	}
}

void Sword::Update()
{
	if (knight->side == true) {
		MoveTo(knight->x + (knight->width / 2 + width / 2), knight->y - 12);
	}
	else {
		MoveTo(knight->x - (knight->width / 2 + width / 2), knight->y - 12);
	}
	if (knight->animGet == 3) {
		if (knight->anim->Frame() == 8) {
			knight->scene->Delete();
			//TSOTD::audio->Play(BLOCK);
		}
	}
	if (knight->animGet != 3) {
		knight->scene->Delete();
	}
}



// ---------------------------------------------------------------------------------