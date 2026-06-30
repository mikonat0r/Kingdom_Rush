#pragma once
#include "Tower.h"
#include "ICreatable.h"
#include "IUpgradable.h"
#include <string>

class BarracksTower : public Tower, public ICreatable, public IUpgradable {
private:
    std::string unitType;
    int unitCount;

public:
    BarracksTower(std::string name, int id);

    void showInfo() const override;
    std::string getType() const override;

    void createUnit() override;
    void upgrade() override;
};