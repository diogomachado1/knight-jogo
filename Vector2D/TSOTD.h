/**********************************************************************************
// AnimaMax (Arquivo de Cabeçalho)
//
// Criação:		10 Abr 2012
// Atualização: 06 Jun 2019
// Compilador:	Visual C++ 2019
//
// Descrição:	Exemplo de uso da classe Animation
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

class TSOTD : public Game
{
private:
	static Game* level;			// nível atual do jogo
public:
	static Audio* audio;			// sistema de áudio
	static bool  viewBBox;			// visualiza bounding box
	static Knight* knight;

	template<class T>
	static void NextLevel()			// muda para próximo nível do jogo
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
	void Update();					// atualiza lógica do jogo
	void Draw();					// desenha jogo
	void Finalize();				// finaliza jogo
};

// ---------------------------------------------------------------------------------

#endif