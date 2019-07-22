#include "swordItem.h"

#include "TSOTD.h"
#include "Knight.h"

// ---------------------------------------------------------------------------------

SwordItem::SwordItem(float posX, float posY, Scene* scene, int number)
{
	this->scene = scene;
	this->number = number;
	swordItem = new Sprite("Resources/sword.png");
	scale = 1;
	bbox = new Rect((-swordItem->Width() * scale) / 2.0f, (-swordItem->Height() * scale) / 2.0f, (swordItem->Width() * scale) / 2.0f, (swordItem->Height() * scale) / 2.0f);
	MoveTo(posX, posY, Layer::MIDDLE);
}

// ---------------------------------------------------------------------------------

SwordItem::~SwordItem()
{
	delete swordItem;
	delete bbox;
}

void SwordItem::OnCollision(Object* obj)
{
	if (obj->Type() == PLAYER)
	{
		Knight* knight = (Knight*)obj;
		knight->swordItems++;
		knight->swordsArray[number] = true;
	}
}
// -------------------------------------------------------------------------------

void SwordItem::Update()
{
	if (TSOTD::knight->swordsArray[number] == true) {
		TSOTD::knight->scene->Delete();
	}

}

// -------------------------------------------------------------------------------
