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
	// 定义顶点数据 把它作为输入发送给顶点着色器
	float vertices[9] = { // 这里是三角形的3个点的坐标，因为绘制的是二维的，所以z轴是0 z轴也是所谓的深度 比如被遮挡了，就是z轴在之后，这个在渲染中是会被丢弃的
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f , 0.0f,
		0.0f, 0.5f, 0.0f
	};
};

