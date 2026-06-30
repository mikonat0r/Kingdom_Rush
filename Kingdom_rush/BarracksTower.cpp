#include "BarracksTower.h"
#include <iostream>

using namespace std;

BarracksTower::BarracksTower(string name, int id)
    : Tower(name, id, 70), unitType("Militia"), unitCount(3) {
}

void BarracksTower::showInfo() const {
    cout << "-------------------------------------------\n";
    cout << "Тип: " << getType() << "\n";
    cout << "Имя: " << name << "\n";
    cout << "ID: " << getId() << "\n";
    cout << "Уровень: " << level << "\n";
    cout << "Стоимость: " << cost << " золота\n";
    cout << "Количество солдат: " << unitCount << " x " << unitType << "\n";
    cout << "-------------------------------------------\n";
}

string BarracksTower::getType() const {
    return "Barracks Tower";
}

void BarracksTower::createUnit() {
	cout << "[Казармы] Из башни " << name << " выходят " << unitCount << " воина класса [" << unitType << "] на поле боя!\n";
}

void BarracksTower::upgrade() {
    level++;
    cost += 110;

    if (level == 2) {
        unitType = "Footmen";
        cout << "Казармы " << name << " улучшена! Ваши солдаты теперь: Footmen (Пехотинцы).\n";
    }
    else if (level >= 3) {
        unitType = "Knights";
        cout << "Казармы " << name << " улучшена до максимального уровня! Ваши солдаты теперь: Knights (Рыцари).\n";
    }
}