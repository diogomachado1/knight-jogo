#pragma once
/**********************************************************************************
// EnemySword (Código Fonte)
//
// Criação:		20 Jan 2013
// Atualização: 06 Jun 2019
// Compilador:	Visual C++ 2019
//
// Descrição:	Animação de uma explosão
//
**********************************************************************************/

#include "EnemySword.h"
#include "level1.h"

// ---------------------------------------------------------------------------------


EnemySword::EnemySword(EnemyKnight* knightIn, float sizeX, float sizeY)
{
	knight = knightIn;
	width = sizeX;
	height = sizeY;
	bbox = new Rect(-sizeX / 2.0f, -sizeY / 2.0f, sizeX / 2.0f, sizeY / 2.0f);
	type = SWORD;
}


// ---------------------------------------------------------------------------------

EnemySword::~EnemySword()
{
	knight->swordOpen = false;
}

// ---------------------------------------------------------------------------------

void EnemySword::OnCollision(Object* obj)
{

	if (obj->Type() == PLAYER && hit == false)
	{
		Knight* enemyKnight = (Knight*)obj;
		if (enemyKnight->animGet != 1) {
			enemyKnight->reviceAttack(30);
			hit = true;
		}
		else if (enemyKnight->side == knight->side) {
			if ((enemyKnight->x > x && knight->side == true) || (enemyKnight->x < x && knight->side == false)) {
				hit = true;
				enemyKnight->reviceAttack(60);
			}
		}
	}
}

void EnemySword::Update()
{
	if (knight->side == true) {
		MoveTo(knight->x + (knight->width / 2 + width / 2), knight->y - 12);
	}
	else {
		MoveTo(knight->x - (knight->width / 2 + width / 2), knight->y - 12);
	}
	if (knight->animGet == 3) {
		if (knight->anim->Frame() == 8) {
			Level1::scene->Delete();
		}
	}
	if (knight->animGet != 3) {
		Level1::scene->Delete();
	}
}



// ---------------------------------------------------------------------------------