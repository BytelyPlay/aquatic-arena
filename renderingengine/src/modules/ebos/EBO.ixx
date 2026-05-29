module;

export module EBO;

export class EBO
{
public:
    static constexpr unsigned int INVALID_EBO_ID = 0;
    static constexpr unsigned int INVALID_INDICE_COUNT = 0;
public:
    unsigned int getVAOId();
    unsigned int getIndiceCount();
protected:
    virtual void compileEBO(
        unsigned int& VAOId,
        unsigned int& indiceCount,
        bool& success
    ) = 0;
private:
    void tryToCompile();
private:
    unsigned int VAOId;
    unsigned int indiceCount;

    bool ran, successful;
public:
    virtual ~EBO() = default;
public:
    EBO(const EBO&) = delete;
    EBO(EBO&&) = delete;

    EBO& operator=(const EBO&) = delete;
    EBO& operator=(EBO&&) = delete;
};