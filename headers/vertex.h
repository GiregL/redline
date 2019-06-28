#ifndef VERTEX_H
#define VERTEX_H
#include "color.h"
#include <vector>
#include <math.h>

class Vertex
{
public:
    Vertex(double x,
           double y,
           double z,
           double r,
           double g,
           double b);
    Vertex(double x, double y, double z, Color c);

    inline bool operator==(Vertex const & other) const
    {
        const auto comp {[](double v1, double v2) -> bool {
                return (abs(v2 - v1) < 0.0001);
        }};

        if (!comp(m_x, other.m_x)
                || !comp(m_y, other.m_y)
                || !comp(m_z, other.m_z)
                || !(m_color == other.m_color))
                return false;
        return true;
    }

    double m_x;
    double m_y;
    double m_z;
    Color m_color;
};

#endif // VERTEX_H
