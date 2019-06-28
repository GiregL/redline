#include <iostream>
#include <GL/glew.h>
#include <SFML/Window.hpp>
#include "application.h"
#include "vertex.h"

int main()
{
    Application app {1080, 720, "WINDOW::BORDEL"};
    if (glewInit() != GLEW_OK)
    {
        std::cerr << "ERROR::GLEW::FAILED_TO_INITIALIZE" << std::endl;
        std::exit(1);
    }
    //const std::vector<Vertex> vertices {
    //    Vertex {-0.5, -0.5, 0.0, 1.0, 0.0, 0.0},
    //    Vertex {0.5, -0.5, 0.0, 0.0, 1.0, 0.0},
    //    Vertex {0.0, 0.5, 0.0, 0.0, 0.0, 1.0},
    //};
    //app.addVertices(vertices);
    app.loop();
    return 0;
}
