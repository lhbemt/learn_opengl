#pragma once
#include <glad/glad.h>
// 绘制图形基类

// 绘制三角形 涉及知识 VAO VBO IBO
// VAO：顶点数组对象
// VBO：顶点缓冲对象
// IBO：索引缓冲对象

class DrawGraph
{
public:
	DrawGraph();
	virtual ~DrawGraph() // 继承的基类的虚函数要设置为析构的 否则delete父类指针的时候，子类的析构函数不会执行 如果子类析构函数是释放资源 那会出现资源泄露
	{ // 释放资源
		glDeleteBuffers(1, &vbo);
		glDeleteVertexArrays(1, &vao);
		glDeleteProgram(sharedProgram);
	}

	virtual void initBuffer() = 0; // 设置顶点属性和buffer

	virtual void init()
	{
		initBuffer(); // 设置顶点属性和buffer
		initShaders(); // 设置shader
	}

	// 检测shader代码是否编译正确
	static bool testShader(unsigned int shader);
	// 检测program是否链接正确
	static bool testProgram(unsigned int program);

	virtual void drawGraph() = 0;

protected:
	bool initShaders();

protected:
	// glsl语言 顶点着色器 定义330版本的glsl语言
// in表示顶点所有输入属性
// 创建vec3的输入变量apos location=0设定了输入变量的位置
// 因为我们的顶点着色器是把3d变量做了转换后给下一阶段用的，所以我们必须用gl_Postion作为输出 它是一个vec4的类型。它表示的是位置数据
// 它就是顶点着色器的输出
// 因为通常真是程序里输入的数据都不是标准化设备坐标(即范围是-1f到1.0f)，所以我们顶点着色器这一步通常是将输入转换为标准设备坐标，这样才能在
// opengl的可视化区域内。
	const char* vertexShaderStr = "#version 330 core\n"
		"layout(location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\n";

	// 片段着色器只需要一个输出量 表示最终像素的颜色 所以这里是一个out
	const char* fragmentShaderStr = "#version 330 core\n"
		"out vec4 fragColor;\n"
		"void main()\n"
		"{\n"
		"	fragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);"
		"}\n";


	unsigned int vbo; // 顶点缓冲对象id 使用opengl生成的id是唯一的
	unsigned int vao; // 这是一个存储顶点属性解释的缓冲区id， id也是唯一的
	unsigned int ebo; // 缓存索引的缓冲区对象id

	unsigned int vertexShader; // 顶点着色器对象 是用来转换为opengl标准化设备坐标的 即值得大小时(-1.0到1.0)
	unsigned int fragmentShader; // 片段着色器 是用来计算最后的像素颜色输出的
	unsigned int sharedProgram; // 链接顶点着色器和片段着色器的程序 也是唯一id

};

