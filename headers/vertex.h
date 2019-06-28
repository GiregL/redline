#ifndef VERTEX_H
#define VERTEX_H
#include "color.h"
#include <vector>

class Vertex
{
public:
    Vertex(float x,
           float y,
           float z,
           float r,
           float g,
           float b);
    Vertex(float x, float y, float z, Color c);

    float m_x;
    float m_y;
    float m_z;
    Color m_color;
};

#endif // VERTEX_H
