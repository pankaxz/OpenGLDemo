#include "shader.hpp"

Shader::Shader(Type type, const std::string &filename)
    :m_handle{0}
{
    GLenum glType = GL_VERTEX_SHADER;
    switch (type) {
        case VERTEX:
            break;

        case FRAGMENT:
            glType = GL_FRAGMENT_SHADER;
        break;
    }

    m_handle = glCreateShader(glType);
}

Shader::~Shader() {
    if(m_handle > 0) {
        glDeleteShader(m_handle);
        m_handle = 0;
    }
}

GLint Shader::handle() const {

}