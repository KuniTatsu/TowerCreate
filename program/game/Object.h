#pragma once
#include"../dxlib_ext/dxlib_ext.h"
#include"GameManager.h"
#include<memory>

class GameManager;

class Object
{
public:
	Object();
	virtual ~Object() {};

	virtual void update(float Deltatime) {};
	virtual void render(float Deltatime) {};

	inline int GetPriority() {
		return priority;
	}
protected:
	GameManager* gManager = nullptr;


	tnl::Vector3 myPos;

	bool isAlive = true;

	enum class Priorities :uint32_t {
		BACKGROUND,
		BLOCK,
		PLAYER,
		EFFECT
	};

	int priority = 0;


};
