
#include "TSOTD.h"
#include "Home.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Level4.h"
#include "Knight.h"

// ------------------------------------------------------------------------------



void Home::Init()
{
	backg = new Sprite("Resources/titleScreen.jpg");
	TSOTD::knight = new Knight();
	
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
	if (window->KeyDown(VK_RETURN)) {
		TSOTD::knight->MoveTo(100, 700);
		TSOTD::NextLevel<Level1>();

	}
}

// ------------------------------------------------------------------------------

void Home::Draw()
{
	backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
}

// ------------------------------------------------------------------------------