#include "rectangle.h"

Rectangle::Rectangle(Vertex v1, Vertex v2, Vertex v3, Vertex v4)
    : Drawable {}
    , m_v1 {v1}
    , m_v2 {v2}
    , m_v3 {v3}
    , m_v4 {v4}
{
    m_vertices = std::vector<Vertex> {
        m_v1, m_v2, m_v3, m_v4
    };
}

Rectangle::Rectangle(std::array<Vertex, 4u> vertices)
    : Drawable {}
    , m_v1 {vertices[0]}
    , m_v2 {vertices[1]}
    , m_v3 {vertices[2]}
    , m_v4 {vertices[3]}
{
}
