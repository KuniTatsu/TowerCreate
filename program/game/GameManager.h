//ゲーム全体を管理するマネージャクラス
//シングルトンで作られている


#pragma once
#include<vector>
#include<list>
#include<string>
#include<unordered_map>
#include"../dxlib_ext/dxlib_ext.h"
#include<memory>

class SceneManager;
class Object;
class MapManager;
class Camera;
class Player;

class Item;
class FadeControl;
class Sound;

class GameManager {

protected:
	GameManager();
	~GameManager();
public:
	//インスタンスがなければ生成、あれば返す関数
	static GameManager* Instance();
	//static std::shared_ptr<GameManager> Instance();

	//オブジェクトリスト登録
	inline void AddObjectList(Object* Obj) {
		objects.emplace_back(Obj);
	}
	//オブジェクトリスト取得
	inline std::list<Object*>GetList() {
		return objects;
	}
	//優先度でリストをソート
	bool SortWithPriority(Object* obj1, Object* obj2);

	int testGraphic = 0;

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
	int LoadGraphEx(std::string Gh);

	//DrawRotaGraphの短縮版
	void DrawRotaGraphNormal(int X, int Y, int GrHandle, int TransFlag);

	//ghを返す関数
	std::vector<int> SetCharaGh(int Num);

	//debug
	void Move();

	tnl::Vector3& GetCameraPos();

	void PlayerMove();
	void PlayerDraw();

private:
	//シングルトンインスタンス
	static GameManager* instance;
	//static std::shared_ptr<GameManager> instance;

	//プレイヤーキャラクタGh
	int playerGh[12] = {};

	//オブジェクトのリスト
	std::list<Object*> objects;
	//マップマネージャ
	MapManager* mManager = nullptr;
	//カメラ
	Camera* camera = nullptr;
	//プレイヤー
	Player* player = nullptr;


	//アイテム情報をexcelから読み取る関数
	void loadItem();

	std::vector<std::vector<std::string>> loadItemCsv;
};