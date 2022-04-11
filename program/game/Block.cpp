#include "Block.h"


Block::Block(int PosX, int PosY, int Life, int Gh)
{
	myPos.x = PosX;
	myPos.y = PosY;

	breakLife = Life;
	gh = Gh;
	priority = static_cast<uint32_t>(Priorities::BLOCK);

}

Block::~Block()
{
}

void Block::update(float Deltatime)
{
}

void Block::render(float Deltatime)
{
	gManager->DrawRotaGraphNormal(myPos.x - gManager->GetCameraPos().x, myPos.y - gManager->GetCameraPos().y, gh, true);

}
