#pragma once
#include <string>

class ICreatable {
public:
    virtual void createUnit() = 0;
    virtual ~ICreatable() = default;
};