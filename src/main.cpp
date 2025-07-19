#include <iostream>
#include <string>
#include <string_view>
#include <cstdlib>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void log_error(std::string_view);

namespace constants {
    constexpr int width = 640;
    constexpr int height = 480;
};

int main(void) {
    // load glfw
    if (!glfwInit()) {
        log_error("GLFW failed to initialize");
        return EXIT_FAILURE;
    }

    // create a window
    GLFWwindow* window = glfwCreateWindow(
            constants::width, constants::height, "test window", NULL, NULL);
    if (!window) {
        log_error("GLFW was unable to create a window");
        glfwTerminate();
        return EXIT_FAILURE;
    }
    glfwMakeContextCurrent(window);

    // load glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        log_error("GLAD failed to initialize");
        return EXIT_FAILURE;
    }

    // --- MAIN LOOP ---
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
