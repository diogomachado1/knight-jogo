#include "BossPower.h"

#include "TSOTD.h"
#include "Knight.h"

// ---------------------------------------------------------------------------------

BossPower::BossPower(float posX, float posY)
{
	swordItem = new Sprite("Resources/sword.png");
	scale = 2;
	bbox = new Rect((-swordItem->Width() * scale) / 2.0f, (-swordItem->Height() * scale) / 2.0f, (swordItem->Width() * scale) / 2.0f, (swordItem->Height() * scale) / 2.0f);
	MoveTo(posX, posY, Layer::MIDDLE);
}

// ---------------------------------------------------------------------------------

BossPower::~BossPower()
{
	delete swordItem;
	delete bbox;
}

void BossPower::OnCollision(Object* obj)
{
	if (obj->Type() == PLAYER)
	{
		Knight* knight = (Knight*)obj;
		knight->reviceAttack(65);
		hit = true;
	}
	if (obj->Type() == SWORD)
	{
    		hit = true;
	}
}
// -------------------------------------------------------------------------------

void BossPower::Update()
{
	Translate(0, 200*gameTime);
	if (hit == true || this->y > 900) {
		TSOTD::knight->scene->Delete();
	}

}

// -------------------------------------------------------------------------------
