#include "ArtilleryTower.h"
#include <iostream>

using namespace std;

ArtilleryTower::ArtilleryTower(string name, int id)
    : Tower(name, id, 125), explosionRadius(5) {
}

void ArtilleryTower::showInfo() const {
    cout << "-------------------------------------------\n";
    cout << "Тип: " << getType() << "\n";
    cout << "Имя: " << name << "\n";
    cout << "ID: " << getId() << "\n";
    cout << "Уровень: " << level << "\n";
    cout << "Стоимость: " << cost << " золота\n";
    cout << "Радиус взрыва: " << explosionRadius << " метров (АОЕ урон)\n";
    cout << "-------------------------------------------\n";
}



string ArtilleryTower::getType() const {
    return "Artillery Tower";
}

void ArtilleryTower::attack() {
    cout << "Артиллерия " << name << " производит мощный выстрел! Бомба взрывается в радиусе " << explosionRadius << " метров, накрывая толпу врагов!\n";
}

void ArtilleryTower::upgrade() {
    level++;
    explosionRadius += 3;
    cost += 95;
    cout << "Артиллерия " << name << " улучшена до " << level << " уровня! Радиус поражения увеличен.\n";
}