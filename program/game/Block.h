//�C���Q�[���Œu�����u���b�N���̃N���X
//�u���b�N���Ƃɔj�󂷂邽�߂̗̑͂Ɖ摜�n���h��������

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
