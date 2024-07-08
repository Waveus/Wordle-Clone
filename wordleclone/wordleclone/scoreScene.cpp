#include "scoreScene.h"

void scoreScene::reload()
{
	virtualFileLoader* buf = objects[1];
	this->objects.pop_back();
	delete buf;
	buf = new fileLoaderRawData(nameOfFileWithScores);
	this->objects.push_back(buf);
	doesFilesExist = buf->getDoesItExist() * doesFilesExist;

}

void scoreScene::run(UI* interFace)
{

	reload();

	interFace->printOutStringVector(1, (objects[0])->getData());
	interFace->printOutSingleString(1, "\n");
	interFace->printOutStringVector(1, (objects[1])->getData());
	interFace->printOutSingleString(1, "Press the \"e\" to exit");
	interFace->getUserResponseNoEnter(this->nextScene, 'e', 'e');

}

int scoreScene::getNextScene()
{
	return 0;
}
