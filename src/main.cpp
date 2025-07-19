#include <iostream>
#include <string>
#include <string_view>
#include <cstdlib>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void log_error(std::string_view);

int main(void) {
    if (!glfwInit()) {
        log_error("GLFW failed to initialize");
        return EXIT_FAILURE;
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "test window", NULL, NULL);
    if (!window) {
        log_error("GLFW was unable to create a window");
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        log_error("Failed to initialize GLAD");
        return EXIT_FAILURE;
    }

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return EXIT_SUCCESS;
}

void log_error(std::string_view sv) {
    std::cerr << sv << "\n";
}
