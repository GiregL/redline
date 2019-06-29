#include "headers/camera.h"

Camera::Camera(float x, float y, float z
               , float rx, float ry, float rz)
    : m_viewmatrix {glm::lookAt(glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f))}
    , m_projection {glm::perspective(70.0f, (1080.0f / 720.0f), 0.1f, 1000.0f)}
    , m_position {x, y, z}
    , m_rotation {0, rx, ry, rz}
    , m_goUp {false}
    , m_goDown {false}
    , m_goLeft {false}
    , m_goRight {false}
    , m_goBack {false}
    , m_goFront {false}
    , m_moveSpeed {0.1f}
    , m_rotationSpeed { 0.01f }
{
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
    else if (event.type == sf::Event::MouseMoved)
    {
        float x {event.mouseMove.x * m_rotationSpeed};
        float y {event.mouseMove.y * m_rotationSpeed};


    }
}

void Camera::applyUpdates()
{
    if (m_goRight) m_position.x = m_moveSpeed;
    if (m_goLeft) m_position.x = -m_moveSpeed;
    if (m_goFront) m_position.z = -m_moveSpeed;
    if (m_goBack) m_position.z = m_moveSpeed;
    if (m_goUp) m_position.y = -m_moveSpeed;
    if (m_goDown) m_position.y = m_moveSpeed;

    m_viewmatrix = glm::translate(m_viewmatrix, m_position);
    m_position = glm::vec3 {0};
}

glm::mat4x4 Camera::sendMatrix()
{
    return m_projection * m_viewmatrix;
}
