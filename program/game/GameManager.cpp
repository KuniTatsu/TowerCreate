#include "GameManager.h"
#include"SceneManager.h"
#include"DxLib.h"
#include"../dxlib_ext/dxlib_ext.h"
#include<string>

//#include"Item.h"
//#include "FadeControl.h"
//#include "SoundManager.h"



GameManager::GameManager()
{
	tnl::DebugTrace("\n�R���X�g���N�^���Ă΂ꂽ��\n");
}

GameManager* GameManager::Instance()
{
	if (instance == nullptr) {
		instance = new GameManager;
	}
	return instance;
}

GameManager::~GameManager()
{

}

void GameManager::Update()
{
	SceneManager::Update();
}
void GameManager::Draw()
{
	SceneManager::Render();
}

void GameManager::initGameManager()
{

	//sound = new Sound();
	//fControl = new FadeControl();

	deitatime_ = 0;

	SceneManager::ChangeScene(SceneManager::SCENE::TITLE);

}

int GameManager::LoadGraphEx(std::string gh)
{

	auto it = ghmap.find(gh);
	if (it != ghmap.end()) {
		return ghmap[gh];
	}

	else {
		int loadgh = LoadGraph(gh.c_str());
		ghmap.insert(std::make_pair(gh, loadgh));
	}


	return ghmap[gh];
}


void GameManager::loadItem()
{
	loadItemCsv = tnl::LoadCsv("Csv/Item.csv");
	for (int i = 1; i < loadItemCsv.size(); ++i) {

		//id
		int a = std::atoi(loadItemCsv[i][0].c_str());
		//ItemType
		int b = std::atoi(loadItemCsv[i][1].c_str());
		//setDay
		int c = std::atoi(loadItemCsv[i][2].c_str());
		//addStatus
		int d = std::atoi(loadItemCsv[i][3].c_str());
		//addStatusNum
		int e = std::atoi(loadItemCsv[i][4].c_str());
		//setAbility
		int f = std::atoi(loadItemCsv[i][5].c_str());
		//setAbilityType
		int g = std::atoi(loadItemCsv[i][6].c_str());
		//num
		int h = std::atoi(loadItemCsv[i][10].c_str());


		//Item* abi = new Item(a, b, c, d, e, f, g, loadItemCsv[i][7], loadItemCsv[i][8], loadItemCsv[i][9], h);

		//abilitytype���ƂɃ��X�g�Ɋi�[
		//itemList[b].emplace_back(abi);
	}
}

