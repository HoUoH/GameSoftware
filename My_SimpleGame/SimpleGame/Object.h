#pragma once
class Object
{
public:
	Object();
	~Object();
	
	void GetPosition(float * x, float * y);	// �ּҸ� �Ѱܼ�, �޸� �ּҿ� �ٷ� ���� �� �� �ֵ���.
	void SetPosition(float x, float y);
	void GetSize(float * width, float * height);
	void SetSize(float width, float height);
private:
	float m_PosX;
	float m_PosY;
	float m_SizeWidth;
	float m_SizeHeight;

	
};

