/**********************************************************************************
// AnimaMax (Arquivo de Cabe�alho)
//
// Cria��o:		10 Abr 2012
// Atualiza��o: 06 Jun 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Exemplo de uso da classe Animation
//
**********************************************************************************/

#ifndef _TSOTD_H_
#define _TSOTD_H_


#include "Game.h"
#include "Audio.h"
#include "Resources.h"
#include "Knight.h"

// ------------------------------------------------------------------------------
enum ObjTypes
{
	PLAYER,
	ENEMY,
	WALL,
	SWORD,
};
enum Sounds { MENU, MUSIC, ATTACK, BLOCK,ENEMYDEATH,PLAYERDAMAGE,PLAYERDEATH,SWING, LV4MUSIC, BOSS};
class TSOTD : public Game
{
private:
	static Game* level;			// n�vel atual do jogo
public:
	static Audio* audio;			// sistema de �udio
	static bool  viewBBox;			// visualiza bounding box
	static Knight* knight;

	template<class T>
	static void NextLevel()			// muda para pr�ximo n�vel do jogo
	{
		if (level)
		{
			level->Finalize();
			delete level;
			level = new T();
			level->Init();
		}
	};

	void Init();					// inicializa jogo
	void Update();					// atualiza l�gica do jogo
	void Draw();					// desenha jogo
	void Finalize();				// finaliza jogo
};

// ---------------------------------------------------------------------------------

#endif