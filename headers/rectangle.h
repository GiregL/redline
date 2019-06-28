#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <array>
#include "object.h"
#include "drawable.h"
#include "vertex.h"

class Rectangle : public Drawable {

public:
    Rectangle(Vertex v1, Vertex v2, Vertex v3, Vertex v4);
    Rectangle(std::array<Vertex, 4u>);

    void init() override;
    void update() override;

private:
    Vertex m_v1;
    Vertex m_v2;
    Vertex m_v3;
    Vertex m_v4;

};

#endif // RECTANGLE_H
