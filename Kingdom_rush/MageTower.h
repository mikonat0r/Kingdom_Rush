#pragma once
#include "Tower.h"
#include "IAttackable.h"
#include "IUpgradable.h"

class MageTower : public Tower, public IAttackable, public IUpgradable {
private:
    int magicDamage;

public:
    MageTower(std::string name, int id);

    void showInfo() const override;
    std::string getType() const override;

    void attack() override;
    void upgrade() override;
};