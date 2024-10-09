#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdio>

int main() {
    int hres = glfwInit();  //Initialize GLFW toolkit

    if(hres != 1) {
        printf("Failed to init GLFW");
    }else {
        printf("GLFW initialized");
    }

    auto window = glfwCreateWindow(640, 480, "Triangle", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    if(glewInit() != GLEW_OK) {
        printf("Failed to init GLEW");
        glfwTerminate();
        return -1;
    }



    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    glfwTerminate();
    return 0;
}
