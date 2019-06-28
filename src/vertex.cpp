#include "vertex.h"

Vertex::Vertex(float x, float y, float z, float r, float g, float b)
    : m_x {x}
    , m_y {y}
    , m_z {z}
    , m_color {r, g, b}
{
}

Vertex::Vertex(float x, float y, float z, Color c)
    : m_x {x}
    , m_y {y}
    , m_z {z}
    , m_color {c}
{
}
