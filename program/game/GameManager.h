#pragma once
#include<vector>
#include<string>
#include<unordered_map>
class SceneManager;

class Item;
class FadeControl;
class Sound;

class GameManager {

protected:
	GameManager();
	~GameManager();
public:

	static GameManager* Instance();


	//GameManager();


	/*SceneManager* sManager = nullptr;
	FadeControl* fControl = nullptr;
	Sound* sound = nullptr;*/



	//一度読み込んだghを保存するmap
	std::unordered_map<std::string, int> ghmap;

	float deitatime_;


	void Update();
	void Draw();

	//GameManagerの初期化
	void initGameManager();

	//画像を読み込んでmapに入れる関数
	//すでにあるghならそれを返す
	int LoadGraphEx(std::string gh);



	//ghを返す関数
	std::vector<int> SetCharaGh(int num);


private:

	static GameManager* instance;

	//アイテム情報をexcelから読み取る関数
	void loadItem();

	std::vector<std::vector<std::string>> loadItemCsv;
};