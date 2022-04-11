#pragma once
class Block;
class GameManager;

class MapManager
{
public:
	MapManager();
	~MapManager();


	void MakeMap();


private:

	GameManager* gManager = nullptr;


};

