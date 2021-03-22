#include "DrawRectangle.h"



DrawRectangle::DrawRectangle()
{
}


DrawRectangle::~DrawRectangle()
{
}

void DrawRectangle::initBuffer()
{
	glGenVertexArrays(1, &vao); // ����vao
	glGenBuffers(1, &vbo); // ����vbo
	glGenBuffers(1, &ebo); // ����ebo ������������
	glBindVertexArray(vao); // ��vao
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // ���ƶ�������
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);  // �󶨵���ǰ
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indeices), indeices, GL_STATIC_DRAW); // �����������ݽ�ȥ
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); // ��������������������
	glEnableVertexAttribArray(0); // ����

	glBindVertexArray(0); // ��ԭ��ϵͳĬ��ֵ ��Ϊ�����Ѿ�������󶨵���Ψһid vao����
	glBindBuffer(GL_ARRAY_BUFFER, 0); // ��ԭ��ϵͳĬ��ֵ �����Ѱ�
	// ע�������ebo���ܻ�ԭ��ϵͳĬ��ֵ
}

void DrawRectangle::drawGraph()
{
	glUseProgram(sharedProgram);
	glBindVertexArray(vao); // ʹ��vao�Ǹ��������ԣ���������
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); // ��6���� ���2��������
}
