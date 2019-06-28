#include "headers/vertex.h"

Vertex::Vertex(double x, double y, double z, double r, double g, double b)
    : m_x {x}
    , m_y {y}
    , m_z {z}
    , m_color {r, g, b}
{
}

Vertex::Vertex(double x, double y, double z, Color c)
    : m_x {x}
    , m_y {y}
    , m_z {z}
    , m_color {c}
{
}
