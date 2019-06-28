TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -L"/usr/lib64/SFML"


INCLUDEPATH += "/usr/include/SFML"
DEPENDPATH += "/usr/include/SFML"

# Release configuration
CONFIG(release, debug|release)
{
LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lGLU -lGL -lGLEW -ldl
#QMAKE_CXXFLAGS_DEBUG += -fsanitize=address,undefined
}

# Debug configuration
CONFIG(debug, debug|release)
{
#QMAKE_CXXFLAGS_DEBUG += -fsanitize=address,undefined
LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lGLU -lGL -lGLEW -ldl
}

SOURCES += \
        src/application.cpp \
        src/color.cpp \
        src/main.cpp \
        src/rawmodel.cpp \
        src/shader.cpp \
        src/vao.cpp \
        src/vertex.cpp

HEADERS += \
    headers/application.h \
    headers/color.h \
    headers/rawmodel.h \
    headers/shader.h \
    headers/vao.h \
    headers/vertex.h

DISTFILES += \
    fragment.glsl \
    vertex.glsl
