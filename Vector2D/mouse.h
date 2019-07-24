/**********************************************************************************
// Mouse (Arquivo de Cabe�alho)
//
// Cria��o:		14 Mai 2012
// Atualiza��o:	30 Jun 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Gerencia mouse na tela
//
**********************************************************************************/

#ifndef _MENU_MOUSE_H_
#define _MENU_MOUSE_H_

// ---------------------------------------------------------------------------------

#include "Object.h"		
#include "Types.h"		

// ---------------------------------------------------------------------------------

class Mouse : public Object
{
public:
	Mouse();							// construtor
	~Mouse();							// destrutor

	bool Clicked();						// click do mouse
	void Update();						// atualiza��o do objeto
	void Draw();						// desenho do objeto 
};

// ---------------------------------------------------------------------------------

#endif