#ifndef OBJECT_H
#define OBJECT_H


class Object
{
public:
    virtual void init();
    virtual void update();

    virtual ~Object();
};

#endif // OBJECT_H
