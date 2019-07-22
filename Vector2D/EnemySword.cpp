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
#include "TSOTD.h"

// ---------------------------------------------------------------------------------


EnemySword::EnemySword(EnemyKnight* knightIn, float sizeX, float sizeY,float damage)
{
	this->damage = damage;
	enemyknight = knightIn;
	width = sizeX;
	height = sizeY;
	bbox = new Rect(-sizeX / 2.0f, -sizeY / 2.0f, sizeX / 2.0f, sizeY / 2.0f);
	type = SWORD;
}


// ---------------------------------------------------------------------------------

EnemySword::~EnemySword()
{
	enemyknight->swordOpen = false;
}

// ---------------------------------------------------------------------------------

void EnemySword::OnCollision(Object* obj)
{

	if (obj->Type() == PLAYER && hit == false)
	{
		Knight* knight = (Knight*)obj;
		if (knight->animGet != 4) {
			if (knight->animGet != 1) {
				knight->reviceAttack(damage);
				hit = true;
				TSOTD::audio->Play(PLAYERDAMAGE);
			}
			else if (knight->side == enemyknight->side) {
				if ((knight->x > x && enemyknight->side == true) || (knight->x < x && enemyknight->side == false)) {
					hit = true;
					knight->reviceAttack(damage*2);
					TSOTD::audio->Play(PLAYERDAMAGE);
				}
			}
			else {
				TSOTD::audio->Play(BLOCK);
			}
		}
	}
}

void EnemySword::Update()
{
	if (enemyknight->side == true) {
		MoveTo(enemyknight->x + (enemyknight->width / 2 + width / 2), enemyknight->y - 12);
	}
	else {
		MoveTo(enemyknight->x - (enemyknight->width / 2 + width / 2), enemyknight->y - 12);
	}
	if (enemyknight->animGet == 3) {


		if (enemyknight->anim->Frame() == 8) {
			enemyknight->scene->Delete();
			//TSOTD::audio->Play(BLOCK);

		}
	}
	if (enemyknight->animGet != 3) {
		enemyknight->scene->Delete();
	}
}



// ---------------------------------------------------------------------------------