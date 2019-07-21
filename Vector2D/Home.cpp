
#include "Engine.h"
#include "Home.h"
#include "Level1.h"
#include "Knight.h"

// ------------------------------------------------------------------------------



void Home::Init()
{
	backg = new Sprite("Resources/titleScreen.jpg");
	this->knight = new Knight();
}

// ------------------------------------------------------------------------------

void Home::Finalize()
{
	delete backg;
}

// ------------------------------------------------------------------------------

void Home::Update()
{
	// sai do jogo com a tecla ESC
	if (window->KeyUp(VK_ESCAPE))
		ctrlKeyESC = true;
	if (ctrlKeyESC && window->KeyDown(VK_ESCAPE))
		window->Close();

	// passa ao primeiro nível com ENTER
	if (window->KeyDown(VK_RETURN))
		Engine::Next<Level1>();
}

// ------------------------------------------------------------------------------

void Home::Draw()
{
	backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
}

// ------------------------------------------------------------------------------