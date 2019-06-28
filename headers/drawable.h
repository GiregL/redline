#ifndef DRAWABLE_H
#define DRAWABLE_H
#include "object.h"
#include <vector>
#include "vertex.h"

class Drawable : public Object {

public:
    void init() override;
    void update() override;

    void init3D();
    void draw3D();

protected:
    std::vector<Vertex> m_vertices;
};

#endif // DRAWABLE_H
