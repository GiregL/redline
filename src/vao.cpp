#include "vao.h"

VAO::VAO()
    : m_id {0}
    , m_vbos {}
{
    glGenVertexArrays(1, &m_id);
}

void VAO::appendVBO(unsigned int vbo)
{
    if (std::size(m_vbos) < 16)
    {
        m_vbos.push_back(vbo);
    }
}

void VAO::bind()
{
    glBindVertexArray(m_id);
}

void VAO::render()
{

}

void VAO::unbind()
{
    glBindVertexArray(0);
}

VAO::~VAO()
{
    auto it {std::begin(m_vbos)};
    while (it != std::end(m_vbos))
    {
        glDeleteBuffers(1, &*it);
        it++;
    }
    m_vbos.clear();
}
