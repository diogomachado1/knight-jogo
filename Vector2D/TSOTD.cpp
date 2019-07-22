     /**********************************************************************************
// AnimaMax (C�digo Fonte)
// 
// Cr                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   f  ia��o:		10 Abr 2012
// Atualiza��o: 06 Jun 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Exemplo de uso da classe Animation
//
**********************************************************************************/


#include "Resources.h"
#include "Engine.h"
#include "TSOTD.h"
#include "Home.h"
//#include "GameOver.h"

// ------------------------------------------------------------------------------

// inicializa membros est�ticos da classe
Game* TSOTD::level = nullptr;
Audio* TSOTD::audio = nullptr;
bool TSOTD::viewBBox = false;
Knight* TSOTD::knight = new Knight();

// ------------------------------------------------------------------------------

void TSOTD::Init()
{
	// cria sistema de �udio
	audio = new Audio();
	audio->Add(MENU, "Resources/Menu.wav");
	audio->Add(MUSIC, "Resources/song.wav");
	audio->Add(ATTACK, "Resources/attack.wav");
	audio->Add(SWING, "Resources/swing.wav");
	audio->Add(BLOCK, "Resources/block.wav");
	audio->Add(PLAYERDAMAGE, "Resources/hit.wav");
	/*audio->Add(PLAYERDEATH, "Resources/playerDeath.wav");
	audio->Add(ENEMYDEATH, "Resources/enemyDeath.wav");*/

	knight = new Knight();

	viewBBox = false;
	level = new Home();
	level->Init();
}

// ------------------------------------------------------------------------------

void TSOTD::Update()
{
	// habilita/desabilita visualiza��o da bounding box
	if (window->KeyCtrl('B'))
		viewBBox = !viewBBox;

	// atualiza n�vel
	level->Update();
}

// ------------------------------------------------------------------------------

void TSOTD::Draw()
{
	// desenha n�vel
	level->Draw();
}

// ------------------------------------------------------------------------------

void TSOTD::Finalize()
{
	level->Finalize();

	//delete audio;
	delete level;
}
// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	Engine * engine = new Engine();

	// configura janela
	engine->window->Mode(WINDOWED);
	engine->window->Size(1200, 800);
	engine->window->Color(0, 0, 0);
	engine->window->Title("The Sword of The Dawn");
	engine->window->Icon(IDI_ICON);
	engine->window->Cursor(IDC_CURSOR);

	// configura dispositivo gr�fico
	engine->graphics->VSync(true);
	
	// inicia o jogo
	int status = engine->Start(new TSOTD());

	delete engine;
	return status;
}

// ----------------------------------------------------------------------------

