//�Q�[���S�̂��Ǘ�����}�l�[�W���N���X
//�V���O���g���ō���Ă���


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
	//�C���X�^���X���Ȃ���ΐ����A����ΕԂ��֐�
	static GameManager* Instance();
	//static std::shared_ptr<GameManager> Instance();

	//�I�u�W�F�N�g���X�g�o�^
	inline void AddObjectList(Object* Obj) {
		objects.emplace_back(Obj);
	}
	//�I�u�W�F�N�g���X�g�擾
	inline std::list<Object*>GetList() {
		return objects;
	}
	//�D��x�Ń��X�g���\�[�g
	bool SortWithPriority(Object* obj1, Object* obj2);

	int testGraphic = 0;

	/*SceneManager* sManager = nullptr;
	FadeControl* fControl = nullptr;
	Sound* sound = nullptr;*/



	//��x�ǂݍ���gh��ۑ�����map
	std::unordered_map<std::string, int> ghmap;

	float deitatime_;


	void Update();
	void Draw();

	//GameManager�̏�����
	void initGameManager();

	//�摜��ǂݍ����map�ɓ����֐�
	//���łɂ���gh�Ȃ炻���Ԃ�
	int LoadGraphEx(std::string Gh);

	//DrawRotaGraph�̒Z�k��
	void DrawRotaGraphNormal(int X, int Y, int GrHandle, int TransFlag);

	//gh��Ԃ��֐�
	std::vector<int> SetCharaGh(int Num);

	//debug
	void Move();

	tnl::Vector3& GetCameraPos();

	void PlayerMove();
	void PlayerDraw();

private:
	//�V���O���g���C���X�^���X
	static GameManager* instance;
	//static std::shared_ptr<GameManager> instance;

	//�v���C���[�L�����N�^Gh
	int playerGh[12] = {};

	//�I�u�W�F�N�g�̃��X�g
	std::list<Object*> objects;
	//�}�b�v�}�l�[�W��
	MapManager* mManager = nullptr;
	//�J����
	Camera* camera = nullptr;
	//�v���C���[
	Player* player = nullptr;


	//�A�C�e������excel����ǂݎ��֐�
	void loadItem();

	std::vector<std::vector<std::string>> loadItemCsv;
};