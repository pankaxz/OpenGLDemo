#pragma once
#include <string>
#include <GL/glew.h>

class Shader {
private:
    GLint m_handle;

public:
    enum Type {
        VERTEX,
        FRAGMENT
    };

    Shader(Type type, const std::string &filename);

    Shader(const Shader &other) = delete;

    Shader operator = (const Shader &other) = delete;

    ~Shader();

    GLint handle() const;
};
