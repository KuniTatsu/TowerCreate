#pragma once
#include"../dxlib_ext/dxlib_ext.h"

class Camera
{
public:
	Camera();
	~Camera();

	void Move();

	tnl::Vector3& GetPos();
private:
	tnl::Vector3 pos;

};
