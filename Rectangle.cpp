#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <iostream>

#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 600
float frameBuffer[WINDOW_HEIGHT][WINDOW_WIDTH][3];
bool mask[WINDOW_HEIGHT][WINDOW_WIDTH];

GLFWwindow *window;

void displayRectangle()
{
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);

    glVertex2i(100, 100); //topLeft
    glVertex2i(800, 100); //topRight
    glVertex2i(800, 500); //bottomRight
    glVertex2i(100, 500); //bottomLeft
    glEnd();
    glFlush();
}

void CharacterCallback(GLFWwindow* lWindow, unsigned int key)
{
    if(char(key) == 'r')
        displayRectangle();
}

void Init()
{
    glfwInit();
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "- <xx>", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSetCharCallback(window, CharacterCallback);
    glewExperimental = GL_TRUE;
    glewInit();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    //ClearFrameBuffer();
}

int main()
{
    Init();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, (GLdouble)WINDOW_WIDTH, (GLdouble)WINDOW_HEIGHT, 0.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);

    while (glfwWindowShouldClose(window) == 0)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        displayRectangle();
        glFlush();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}