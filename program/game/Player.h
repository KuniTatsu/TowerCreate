#pragma once
#include"Object.h"

class GameManager;

class Player :public Object
{
public:
	Player();
	~Player();

	void update(float Deltatime)override;
	void render(float Deltatime)override;

	void Move();

	enum dir {
		UP,
		RIGHT,
		DOWN,
		LEFT
	};
	dir mydir = UP;

private:
	int playerGh[12] = {};
	GameManager* gManager = nullptr;
	void Draw();
	void Anim(int* DrawGhArr, int Speed, int MaxIndex, int& DrawGh);

	int actSpeed = 20;
	int maxMotionIndex = 3;


	//通常時の描画するアニメーション画像
	int drawGh = 0;
	int actWait = actSpeed;
	int actIndex = 0;

};

