#ifndef APPLICATION_H
#define APPLICATION_H
#include <vector>
#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include "headers/vertex.h"
#include "headers/shader.h"
#include "headers/camera.h"
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Application
{
public:
    Application(unsigned int width, unsigned int height, std::string name);
    ~Application();

    void addVertices(const std::vector<Vertex> & vertices);
    void render();
    void loop();

private:
    bool m_running;
    unsigned int m_width;
    unsigned int m_height;
    std::string m_name;
    sf::Window m_window;
    sf::ContextSettings m_settings;
    std::vector<Vertex> m_vertices;

};

#endif // APPLICATION_H
