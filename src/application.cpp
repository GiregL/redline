#include "headers/application.h"

Application::Application(unsigned int width,
                         unsigned int height,
                         std::string name)
    : m_running {true}
    , m_width {width}
    , m_height {height}
    , m_name {name}
    , m_window {}
    , m_settings {}
{
    m_settings.depthBits = 24;
    m_settings.stencilBits = 8;
    m_settings.antialiasingLevel = 4;
    m_settings.majorVersion = 3;
    m_settings.minorVersion = 3;
    m_settings.attributeFlags = sf::ContextSettings::Core;

    m_window.create(sf::VideoMode{m_width, m_height},
                    m_name,
                    sf::Style::Close,
                    m_settings);

    m_window.setVerticalSyncEnabled(true);
    m_window.setActive(true);
}

void Application::loop()
{
    std::vector<Vertex> vert {
        Vertex {-0.5, -0.5, 0.0, Color {1.0, 0.0, 0.0}},
        Vertex {0.5, -0.5, 0.0, Color{0.0, 1.0, 0.0}},
        Vertex {0.0, 0.5, 0.0, Color {0.0, 0.0, 1.0}}
    };

    std::vector<double> vertices {};
    vertices.reserve(6 * vert.size());

    auto it = std::begin(vert);
    while (it != std::end(vert))
    {
        vertices.push_back(it->m_x);
        vertices.push_back(it->m_y);
        vertices.push_back(it->m_z);
        vertices.push_back(it->m_color.m_r);
        vertices.push_back(it->m_color.m_g);
        vertices.push_back(it->m_color.m_b);
        it++;
    }

    Shader shader {"shaders/vertex.glsl", "shaders/fragment.glsl"};

    unsigned int vbo, vao;
    glGenBuffers(1, &vbo);
    glGenVertexArrays(1, &vao);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(double), vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 6 * sizeof(double), nullptr);
    glVertexAttribPointer(1, 3, GL_DOUBLE, GL_FALSE, 6 * sizeof(double), reinterpret_cast<void *>(3 * sizeof(double)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    Camera camera {0, 0, 0, 0, 0, 0};

    while (m_running)
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_running = false;
            }
            camera.renderUpdate(event);
        }
        // Rendering
        camera.applyUpdates();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        shader.use();
        camera.sendMatrix("model_matrix", shader);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        m_window.display();
    }
}

void Application::render()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Application::addVertices(const std::vector<Vertex> & vertices)
{
    auto it {std::begin(vertices)};
    while (it != std::end(vertices))
    {
        m_vertices.push_back(*it);
        it++;
    }
}

Application::~Application()
{
    m_window.close();
    m_vertices.clear();
}
