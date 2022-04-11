//インゲームで置かれるブロック一つ一つのクラス
//ブロックごとに破壊するための体力と画像ハンドルを持つ

#pragma once
#include"Object.h"

class Block:public Object
{
public:
	Block(int PosX,int PosY,int Life,int Gh);
	~Block();

	void update(float Deltatime)override;
	void render(float Deltatime)override;

private:

	int breakLife = 0;

	int gh = 0;



};
