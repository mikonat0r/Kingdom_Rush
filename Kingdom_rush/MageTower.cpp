#include "MageTower.h"
#include <iostream>

using namespace std;

MageTower::MageTower(string name, int id)
    : Tower(name, id, 100), magicDamage(40) {
}

void MageTower::showInfo() const {
    cout << "-------------------------------------------\n";
    cout << "Тип: " << getType() << "\n";
    cout << "Имя: " << name << "\n";
    cout << "ID: " << getId() << "\n";
    cout << "Уровень: " << level << "\n";
    cout << "Стоимость: " << cost << " золота\n";
    cout << "Магический урон: " << magicDamage << " ед. (пробивает броню)\n";
    cout << "-------------------------------------------\n";
}



string MageTower::getType() const {
    return "Mage Tower";
}

void MageTower::attack() {
    cout << "Маги " << name << " выпускает медленный, но мощный энергетический заряд, нанося " << magicDamage << " маг. урона!\n";
}

void MageTower::upgrade() {
    level++;
    magicDamage += 25;
    cost += 80;
    cout << "Маги " << name << " улучшена до " << level << " уровня! Магический урон значительно увеличен.\n";
}