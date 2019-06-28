#ifndef VAO_H
#define VAO_H
#include <GL/glew.h>
#include <vector>
#include "vertex.h"

class VAO
{
public:
    VAO();
    ~VAO();
    void appendVBO(unsigned int vbo);
    void bind();
    void render();
    void unbind();

private:
    unsigned int m_id;

    std::vector<unsigned int> m_vbos;
};

#endif // VAO_H
