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

CONFIG += file_copies

COPIES += shaders

shaders.files = $$files(shaders/*.glsl)
shaders.path = $$OUT_PWD/shaders

SOURCES += \
        src/application.cpp \
        src/color.cpp \
        src/main.cpp \
        src/shader.cpp \
        src/vertex.cpp

HEADERS += \
    headers/application.h \
    headers/color.h \
    headers/shader.h \
    headers/vertex.h

DISTFILES += \
    shaders/fragment.glsl \
    shaders/vertex.glsl
