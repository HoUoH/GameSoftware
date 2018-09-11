#pragma once
class Object
{
public:
	Object();
	~Object();
	
	void GetPosition(float * x, float * y);	// 주소를 넘겨서, 메모리 주소에 바로 값을 쓸 수 있도록.
	void SetPosition(float x, float y);
	void GetSize(float * width, float * height);
	void SetSize(float width, float height);
private:
	float m_PosX;
	float m_PosY;
	float m_SizeWidth;
	float m_SizeHeight;

	
};

