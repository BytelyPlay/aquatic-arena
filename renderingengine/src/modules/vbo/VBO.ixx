module;

export module VBO;
import Logger;

export class VBO
{
public:
    VBO();
public:
    /**
     * Get the VBO id, builds if it isn't yet built.
     * @return Returns 0 if we can't get the ID
     */
    unsigned int getVBOId();
    /**
     * Binds the VBO.
     * @return Whether it was successful or not.
     */
    bool bind();
protected:
    /**
     * Builds the VBO
     * @return Successful or not
     */
    virtual bool build(unsigned int& vboId) = 0;
private:
    /**
     * The VBO ID from OpenGL.
     */
    unsigned int vboId = 0;
    /**
     * If the VBO was built.
     * Doesn't mean it was successful,
     * it's just so that we don't repeatedly compile it after it fails...
     */
    bool built = false;
private:
    Logger& log = Logger::getInstance();
public:
    virtual ~VBO();
public:
    VBO(const VBO&) = delete;
    VBO(VBO&) = delete;

    VBO& operator=(const VBO&) = delete;
    VBO& operator=(VBO&&) = delete;
};