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



	//��x�ǂݍ���gh��ۑ�����map
	std::unordered_map<std::string, int> ghmap;

	float deitatime_;


	void Update();
	void Draw();

	//GameManager�̏�����
	void initGameManager();

	//�摜��ǂݍ����map�ɓ����֐�
	//���łɂ���gh�Ȃ炻���Ԃ�
	int LoadGraphEx(std::string gh);



	//gh��Ԃ��֐�
	std::vector<int> SetCharaGh(int num);


private:

	static GameManager* instance;

	//�A�C�e������excel����ǂݎ��֐�
	void loadItem();

	std::vector<std::vector<std::string>> loadItemCsv;
};