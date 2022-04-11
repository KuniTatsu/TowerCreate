#include "Object.h"

Object::Object()
{
	gManager = GameManager::Instance();

	gManager->AddObjectList(this);
}
