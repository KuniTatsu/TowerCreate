#include"SceneManager.h"
#include <cstddef>
#include"DxLib.h"
#include"TitleScene.h"
#include"InGameScene.h"


BaseScene* SceneManager::nowScene = NULL;       //�n�߂̓V�[���͋�

void SceneManager::ChangeScene(SCENE Scene) {

    if (nowScene != NULL) {
        delete nowScene;
    }

    switch (Scene) {          //�����̃V�[��
    case SCENE::TITLE:
        nowScene = new TitleScene();      //�^�C�g���V�[�������݂̃V�[���ɂ���
        break;
    case SCENE::INGAME:
        nowScene = new InGameScene();       //�_���W�����V�[�������݂̃V�[���ɂ���
        break;
    //case SCENE::TRAINING:
    //    nowScene = new TrainingScene();     //�o�g���V�[�������݂̃V�[���ɂ���
    //    break;
    //case SCENE::BATTLE:
    //    nowScene = new BattleScene();     //�o�g���V�[�������݂̃V�[���ɂ���
    //    break;
    default:
        break;
    }

}

void SceneManager::Update() {
    nowScene->Update();         //���݂̃V�[���̍X�V�֐�
}

void SceneManager::Render() {
    nowScene->Draw();           //���݂̃V�[���̕`��֐�
}

void SceneManager::Save()
{
    nowScene->Save();


}

void SceneManager::Load()
{
    nowScene->Load();
}
