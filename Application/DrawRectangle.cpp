#include "DrawRectangle.h"



DrawRectangle::DrawRectangle()
{
}


DrawRectangle::~DrawRectangle()
{
}

void DrawRectangle::initBuffer()
{
	glGenVertexArrays(1, &vao); // 生成vao
	glGenBuffers(1, &vbo); // 生成vbo
	glGenBuffers(1, &ebo); // 生成ebo 保存索引数据
	glBindVertexArray(vao); // 绑定vao
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // 复制顶点数据
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);  // 绑定到当前
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indeices), indeices, GL_STATIC_DRAW); // 复制索引数据进去
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); // 设置怎样解析顶点数据
	glEnableVertexAttribArray(0); // 启用

	glBindVertexArray(0); // 还原回系统默认值 因为数据已经在上面绑定到了唯一id vao上了
	glBindBuffer(GL_ARRAY_BUFFER, 0); // 还原回系统默认值 上面已绑定
	// 注意这里的ebo不能还原回系统默认值
}

void DrawRectangle::drawGraph()
{
	glUseProgram(sharedProgram);
	glBindVertexArray(vao); // 使用vao那个顶点属性，解释数据
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); // 画6个点 组成2个三角形
}
