#pragma once
#include "Scene.h"

class Scene;

class SceneManager {
public:
	enum SCENE {
		TITLE,
		INGAME


	};

	static void ChangeScene(SCENE scene);     //
	static void Update();                     //
	static void Render();                     //

	static BaseScene* m_pScene;               //

	static void Save();
	static void Load();

};