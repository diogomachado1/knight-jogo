/**********************************************************************************
// Item (C�digo Fonte)
//
// Cria��o:		14 Mai 2012
// Atualiza��o:	30 Jun 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Define um item de menu
//
**********************************************************************************/

#include "Item.h"

// ---------------------------------------------------------------------------------

Item::Item(float posX, float posY, uint menuId, string imgFile)
{
	tileset = new TileSet(imgFile, 400, 100, 1, 3);
	animation = new Animation(tileset, 0.200f, true);

	uint selected[2] = { 1,2 };
	animation->Add(SELECTED, selected, 2);

	uint notselected[1] = { 0 };
	animation->Add(NOTSELECTED, notselected, 1);

	// cria bounding box
	bbox = new Rect(-1.0f * tileset->TileWidth() / 2.0f,
		-1.0f * tileset->TileHeight() / 2.0f,
		tileset->TileWidth() / 2.0f,
		tileset->TileHeight() / 2.0f);

	MoveTo(posX, posY, Layer::FRONT);
	type = menuId;
}

// ---------------------------------------------------------------------------------

Item::~Item()
{
	delete bbox;
	delete animation;
	delete tileset;
}

// -------------------------------------------------------------------------------

void Item::Select()
{
	animation->Select(SELECTED);
}

// -------------------------------------------------------------------------------

void Item::UnSelect()
{
	animation->Select(NOTSELECTED);
}

// -------------------------------------------------------------------------------

void Item::Update()
{
	animation->NextFrame();
}

// -------------------------------------------------------------------------------

void Item::Draw()
{
	animation->Draw(x, y, z);
}

// -------------------------------------------------------------------------------