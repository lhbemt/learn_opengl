#pragma once
#include "DrawGraph.h"

class DrawTriangle : public DrawGraph
{
public:
	DrawTriangle()
	{
	}

	virtual void drawGraph() override;

	~DrawTriangle()
	{
	}

	virtual void initBuffer() override;

private:
	// ���嶥������ ������Ϊ���뷢�͸�������ɫ��
	float vertices[9] = { // �����������ε�3��������꣬��Ϊ���Ƶ��Ƕ�ά�ģ�����z����0 z��Ҳ����ν����� ���类�ڵ��ˣ�����z����֮���������Ⱦ���ǻᱻ������
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f , 0.0f,
		0.0f, 0.5f, 0.0f
	};
};

