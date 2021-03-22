#include "DrawGraph.h"
#include  <iostream>

DrawGraph::DrawGraph()
{
}

// 检测shader代码是否编译正确
bool DrawGraph::testShader(unsigned int shader)
{
	int success;
	char info[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, info);
		std::cout << "shader compile failed: " << info << std::endl;
		return false;
	}
	return true;
}

// 检测program是否链接正确
bool DrawGraph::testProgram(unsigned int program)
{
	int success;
	char info[512];
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(program, 512, NULL, info);
		std::cout << "program link failed: " << info << std::endl;
		return false;
	}
	return true;
}

bool DrawGraph::initShaders()
{
	// 创建顶点着色器对象 也是返回一个唯一的引用
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderStr, NULL); // 设置着色器源代码
	glCompileShader(vertexShader); // 编译着色器
	if (!testShader(vertexShader)) // 顶点着色器错误
		return false;

	// 创建片段着色器
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderStr, NULL);
	glCompileShader(fragmentShader);
	if (!testShader(fragmentShader))
		return false;

	// 接着我们需要将这两个着色器链接起来
	sharedProgram = glCreateProgram();
	glAttachShader(sharedProgram, vertexShader);
	glAttachShader(sharedProgram, fragmentShader); // 接着把这两个着色器和程序关联起来
	glLinkProgram(sharedProgram); // 接着就链接该程序即可。
	if (!testProgram(sharedProgram))
		return false;

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	return true;
}
