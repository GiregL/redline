#include "headers/shader.h"

Shader::Shader(const GLchar * vertexPath,
               const GLchar * fragmentPath)
    : m_vpath {vertexPath}
    , m_fpath {fragmentPath}
{
    std::string vertexCode;
    std::string fragmentCode;

    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try
    {
        // Open files
        vShaderFile.open(m_vpath);
        fShaderFile.open(m_fpath);

        // Create streams
        std::stringstream vShaderStream, fShaderStream;

        // Read buffers
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();

        // Close files
        vShaderFile.close();
        fShaderFile.close();

        // Convert stream to string
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (std::ifstream::failure e)
    {
        std::cerr << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ\n" << e.what() << std::endl;
    }
    catch (std::exception e)
    {
        std::cerr << "ERROR::EXCEPTION\n" << e.what() << std::endl;
    }

    std::cout << "DEBUG::SHADER::SUCCESS_READ_FILES" << std::endl;

    const char * vShaderCode = vertexCode.c_str();
    const char * fShaderCode = fragmentCode.c_str();

    // Compile shaders
    unsigned int vertex, fragment;
    int success;
    char infoLog[512];

        // Vertex Shader

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, nullptr);
    glCompileShader(vertex);
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertex, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

        // Fragment Shader

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, nullptr);
    glCompileShader(fragment);
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragment, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // Create shader program

    m_id = glCreateProgram();
    if (!m_id)
    {
        std::cerr << "ERROR::SHADER::PROGRAM::CREATION_FAILED" << std::endl;
    }

    glAttachShader(m_id, vertex);
    glAttachShader(m_id, fragment);
    glLinkProgram(m_id);
    glGetProgramiv(m_id, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(m_id, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    // Cleanup
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::use()
{
    glUseProgram(m_id);
}

void Shader::setBool(std::string const & name, bool val) const
{
    glUniform1i(glGetUniformLocation(m_id, name.c_str()), static_cast<int>(val));
}

void Shader::setInt(std::string const & name, int val) const
{
    glUniform1i(glGetUniformLocation(m_id, name.c_str()), val);
}

void Shader::setFloat(std::string const & name, float val) const
{
    glUniform1f(glGetUniformLocation(m_id, name.c_str()), val);
}

void Shader::setMatrix4f(std::string const & name, glm::mat4x4 val) const
{
    glUniformMatrix4fv(glGetUniformLocation(m_id, name.c_str()), 1, GL_FALSE, &val[0][0]);
}
