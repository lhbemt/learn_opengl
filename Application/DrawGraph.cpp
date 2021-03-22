#include "DrawGraph.h"
#include  <iostream>

DrawGraph::DrawGraph()
{
}

// ���shader�����Ƿ������ȷ
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

// ���program�Ƿ�������ȷ
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
	// ����������ɫ������ Ҳ�Ƿ���һ��Ψһ������
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderStr, NULL); // ������ɫ��Դ����
	glCompileShader(vertexShader); // ������ɫ��
	if (!testShader(vertexShader)) // ������ɫ������
		return false;

	// ����Ƭ����ɫ��
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderStr, NULL);
	glCompileShader(fragmentShader);
	if (!testShader(fragmentShader))
		return false;

	// ����������Ҫ����������ɫ����������
	sharedProgram = glCreateProgram();
	glAttachShader(sharedProgram, vertexShader);
	glAttachShader(sharedProgram, fragmentShader); // ���Ű���������ɫ���ͳ����������
	glLinkProgram(sharedProgram); // ���ž����Ӹó��򼴿ɡ�
	if (!testProgram(sharedProgram))
		return false;

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	return true;
}
