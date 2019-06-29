#ifndef CAMERA_H
#define CAMERA_H
#include "headers/shader.h"
#include <SFML/Window.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:
    Camera(float x, float y, float z
           , float rx, float ry, float rz);
    void renderUpdate(sf::Event const & event);
    void sendMatrix(std::string const & name, Shader const & shader);
    void applyUpdates();

private:
    glm::mat4x4 m_modelview;
    glm::vec3 m_position;
    glm::quat m_rotation;

    bool m_goUp;
    bool m_goDown;
    bool m_goLeft;
    bool m_goRight;
    bool m_goBack;
    bool m_goFront;

    float m_moveSpeed;
    float m_rotationSpeed;
};

#endif // CAMERA_H
