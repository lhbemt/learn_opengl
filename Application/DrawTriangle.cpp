#include "DrawTriangle.h"

void DrawTriangle::initBuffer()
{
	glGenBuffers(1, &vbo); // 生成一个顶点缓冲对象 vbo 缓冲对象类型有很多 下一步设置为array类型
	glGenVertexArrays(1, &vao); // 生成一个vao 用来保存顶点属性解释 我们一个程序可以有很多vao 代表不同的顶点属性解释方法 只需要绑定到相应的顶点上就可以对buffer做正确的解释
	glBindVertexArray(vao); // 表示我们的程序的顶点属性应该按照它来解释 就是上面的glVertexAttribPointer这行。
	glBindBuffer(GL_ARRAY_BUFFER, vbo); // 设置这个缓冲对象的类型是array
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // 为缓冲区写入数据 复制数据到缓冲区内
	//GL_STATIC_DRAW 表示数据不会改变 GL_DYNAMIC_DRAW数据会改变很多 GL_STREAM_DRAW 数据每次绘制的时候都会改变
	// 设置顶点属性指针 第一个参数0对应顶点shader着色器的layout(location=0) 表示我们希望把数据传递到这个这一个顶点属性中
	// 第二个参数是顶点属性大小，我们的in是vec3，所以是3
	// 第三个参数是数据类型，我们的是float
	// 第4个参数是是否希望被标准化，标准化后所有数据是-1到1之间的，而我们的不是，我们希望在vertex着色器去标准化。所以是false
	// 第5个参数是步长，因为我们是vec3，所以是3个float。
	// 第6个参数是数据在缓冲中的起始偏移量。由于位置数据在数组的开头，所以我们这里设置为0
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); // 定义opengl如何解释顶点数据
	glEnableVertexAttribArray(0); // 这两步是定义opengl如何解释顶点数据

	glBindVertexArray(0); // 还原回系统默认值 因为数据已经在上面绑定到了唯一id vao上了
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); // 还原回系统默认值 因为数据已经绑定到唯一id vbo上了
}

void DrawTriangle::drawGraph() // 绘制三角形
{
	// 使用该程序
	glUseProgram(sharedProgram);
	glBindVertexArray(vao); // 使用该vao配置
	glDrawArrays(GL_TRIANGLES, 0, 3); // 画三角形 起始索引是0， 使用3个顶点
}
