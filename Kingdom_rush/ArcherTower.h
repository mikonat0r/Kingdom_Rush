#pragma once
#include "Tower.h"
#include "IAttackable.h"
#include "IUpgradable.h"

class ArcherTower : public Tower, public IAttackable, public IUpgradable {
private:
    int attackSpeed;

public:
    ArcherTower(std::string name, int id);

    void showInfo() const override;
    std::string getType() const override;

    void attack() override;

    void upgrade() override;
};