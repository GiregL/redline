#ifndef COLOR_H
#define COLOR_H
#include <math.h>

class Color
{
public:
    Color(double r = 1.0, double g = 1.0, double b = 1.0);
    double m_r;
    double m_g;
    double m_b;

    inline bool operator==(Color const & other) const
    {
        const auto comp {[](double v1, double v2) -> bool {
                return (abs(v2 - v1) < 0.001);
        }};

        if (!comp(m_r, other.m_r)
                || !comp(m_g, other.m_g)
                || !comp(m_b, other.m_b))
                return false;
        return true;
    }
};

#endif // COLOR_H
