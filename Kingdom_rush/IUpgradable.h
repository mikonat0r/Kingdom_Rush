#pragma once

class IUpgradable {
public:
    virtual void upgrade() = 0;
    virtual ~IUpgradable() = default;
};