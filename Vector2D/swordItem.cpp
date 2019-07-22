#include "swordItem.h"

#include "TSOTD.h"
#include "Knight.h"

// ---------------------------------------------------------------------------------

SwordItem::SwordItem(float posX, float posY, Scene* scene)
{
	this->scene = scene;
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
		scene->Remove(this, STATIC);
		delete this;
	}
}
// -------------------------------------------------------------------------------

void SwordItem::Update()
{
	// move plataforma apenas no eixo x

}

// -------------------------------------------------------------------------------
