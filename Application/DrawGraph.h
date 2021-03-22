#pragma once
#include <glad/glad.h>
// ����ͼ�λ���

// ���������� �漰֪ʶ VAO VBO IBO
// VAO�������������
// VBO�����㻺�����
// IBO�������������

class DrawGraph
{
public:
	DrawGraph();
	virtual ~DrawGraph() // �̳еĻ�����麯��Ҫ����Ϊ������ ����delete����ָ���ʱ�������������������ִ�� ������������������ͷ���Դ �ǻ������Դй¶
	{ // �ͷ���Դ
		glDeleteBuffers(1, &vbo);
		glDeleteVertexArrays(1, &vao);
		glDeleteProgram(sharedProgram);
	}

	virtual void initBuffer() = 0; // ���ö������Ժ�buffer

	virtual void init()
	{
		initBuffer(); // ���ö������Ժ�buffer
		initShaders(); // ����shader
	}

	// ���shader�����Ƿ������ȷ
	static bool testShader(unsigned int shader);
	// ���program�Ƿ�������ȷ
	static bool testProgram(unsigned int program);

	virtual void drawGraph() = 0;

protected:
	bool initShaders();

protected:
	// glsl���� ������ɫ�� ����330�汾��glsl����
// in��ʾ����������������
// ����vec3���������apos location=0�趨�����������λ��
// ��Ϊ���ǵĶ�����ɫ���ǰ�3d��������ת�������һ�׶��õģ��������Ǳ�����gl_Postion��Ϊ��� ����һ��vec4�����͡�����ʾ����λ������
// �����Ƕ�����ɫ�������
// ��Ϊͨ�����ǳ�������������ݶ����Ǳ�׼���豸����(����Χ��-1f��1.0f)���������Ƕ�����ɫ����һ��ͨ���ǽ�����ת��Ϊ��׼�豸���꣬����������
// opengl�Ŀ��ӻ������ڡ�
	const char* vertexShaderStr = "#version 330 core\n"
		"layout(location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\n";

	// Ƭ����ɫ��ֻ��Ҫһ������� ��ʾ�������ص���ɫ ����������һ��out
	const char* fragmentShaderStr = "#version 330 core\n"
		"out vec4 fragColor;\n"
		"void main()\n"
		"{\n"
		"	fragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);"
		"}\n";


	unsigned int vbo; // ���㻺�����id ʹ��opengl���ɵ�id��Ψһ��
	unsigned int vao; // ����һ���洢�������Խ��͵Ļ�����id�� idҲ��Ψһ��
	unsigned int ebo; // ���������Ļ���������id

	unsigned int vertexShader; // ������ɫ������ ������ת��Ϊopengl��׼���豸����� ��ֵ�ô�Сʱ(-1.0��1.0)
	unsigned int fragmentShader; // Ƭ����ɫ�� ��������������������ɫ�����
	unsigned int sharedProgram; // ���Ӷ�����ɫ����Ƭ����ɫ���ĳ��� Ҳ��Ψһid

};

