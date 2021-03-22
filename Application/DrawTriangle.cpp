#include "DrawTriangle.h"

void DrawTriangle::initBuffer()
{
	glGenBuffers(1, &vbo); // ����һ�����㻺����� vbo ������������кܶ� ��һ������Ϊarray����
	glGenVertexArrays(1, &vao); // ����һ��vao �������涥�����Խ��� ����һ����������кܶ�vao ����ͬ�Ķ������Խ��ͷ��� ֻ��Ҫ�󶨵���Ӧ�Ķ����ϾͿ��Զ�buffer����ȷ�Ľ���
	glBindVertexArray(vao); // ��ʾ���ǵĳ���Ķ�������Ӧ�ð����������� ���������glVertexAttribPointer���С�
	glBindBuffer(GL_ARRAY_BUFFER, vbo); // ���������������������array
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // Ϊ������д������ �������ݵ���������
	//GL_STATIC_DRAW ��ʾ���ݲ���ı� GL_DYNAMIC_DRAW���ݻ�ı�ܶ� GL_STREAM_DRAW ����ÿ�λ��Ƶ�ʱ�򶼻�ı�
	// ���ö�������ָ�� ��һ������0��Ӧ����shader��ɫ����layout(location=0) ��ʾ����ϣ�������ݴ��ݵ������һ������������
	// �ڶ��������Ƕ������Դ�С�����ǵ�in��vec3��������3
	// �������������������ͣ����ǵ���float
	// ��4���������Ƿ�ϣ������׼������׼��������������-1��1֮��ģ������ǵĲ��ǣ�����ϣ����vertex��ɫ��ȥ��׼����������false
	// ��5�������ǲ�������Ϊ������vec3��������3��float��
	// ��6�������������ڻ����е���ʼƫ����������λ������������Ŀ�ͷ������������������Ϊ0
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); // ����opengl��ν��Ͷ�������
	glEnableVertexAttribArray(0); // �������Ƕ���opengl��ν��Ͷ�������

	glBindVertexArray(0); // ��ԭ��ϵͳĬ��ֵ ��Ϊ�����Ѿ�������󶨵���Ψһid vao����
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); // ��ԭ��ϵͳĬ��ֵ ��Ϊ�����Ѿ��󶨵�Ψһid vbo����
}

void DrawTriangle::drawGraph() // ����������
{
	// ʹ�øó���
	glUseProgram(sharedProgram);
	glBindVertexArray(vao); // ʹ�ø�vao����
	glDrawArrays(GL_TRIANGLES, 0, 3); // �������� ��ʼ������0�� ʹ��3������
}
