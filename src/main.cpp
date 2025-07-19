#include <iostream>
#include <string>
#include <string_view>
#include <cstdlib>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

GLFWwindow* initialize_render_window();
void report_error(std::string_view);

namespace constants {
    constexpr int WIDTH = 640;
    constexpr int HEIGHT = 480;
    constexpr int POSITION_COMPONENTS = 3;
};

int main(void) {
    GLFWwindow* window = initialize_render_window();
    if (!window) return EXIT_FAILURE;

    // --- setting up buffers ---
    float triangle_vertices[] = {
        0.0f,  0.5f, 0.0f,      // top
        -0.5f, -0.5f, 0.0f,     // bottom left
        0.5f, -0.5f, 0.0f       // bottom right
    };

    // set up vertex array object
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glVertexAttribPointer(
            0,
            constants::POSITION_COMPONENTS,
            GL_FLOAT,
            GL_FALSE,
            constants::POSITION_COMPONENTS * sizeof(float),
            nullptr);
    glEnableVertexAttribArray(0);

    // set up vertex buffer object
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(
            GL_ARRAY_BUFFER,
            sizeof(triangle_vertices),
            triangle_vertices,
            GL_STATIC_DRAW);
    // --- end of setting up  ---

    // --- MAIN LOOP ---
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // TODO: render here
        // ...

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
