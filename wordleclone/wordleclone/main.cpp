#include <iostream>
#include <memory>
#include "UI.h"
#include "fileLoaderRawData.h"
#include "game.h"
#include "scene.h"
#include "virtualFileLoader.h"
#include "fileLoaderDictionary.h"
#include "mainMenu.h"
#include "wordleclassicmode.h"
#include "scoreScene.h"
#include "testListClass.h"
#include "addToDictionary.h"


#define DICTIONARY "dictionary.txt"
#define LOGO "image1.txt"
#define mainMenuTxt "mainMenu.txt"
#define BESTRESULTLOGO "bestResults.txt"
#define USERRESULTS "fileWithScores.txt"

#define A "A.txt"
#define B "B.txt"
#define C "C.txt"
#define D "D.txt"
#define E "E.txt"
#define F "F.txt"
#define G "G.txt"
#define H "H.txt"
#define I "I.txt"
#define J "J.txt"
#define K "K.txt"
#define L "L.txt"
#define M "M.txt"
#define N "N.txt"
#define O "O.txt"
#define P "P.txt"
#define Q "Q.txt"
#define R "R.txt"
#define S "S.txt"
#define T "T.txt"
#define U "U.txt"
#define V "V.txt"
#define W "W.txt"
#define X "X.txt"
#define Y "Y.txt"
#define Z "Z.txt"
#define zero "0.txt"
#define one "1.txt"
#define two "2.txt"
#define three "3.txt"
#define four "4.txt"
#define five "5.txt"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//
	// UI
	//

	UI* userInterface = new UI();

	//
	// SCENES
	//

	scene* ADDTODIC = new addToDictionary(DICTIONARY);
	scene* MAINMENU = new mainMenu({ LOGO, mainMenuTxt });
	scene* GAMESCENE = new wordleclassicmode({ DICTIONARY, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, zero, one, two, three, four, five, USERRESULTS }); //27, 31 - cyfry
	scene* RESULTSSCENE = new scoreScene({ BESTRESULTLOGO, USERRESULTS });

	//
	// CHECK IS GOOD
	//
	
	if (MAINMENU->doesFilesExistReturnValue() && GAMESCENE->doesFilesExistReturnValue() && RESULTSSCENE->doesFilesExistReturnValue())
	{
	game GAME = { MAINMENU, GAMESCENE, RESULTSSCENE, ADDTODIC };
	GAME.run(userInterface);
	}
	else
	{
		std::cout << "Files cannot be opened";
	}

	//
	// FREE MEMORY
	//

	delete RESULTSSCENE;	
	RESULTSSCENE = nullptr;

	delete MAINMENU;
	MAINMENU = nullptr;

	delete userInterface;
	userInterface = nullptr;

	delete GAMESCENE;
	GAMESCENE = nullptr;

	delete ADDTODIC;
	ADDTODIC = nullptr;

}
