#include "Camera.h"


Camera::Camera()
{
	pos.x = 0;
	pos.y = 0;
}

Camera::~Camera()
{
}

void Camera::Move()
{
	if (tnl::Input::IsKeyDown(eKeys::KB_LEFT)) {
		pos.x -= 2;
	}
	else if (tnl::Input::IsKeyDown(eKeys::KB_RIGHT)) {
		pos.x += 2;
	}
	else if (tnl::Input::IsKeyDown(eKeys::KB_UP)) {
		pos.y -= 2;
	}
	else if (tnl::Input::IsKeyDown(eKeys::KB_DOWN)) {
		pos.y += 2;
	}

}

tnl::Vector3& Camera::GetPos()
{
	return pos;
}
