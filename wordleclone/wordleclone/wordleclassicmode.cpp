#include "wordleclassicmode.h"

wordleclassicmode::wordleclassicmode(std::initializer_list<std::string> nameOfFilesToLoad)
{
	virtualFileLoader* buf = nullptr;

	this->doesFilesExist = 1;
	this->nextScene = '0';
	this->lives = myEnum::five;
	this->points = 0;
	this->userWord = "";
	this->wordNumber = myEnum::one;

	int firstItem = 1;


	for (const auto& oneNameOfFileToLoad : nameOfFilesToLoad)
	{
		if (firstItem)
		{
			buf = new fileLoaderDictionary(oneNameOfFileToLoad);
			this->objects.push_back(buf);
			doesFilesExist = buf->getDoesItExist() * doesFilesExist;
		}
		else
		{
			buf = new fileLoaderRawData(oneNameOfFileToLoad);
			this->objects.push_back(buf);
			doesFilesExist = buf->getDoesItExist() * doesFilesExist;
			this->fileWithScores = oneNameOfFileToLoad;

		}
		firstItem = 0;
	}

	this->livesWord.push_back(this->objects[myEnum::L]->getData()); this->livesWord.push_back(this->objects[myEnum::I]->getData());
	this->wordWord.push_back(this->objects[myEnum::W]->getData()); this->wordWord.push_back(this->objects[myEnum::O]->getData());
	this->isNotAWord.push_back(this->objects[myEnum::I]->getData()); this->isNotAWord.push_back(this->objects[myEnum::N]->getData()); this->isNotAWord.push_back(this->objects[myEnum::W]->getData());
};

wordleclassicmode::~wordleclassicmode()
{
	for (const auto& object : this->objects)
	{
		delete object;
	}
}

void wordleclassicmode::reload()
{
	virtualFileLoader* buf = objects[myEnum::fileWithUsers];
	this->objects.pop_back();
	delete buf;
	buf = new fileLoaderRawData(fileWithScores);
	this->objects.push_back(buf);
	doesFilesExist = buf->getDoesItExist() * doesFilesExist;
}

void wordleclassicmode::run(UI* interFace)
{
	char userSingleCharResponse;
	

	reload();
	bool guessed = 0;
	lives = myEnum::five;
	wordNumber = myEnum::one - 1;
	points = 0;

	theWordsToGuess = this->objects[myEnum::DICTIONARY]->getData();


	std::for_each(theWordsToGuess.begin(), theWordsToGuess.end(), [&](std::string oneWord) {

		wordNumber++;
		interFace->clearScreen();
		std::cout << oneWord;

		Sleep(2000);

		interFace->clearScreen();
		lives = myEnum::five;

		wordWord.push_back(this->objects[wordNumber]->getData());
		livesWord.push_back(this->objects[lives]->getData());

		interFace->printOutGuessedWord(wordWord);
		interFace->printOutGuessedWord(livesWord);

		interFace->printOutSingleString(0, "\n");

		do 
		{
			do
			{
			
				interFace->getUserResponseNoEnter(userSingleCharResponse, 'a', 'z');
				interFace->clearScreen();

				this->userWord.push_back(userSingleCharResponse);

				interFace->printOutGuessedWord(wordWord);
				interFace->printOutGuessedWord(livesWord);
				makeASCIIWordAndPassItToPrintItOutWithColors(interFace);
				interFace->printOutSingleString(0, "\n");

				makeASCIIWordAndPassItToPrintItOut(interFace);

			} while (this->userWord.size() != 5);


			if (((fileLoaderDictionary*)objects[0])->doesWordExist(this->userWord))
			{
			addColorsAndWordToVectorsToDisplayItColorful(oneWord);
			livesWord.pop_back();
			lives--;
			livesWord.push_back(this->objects[lives]->getData());
			}
			else
			{
				interFace->printOutGuessedWord(isNotAWord);
				Sleep(2000);
			}

			interFace->clearScreen();
			interFace->printOutGuessedWord(wordWord);
			interFace->printOutGuessedWord(livesWord);
			
			makeASCIIWordAndPassItToPrintItOutWithColors(interFace);
			
			interFace->printOutSingleString(0, "\n");

			if (userWord == oneWord)
			{
				points++;
				userWord.clear();
				break;
			}

			userWord.clear();


		} while (lives != myEnum::one - 1);

		livesWord.pop_back();
		wordWord.pop_back();

		guessedWordsYet.clear();
		guessedWordsYetColorsInt.clear();

		Sleep(3000);

		});

	resultsOfGame(interFace);


}

