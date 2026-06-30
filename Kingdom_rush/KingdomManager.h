#pragma once

#include <vector>
#include <memory>
#include "Tower.h"

class KingdomManager {
private:
    std::vector<std::shared_ptr<Tower>> mapTowers;
    int gold;
    int nextId;

public:
    KingdomManager();

    void run();
    void showMenu() const;

    void buildTower();
    void showMapTowers() const;
    void showTowerDetails() const;
    void upgradeTower();
    void commandTower();
    void sellTower();
};