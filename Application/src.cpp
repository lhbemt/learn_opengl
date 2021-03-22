#include <glad/glad.h>
#include <GLFW/glfw3.h> // 只是处理各个平台上的窗口创建
#include <iostream>
#include "DrawTriangle.h"
#include "DrawRectangle.h"

// 回调函数  当我们窗口 大小发生变化的时候，视口大小也要跟着变化
void frameBufferSizeCallBack(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

// 处理输入事件
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true); // 按下esc 关闭窗口
	}
}

int main(void)
{
	glfwInit(); // 初始化
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 设置版本为3.3 并且 设置为可编程模式 即corefile

	// 创建绘制的窗口 800*600
	GLFWwindow* glfwWindow = glfwCreateWindow(800, 600, "Render Window", NULL, NULL);

	glfwMakeContextCurrent(glfwWindow);  // 将我们窗口的context上下文设置为当前线程的context上下文

	//glViewport(0, 0, 800, 600);  // 设置视口大小

	glfwSetFramebufferSizeCallback(glfwWindow, frameBufferSizeCallBack); // 为窗口注册回调函数 当窗口大小发生改变的时候 视口也应当发生变化
	
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress); //  加载opengl函数指针地址

//	static DrawTriangle triangle;
//	triangle.init();
	
	static DrawRectangle rectangle;
	rectangle.init();

	// 渲染循环 只要窗口没关闭 就一直绘制 这里相当于一帧的循环 或者说是tick
	while (!glfwWindowShouldClose(glfwWindow))
	{ // 一般是这三步 1处理输入 2渲染指令 3最终绘制
		// 处理输入
		processInput(glfwWindow);

		// 渲染指令
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);

//		triangle.drawGraph(); // 画有颜色的三角形
		rectangle.drawGraph(); // 画矩形

		// 最后的处理 交换缓冲等
		glfwSwapBuffers(glfwWindow); // 双缓冲机制 如果是单缓冲的话，意味着在渲染的过程中就显示画面，这样会导致闪烁，而双缓冲机制，是前缓存是当前显示的图形
		// 而另一个缓存是在渲染绘制接下来的图形，一旦绘制完成，就交换缓存，就不会有突然显示出来的过程，没有闪烁，此时前面的缓存就是后缓存了。

		glfwPollEvents(); // 检查窗口事件 如鼠标移动和键盘输入。更新窗口状态
	}

	glfwTerminate(); // 释放资源

	return 0;
}