
#include "TSOTD.h"
#include "Home.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Level4.h"
#include "Level5.h"
#include "Knight.h"
#include "Mouse.h"


// ------------------------------------------------------------------------------



void Home::Init()
{
	TSOTD::audio->Stop(MUSIC);
	anim = new Animation(new TileSet("Resources/newKnight/knightIdleR.png", 100, 100, 4, 4), 0.150f, true);
	title = new Sprite("Resources/title.png");
	backg = new Sprite("Resources/battleground.png");
	mouse = new Mouse();
	menu[0] = new Item(870, 600, PLAY, "Resources/SinglePlayer.png");
	menu[1] = new Item(870, 700, EXIT, "Resources/ExitGame.png");
	TSOTD::knight = new Knight();
	scene = new Scene();
}

// ------------------------------------------------------------------------------

void Home::Finalize()
{
	delete scene;

	// remove sprites
	delete backg;

	// remove objetos
	delete mouse;
	for (int i = 0; i < MaxItens; ++i)
		delete menu[i];
}

// ------------------------------------------------------------------------------

void Home::Update()
{
	mouse->Update();

	anim->NextFrame();
	// destaca item selecionado
	for (int i = 0; i < MaxItens; ++i)
	{
		if (scene->Collision(mouse, menu[i]))
		{
			menu[i]->Select();

			// executa ações do menu 
			if (mouse->Clicked())
			{
				switch (menu[i]->Type())
				{
				case PLAY:fase = 1; break;
				case EXIT: window->Close(); break;
				}
			}
		}
		else
		{
			menu[i]->UnSelect();
		}
		menu[i]->Update();

	}
	// sai do jogo com a tecla ESC
	if (window->KeyUp(VK_ESCAPE))
		ctrlKeyESC = true;
	if (ctrlKeyESC && window->KeyDown(VK_ESCAPE))
		window->Close();
	if (fase == 1) {
		TSOTD::knight->MoveTo(100, 600);
		TSOTD::NextLevel<Level1>();
	}
	// passa ao primeiro nível com ENTER
	if (window->KeyDown(VK_RETURN)) {
		TSOTD::knight->MoveTo(100, 600);
		TSOTD::NextLevel<Level1>();
	}
}

// ------------------------------------------------------------------------------

void Home::Draw()
{
	anim->Draw(200.0f, 500.0f, Layer::MIDBACK, 5.0f);
	backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
	title->Draw(float(window->CenterX()),100.0f, Layer::BACK);
	for (int i = 0; i < MaxItens; ++i)
		menu[i]->Draw();
}

// ------------------------------------------------------------------------------