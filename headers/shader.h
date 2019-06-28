#ifndef SHADER_H
#define SHADER_H
#include <string>
#include <GL/glew.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/mat4x4.hpp>
#include <glm/common.hpp>
#include <glm/gtc/type_ptr.hpp>

/**
 * @brief The Shader class
 * Used to include shaders in your application
 */
class Shader
{
public:
    /**
     * @brief Shader constructor
     * @param vertexPath path to the vertex shader
     * @param fragmentPath path to the fragment shader
     */
    Shader(const GLchar * vertexPath,
           const GLchar * fragmentPath);

    /**
     * @brief create creates the shaders
     */
    void create();

    /**
     * @brief use use the shader
     */
    void use();

    /**
     * @brief setBool sets a shader variable value
     * @param name name of the shader variable
     * @param val new value
     */
    void setBool(std::string const & name, bool val) const;

    /**
     * @brief setInt sets a shader variable value
     * @param name name of the shader variable
     * @param val new value
     */
    void setInt(std::string const & name, int val) const;

    /**
     * @brief setFloat sets a shader variable value
     * @param name name of the shader variable
     * @param val new value
     */
    void setFloat(std::string const & name, float val) const;

    /**
     * @brief setMatrix4f sets a shader matrix value
     * @param name name of the shader variable
     * @param val new value
     */
    void setMatrix4f(std::string const & name, glm::mat4x4 & val) const;

private:
    unsigned int m_id;
    const GLchar * m_vpath;
    const GLchar * m_fpath;
};

#endif // SHADER_H
