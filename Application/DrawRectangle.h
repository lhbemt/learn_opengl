#pragma once
#include "DrawGraph.h"

class DrawRectangle : public DrawGraph
{
public:
	DrawRectangle();
	~DrawRectangle();

	virtual void initBuffer() override;
	virtual void drawGraph() override;

private:

	float vertices[12] = { // ���ε�4������
		0.5f, 0.5f, 0.0f, // ���Ͻ�
		0.5f, -0.5f, 0.0f, // ���½�
		-0.5f, -0.5f, 0.0f, // ���½�
		-0.5f, 0.5f, 0.0f // ���Ͻ�
	};

	unsigned int indeices[6] = { // ����������������ɵģ�opengl������ƾ��Σ����ǻ���������� ���Ծ�����2�����������
		0, 1, 3, // ʹ��vects���ļ����� ��ɵ�һ��������
		1, 2, 3 // ��ɵڶ���������
	};
};

