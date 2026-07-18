module;
#include <glad/gl.h>
#include <vector>

export module SimpleVAO;
import VAO;
import EBO;
import VBO;

export class SimpleVAO : public VAO
{
public:
    struct TypeEntry
    {
        /**
         * The type (e.g. GL_UNSIGNED_BYTE)
         */
        GLenum type;
        /**
         * The amount of times to use this type.
         */
        unsigned int size;
    };
public:
    /**
     * This creates a VAO, that is quite flexible.
     * @param vbo The VBO to bind to.
     * @param types The types in the order you want them.
     */
    SimpleVAO(VBO& vbo, std::vector<TypeEntry> types);
protected:
    bool build(unsigned int& vaoId, GLenum& mode) override;
private:
    bool fillVertexAttributes();
    unsigned int getStride(const TypeEntry& entry, const unsigned int& offset);

    void setVertexAttribute(
        const unsigned int& stride,
        const unsigned int& offset
    );
private:
    VBO& vbo;
    /**
     * The types in the proper order.
     * TODO: Add more information...
     */
    const std::vector<TypeEntry> types;
};
