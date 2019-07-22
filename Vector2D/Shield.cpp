
#include "Shield.h"
#include "TSOTD.h"
#include "Knight.h"

// ---------------------------------------------------------------------------------

Shield::Shield(float posX, float posY, Scene* scene, int number)
{
	this->number = number;
	this->scene = scene;
	shield = new Sprite("Resources/shield.png");
	scale = 0.3;
	bbox = new Rect((-shield->Width() * scale) / 2.0f, (-shield->Height() * scale) / 2.0f, (shield->Width() * scale) / 2.0f, (shield->Height() * scale) / 2.0f);
	MoveTo(posX, posY, Layer::MIDDLE);
	//if (TSOTD::knight->shieldsArray[number] == true) {
	//	delete this;
	//}
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
		knight->shieldsArray[number] = true;
	}
}
// -------------------------------------------------------------------------------

void Shield::Update()
{
	if (TSOTD::knight->shieldsArray[number]==true) {
		TSOTD::knight->scene->Delete();
	}

	// move plataforma apenas no eixo x

}

// -------------------------------------------------------------------------------
