#include "Tower.h"
#include <iostream>

using namespace std;

Tower::Tower(string name, int id, int cost)
    : name(name), id(id), cost(cost), level(1) {
}
int Tower::getId() const {
    return id;
}

string Tower::getName() const {
    return name;
}

int Tower::getLevel() const {
    return level;
}

int Tower::getCost() const {
    return cost;
}