void wordleclassicmode::makeASCIIWordAndPassItToPrintItOut(UI* interFace)
{
	myList<myList<std::string>> userWordThatIsBeingTyped;

	std::for_each(userWord.begin(), userWord.end(), [&](char singlechar) {
		userWordThatIsBeingTyped.push_back(this->objects[singlechar-96]->getData());
		});

	interFace->printOutGuessedWord(userWordThatIsBeingTyped);
}

void wordleclassicmode::addColorsAndWordToVectorsToDisplayItColorful(std::string wordToGuess)
{
	myList<int> colorBufor;

	for (int i = 0; i < 5; i++)
	{
		if (wordToGuess[i] == userWord[i])
		{
			colorBufor.push_back(1);
		}
		else
		{
			colorBufor.push_back(2);
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (userWord[i] == wordToGuess[j] && colorBufor[i] != 1 && colorBufor[j] != 1)
			{
				colorBufor[i] = 3;
			}
		}
	}

	guessedWordsYet.push_back(userWord);
	guessedWordsYetColorsInt.push_back(colorBufor);
	
}

void wordleclassicmode::makeASCIIWordAndPassItToPrintItOutWithColors(UI* interFace)
{
	myList<myList<std::string>> userWordThatIsBeingTyped;

	int i = 0;
	if (guessedWordsYet.size() != 0)
	{
		std::for_each(guessedWordsYet.begin(), guessedWordsYet.end(), [&](std::string& singleUserWord) {
			userWordThatIsBeingTyped.clear();
		std::for_each(singleUserWord.begin(), singleUserWord.end(), [&](char singlechar) {
			userWordThatIsBeingTyped.push_back(this->objects[singlechar - 96]->getData());
			});
		interFace->printOutGuessedWordColored(guessedWordsYetColorsInt[i], userWordThatIsBeingTyped);
		i++;
			});

	}

}

void wordleclassicmode::resultsOfGame(UI* interFace)
{
	char userSingleCharResponse;

	interFace->clearScreen();


	std::cout << "Points: " << points << std::endl;

	Sleep(3000);

	if (points)
	{
		std::string userDataNameAndPoints;

		interFace->printOutSingleString(0, "Would, you like to save this score?");
		interFace->printOutSingleString(1, "1. Save your score");
		interFace->printOutSingleString(2, "2. Don't save your score");

		interFace->getUserResponseNoEnter(userSingleCharResponse, '1', '2');

		if (userSingleCharResponse == '1')
		{
			interFace->printOutSingleString(0, "Enter the username use \"_\" insted of spaces : ");
			interFace->getUserResponse(userDataNameAndPoints);

			userDataNameAndPoints.push_back(' ');
			userDataNameAndPoints.push_back(points + '0');

			saveToFile(userDataNameAndPoints);
			
		}

	}
}

void wordleclassicmode::saveToFile(std::string& lineToSave)
{
	std::fstream fileStreamToAppend;
	try
	{
		fileStreamToAppend.open(this->fileWithScores, std::ios::out);

		if (!fileStreamToAppend.is_open())
		{
			throw std::runtime_error("Could not open file");
		}
	
		int loadmax5 = objects[myEnum::fileWithUsers]->getData().size();

		for (const auto& line : objects[myEnum::fileWithUsers]->getData())
		{
			if (loadmax5 <= 4)
			{
				fileStreamToAppend << line;
				fileStreamToAppend << std::endl;
			}
			loadmax5--;
		}

	fileStreamToAppend << lineToSave;
	fileStreamToAppend << std::endl;

	}
	catch(std::runtime_error& ex)
	{
		std::cout << ex.what();
	}

}

int wordleclassicmode::getNextScene()
{
	return  int(this->nextScene - '0');
}