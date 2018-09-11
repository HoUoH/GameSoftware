#include "stdafx.h"
#include "Object.h"


Object::Object()
{
}


Object::~Object()
{
}

void Object::GetPosition(float * x, float * y)
{
	*x = m_PosX;
	*y = m_PosY;
}

void Object::SetPosition(float x, float y)
{
	m_PosX = x;
	m_PosY = y;
}

void Object::GetSize(float * width, float * height)
{
	*width = m_SizeWidth;
	*height = m_SizeHeight;
}

void Object::SetSize(float width, float height)
{
	m_SizeWidth = width;
	m_SizeHeight = height;
}
