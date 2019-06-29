#include "camera.h"

Camera::Camera(float x, float y, float z
               , float rx, float ry, float rz)
    : m_modelview {1}
    , m_position {x, y, z}
    , m_rotation {0, rx, ry, rz}
    , m_moveSpeed {0.1f}
    , m_rotationSpeed { 0.01f }
{
    glm::mat4 perspective {glm::perspective(70.0f, (1080.0f / 720.0f), 0.1f, 1000.0f)};
    glm::mat4 view {glm::lookAt(glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f))};
    glm::mat4 translation {1};
    glm::mat4 model {glm::translate(translation, glm::vec3(0.0, 0.0, 5.0))};
    m_modelview = perspective * view * model;
}

void Camera::renderUpdate(sf::Event const & event)
{

    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::D)
            m_goRight = true;
        if (event.key.code == sf::Keyboard::Q)
            m_goLeft = true;
        if (event.key.code == sf::Keyboard::Z)
            m_goFront = true;
        if (event.key.code == sf::Keyboard::S)
            m_goBack = true;
        if (event.key.code == sf::Keyboard::Space)
            m_goUp = true;
        if (event.key.code == sf::Keyboard::LShift)
            m_goDown = true;
    }
    else if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::D)
            m_goRight = false;
        if (event.key.code == sf::Keyboard::Q)
            m_goLeft = false;
        if (event.key.code == sf::Keyboard::Z)
            m_goFront = false;
        if (event.key.code == sf::Keyboard::S)
            m_goBack = false;
        if (event.key.code == sf::Keyboard::Space)
            m_goUp = false;
        if (event.key.code == sf::Keyboard::LShift)
            m_goDown = false;
    }
}

void Camera::applyUpdates()
{
    if (m_goRight) m_modelview = glm::translate(m_modelview, glm::vec3(m_moveSpeed, 0.0f, 0.0f));
    if (m_goLeft) m_modelview = glm::translate(m_modelview, glm::vec3(-m_moveSpeed, 0.0f, 0.0f));
    if (m_goFront) m_modelview = glm::translate(m_modelview, glm::vec3(0.0f, 0.0f, -m_moveSpeed));
    if (m_goBack) m_modelview = glm::translate(m_modelview, glm::vec3(0.0f, 0.0f, m_moveSpeed));
    if (m_goUp) m_modelview = glm::translate(m_modelview, glm::vec3(0.0f, m_moveSpeed, 0.0f));
    if (m_goDown) m_modelview = glm::translate(m_modelview, glm::vec3(0.0f, -m_moveSpeed, 0.0f));
}

void Camera::sendMatrix(std::string const & name, Shader const & shader)
{
    shader.use();
    shader.setMatrix4f(name, m_modelview);
}
