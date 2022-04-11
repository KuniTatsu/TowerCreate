#include "Player.h"
#include"DxLib.h"

Player::Player()
{
	gManager = GameManager::Instance();
	LoadDivGraph("graphics/Character_1.png", 12, 3, 4, 32, 32, playerGh);
	myPos.x = 512;
	myPos.y = 350;
	priority = static_cast<uint32_t>(Priorities::PLAYER);
}

Player::~Player()
{
}

void Player::update(float Deltatime)
{
}

void Player::render(float Deltatime)
{
	//gManager->DrawRotaGraphNormal(myPos.x, myPos.y, playerGh, true);
	Draw();
}

void Player::Move()
{
	if (tnl::Input::IsKeyDown(eKeys::KB_LEFT)) {
		myPos.x -= 2;
		mydir = dir::LEFT;
	}
	else if (tnl::Input::IsKeyDown(eKeys::KB_RIGHT)) {
		myPos.x += 2;
		mydir = dir::RIGHT;
	}
	else if (tnl::Input::IsKeyDown(eKeys::KB_UP)) {
		myPos.y -= 2;
		mydir = dir::UP;
	}
	else if (tnl::Input::IsKeyDown(eKeys::KB_DOWN)) {
		myPos.y += 2;
		mydir = dir::DOWN;
	}
}

void Player::Draw()
{
	Anim(playerGh, actSpeed, maxMotionIndex, drawGh);
	//描画座標+アニメーション位置補正(補完座標)-カメラ補正
	DrawRotaGraph(myPos.x - gManager->GetCameraPos().x, myPos.y - gManager->GetCameraPos().y, 1, 0, drawGh, true);
}

void Player::Anim(int* DrawGhArr, int Speed, int MaxIndex, int& DrawGh)
{
	if (--actWait <= 0) {
		actIndex++;
		actWait = Speed;
		actIndex %= MaxIndex;
	}
	DrawGh = DrawGhArr[actIndex + 3 * mydir];
}