#pragma once
#include "scene.h"
#include "fileLoaderDictionary.h"
#include <windows.h>
#include <stdexcept>
#include <fstream>
#include "myList.h"

class wordleclassicmode : public scene
{
private:
	
	int lives, points, wordNumber;

	std::string userWord, fileWithScores;
	myList<std::string> theWordsToGuess;
	myList<myList<std::string>> livesWord, wordWord, isNotAWord; //ASCII Imagines
	
	myList<std::string> guessedWordsYet;
	myList<myList<int>> guessedWordsYetColorsInt;

	enum myEnum {
		DICTIONARY,
		A,
		B,
		C,
		D,
		E,
		F,
		G,
		H,
		I,
		J,
		K,
		L,
		M,
		N,
		O,
		P,
		Q,
		R,
		S,
		T,
		U,
		V,
		W,
		X,
		Y,
		Z,
		zero,
		one,
		two,
		three,
		four,
		five,
		fileWithUsers
	};

	
	void addColorsAndWordToVectorsToDisplayItColorful(std::string wordToGuess);
	void makeASCIIWordAndPassItToPrintItOut(UI* interFace);
	void makeASCIIWordAndPassItToPrintItOutWithColors(UI* interFace);
	void resultsOfGame(UI* interFace);
	void saveToFile(std::string& lineToSave);


public:

	wordleclassicmode(std::initializer_list<std::string> nameOfFilesToLoad);
	~wordleclassicmode();

	void reload();

	void run(UI* interFace);

	int getNextScene();

};

