#pragma once
enum class Type {
    trap,
    buff,
    spell
};

const int MAX_NAME_SIZE = 26;
const int MAX_EFFECT_SIZE = 101;

class Magic {
private:
    char name[MAX_NAME_SIZE];
    char effect[MAX_EFFECT_SIZE];
    Type type;

public:
    const char* getName() const;
    const char* getEffect() const;
    Type getType() const;

    void setName(const char* name);
    void setEffect(const char* effect);
    void setType(Type type);
};