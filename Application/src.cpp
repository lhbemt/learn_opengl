#include <glad/glad.h>
#include <GLFW/glfw3.h> // ֻ�Ǵ������ƽ̨�ϵĴ��ڴ���
#include <iostream>
#include "DrawTriangle.h"
#include "DrawRectangle.h"

// �ص�����  �����Ǵ��� ��С�����仯��ʱ���ӿڴ�СҲҪ���ű仯
void frameBufferSizeCallBack(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

// ���������¼�
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true); // ����esc �رմ���
	}
}

int main(void)
{
	glfwInit(); // ��ʼ��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // ���ð汾Ϊ3.3 ���� ����Ϊ�ɱ��ģʽ ��corefile

	// �������ƵĴ��� 800*600
	GLFWwindow* glfwWindow = glfwCreateWindow(800, 600, "Render Window", NULL, NULL);

	glfwMakeContextCurrent(glfwWindow);  // �����Ǵ��ڵ�context����������Ϊ��ǰ�̵߳�context������

	//glViewport(0, 0, 800, 600);  // �����ӿڴ�С

	glfwSetFramebufferSizeCallback(glfwWindow, frameBufferSizeCallBack); // Ϊ����ע��ص����� �����ڴ�С�����ı��ʱ�� �ӿ�ҲӦ�������仯
	
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress); //  ����opengl����ָ���ַ

//	static DrawTriangle triangle;
//	triangle.init();
	
	static DrawRectangle rectangle;
	rectangle.init();

	// ��Ⱦѭ�� ֻҪ����û�ر� ��һֱ���� �����൱��һ֡��ѭ�� ����˵��tick
	while (!glfwWindowShouldClose(glfwWindow))
	{ // һ���������� 1�������� 2��Ⱦָ�� 3���ջ���
		// ��������
		processInput(glfwWindow);

		// ��Ⱦָ��
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);

//		triangle.drawGraph(); // ������ɫ��������
		rectangle.drawGraph(); // ������

		// ���Ĵ��� ���������
		glfwSwapBuffers(glfwWindow); // ˫������� ����ǵ�����Ļ�����ζ������Ⱦ�Ĺ����о���ʾ���棬�����ᵼ����˸����˫������ƣ���ǰ�����ǵ�ǰ��ʾ��ͼ��
		// ����һ������������Ⱦ���ƽ�������ͼ�Σ�һ��������ɣ��ͽ������棬�Ͳ�����ͻȻ��ʾ�����Ĺ��̣�û����˸����ʱǰ��Ļ�����Ǻ󻺴��ˡ�

		glfwPollEvents(); // ��鴰���¼� ������ƶ��ͼ������롣���´���״̬
	}

	glfwTerminate(); // �ͷ���Դ

	return 0;
}