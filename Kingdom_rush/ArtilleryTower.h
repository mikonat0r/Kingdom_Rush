#pragma once
#include "Tower.h"
#include "IAttackable.h"
#include "IUpgradable.h"

class ArtilleryTower : public Tower, public IAttackable, public IUpgradable {
private:
    int explosionRadius;

public:
    ArtilleryTower(std::string name, int id);

    void showInfo() const override;
    std::string getType() const override;

    void attack() override;
    void upgrade() override;
};