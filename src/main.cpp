#include <iostream>
#include <string>
#include <string_view>
#include <cstdlib>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

GLFWwindow* initialize_render_window();
void report_error(std::string_view);

namespace constants {
    constexpr int width = 640;
    constexpr int height = 480;
};

int main(void) {
    GLFWwindow* window = initialize_render_window();
    if (!window) return EXIT_FAILURE;

    // --- MAIN LOOP ---
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return EXIT_SUCCESS;
}


GLFWwindow* initialize_render_window() {
    bool success = true;

    // load glfw
    if (!glfwInit()) {
        report_error("GLFW failed to initialize");
        success = false;
    }

    // create a window
    GLFWwindow* window = glfwCreateWindow(
            constants::width, constants::height, "test window", NULL, NULL);

    if (!window) {
        report_error("GLFW was unable to create a window");
        glfwTerminate();
        success = false;
    }

    glfwMakeContextCurrent(window);

    // load glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        report_error("GLAD failed to initialize");
        success = false;
    }
  
    if (success) {
        return window;
    }
    return nullptr;
}

void report_error(std::string_view sv) {
    std::cerr << sv << "\n";
}
