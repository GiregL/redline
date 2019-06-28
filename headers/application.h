#ifndef APPLICATION_H
#define APPLICATION_H
#include <vector>
#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include "vertex.h"
#include "shader.h"

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
