#include "MapManager.h"
#include"Block.h"
#include"GameManager.h"
#include<memory>

MapManager::MapManager()
{
	gManager = GameManager::Instance();
}

MapManager::~MapManager()
{
}

void MapManager::MakeMap()
{
	int x = 0;
	int y = 400;

	for (int i = 0; i < 30; ++i) {
		for (int k = 0; k < 50; ++k) {
			Block* block = new Block(x, y, 10, gManager->testGraphic);
			x += 20;
		}
		x = 0;
		y += 20;
	}

}
