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

	float vertices[12] = { // 矩形的4个顶点
		0.5f, 0.5f, 0.0f, // 右上角
		0.5f, -0.5f, 0.0f, // 右下角
		-0.5f, -0.5f, 0.0f, // 左下角
		-0.5f, 0.5f, 0.0f // 左上角
	};

	unsigned int indeices[6] = { // 矩形是由三角形组成的，opengl不会绘制矩形，但是会绘制三角形 所以矩形由2个三角形组成
		0, 1, 3, // 使用vects的哪几个点 组成第一个三角形
		1, 2, 3 // 组成第二个三角形
	};
};

