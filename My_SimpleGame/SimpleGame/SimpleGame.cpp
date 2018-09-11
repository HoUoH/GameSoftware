/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"
#include <iostream>
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"

#include "Renderer.h"
#include "Object.h"

#include <math.h>

Renderer *g_Renderer = NULL;
Object *g_TestObj = NULL;


// �Լ��� ����, ����������, �޸𸮿� ������ �ȴ�.
// global ����
float g_Time = 0;
float g_X = 0;
float g_Y = 0;


void RenderScene(void)
{
	/// �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
	/// �ڡڡڡڡڡڡڡڡڡ� �׸��� -> ���� -> ����� -> �׸��� -> ���� -> ����� �ڡڡڡڡڡڡڡڡڡ�
	/// �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		/// ������ �� �׷ȴ� ���� �����.
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);	// RGBA�� 0, 0.3, 0.3 1.0�� ���� clear�ϰ� �ִ�.
	

	//float x = sin(g_Time) * 200.f;
	//float y = cos(g_Time) * 200.f;
	
	g_Time += 0.001f;	/// ��ǥ�� �����δ�.

	float x, y;
	g_TestObj->GetPosition(&x, &y);
	x = g_X;
	y = g_Y;
	
	float width, height;
	g_TestObj->GetSize(&width, &height);


	// Renderer Test
	g_Renderer->DrawSolidRect(x, y, 0, width, 1, 0, 1, 1); // 1, 0, 1, 1�� ��ġ�� �׸� ����

	glutSwapBuffers();	// Buffer�� Swap�Ѵ�.
}

void Idle(void)
{
	RenderScene();
}

void MouseInput(int button, int state, int x, int y)
{
	RenderScene();
}

void KeyInput(unsigned char key, int x, int y)		// (���� Ű�� ���ڰ�, ��ǥ��)
// Ű���� ������ ���� �۵��Ѵ�.
{
	float amount = 5.f;
	/*
	if(key == 'w')
	{
		std::cout << "w";
	}
	*/
	// ---------------------------------
	// ���ӵ��� �ַ��� ��� �ؾ��ұ�?
	// ---------------------------------



	if (key == 'w')
	{
		std::cout << 'w';
		g_Y += amount;
	}
	if (key == 'a')
	{
		std::cout << 'a';
		g_X -= amount;
	}
	if (key == 's')
	{
		std::cout << 's';
		g_Y -= amount;
	}
	if (key == 'd')
	{
		std::cout << 'd';
		g_X += amount;
	}



	RenderScene();
}

void SpecialKeyInput(int key, int x, int y)
{
	RenderScene();
}

int main(int argc, char **argv)
{
	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Game Software Engineering KPU");

	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		std::cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		std::cout << "GLEW 3.0 not supported\n ";
	}

	// Initialize Renderer
	g_Renderer = new Renderer(500, 500);
	if (!g_Renderer->IsInitialized())
	{
		std::cout << "Renderer could not be initialized.. \n";
	}

	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);

	// Initialize
	g_TestObj = new Object();
	g_TestObj->SetPosition(0.f, 0.f);
	g_TestObj->SetSize(20.f, 20.f);

	glutMainLoop();

	delete g_Renderer;

    return 0;
}

