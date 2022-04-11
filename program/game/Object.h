#pragma once
#include"../dxlib_ext/dxlib_ext.h"

class Object
{
public:
	Object(){};
	virtual ~Object() {};

	virtual void update(float deltatime) {}
	virtual void render(float deltatime) {}

protected:
	tnl::Vector3 pos_;
	
	bool is_alive_ = true;

};
