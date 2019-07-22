#pragma once
/**********************************************************************************
// Sword (Código Fonte)
//
// Criação:		20 Jan 2013
// Atualização: 06 Jun 2019
// Compilador:	Visual C++ 2019
//
// Descrição:	Animação de uma explosão
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
		if (enemyKnight->animGet != 1) {
			enemyKnight->reviceAttack(30 * (1 + (float(knight->swordItems) / 5)));
			hit = true;
		}
		else if (enemyKnight->side == knight->side) {
			if ((enemyKnight->x > x && knight->side == true) || (enemyKnight->x < x && knight->side == false)) {
				hit = true;
				enemyKnight->reviceAttack(60 * (1 + (float(knight->swordItems) / 5)));
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
		}
	}
	if (knight->animGet != 3) {
		knight->scene->Delete();
	}
}



// ---------------------------------------------------------------------------------