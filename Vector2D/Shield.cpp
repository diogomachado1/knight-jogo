
#include "Shield.h"
#include "TSOTD.h"
#include "Knight.h"

// ---------------------------------------------------------------------------------

Shield::Shield(float posX, float posY, Scene* scene)
{
	this->scene = scene;
	shield = new Sprite("Resources/shield.png");
	scale = 0.3;
	bbox = new Rect((-shield->Width() * scale) / 2.0f, (-shield->Height() * scale) / 2.0f, (shield->Width() * scale) / 2.0f, (shield->Height() * scale) / 2.0f);
	MoveTo(posX, posY, Layer::MIDDLE);
}

// ---------------------------------------------------------------------------------

Shield::~Shield()
{
	delete shield;
	delete bbox;
}

void Shield::OnCollision(Object* obj)
{

	if (obj->Type() == PLAYER)
	{
		Knight* knight = (Knight*)obj;
		knight->shields++;
		scene->Remove(this, STATIC);
		delete this;
	}
}
// -------------------------------------------------------------------------------

void Shield::Update()
{
	// move plataforma apenas no eixo x

}

// -------------------------------------------------------------------------------
