#include "ArcherTower.h"
#include <iostream>

using namespace std;

ArcherTower::ArcherTower(string name, int id)
    : Tower(name, id, 100), attackSpeed(1) {
}

void ArcherTower::showInfo() const {
    cout << "-------------------------------------------\n";
    cout << "Тип: " << getType() << "\n";
    cout << "Имя: " << name << "\n";
    cout << "ID: " << getId() << "\n";
    cout << "Уровень: " << level << "\n";
    cout << "Стоимость: " << cost << " золота\n";
    cout << "Скорость атаки: " << attackSpeed << " стр./сек.\n";
    cout << "-------------------------------------------\n";
}

string ArcherTower::getType() const {
    return "Archer Tower";
}

void ArcherTower::attack() {
    cout << "Лучники " << name << " выпускают быстрый залп стрел со скоростью " << attackSpeed << " стр./сек.!\n";
}

void ArcherTower::upgrade() {
    level++;
    attackSpeed += 1;
    cost += 50;
    cout << "Лучники " << name << " улучшена до " << level << " уровня! Скорость атаки выросла.\n";
}