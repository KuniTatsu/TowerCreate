#include <time.h>
#include <list>
#include <map>
#include <algorithm>
#include "game_main.h"
#include "../dxlib_ext/dxlib_ext.h"
#include"GameManager.h"

bool init = false;

GameManager* GameManager::instance = nullptr;

void gameMain(float delta_time) {

	if (!init) {
		GameManager* gManager = GameManager::Instance();

		gManager->initGameManager();
		init = true;
	}

}

