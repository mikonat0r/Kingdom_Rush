#include "KingdomManager.h"
#include "ArcherTower.h"
#include "MageTower.h"
#include "BarracksTower.h"
#include "ArtilleryTower.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

KingdomManager::KingdomManager() : gold(500), nextId(1) {}

void KingdomManager::showMenu() const {
    endl(::cout);
    cout << "    KINGDOM RUSH TOWER MANAGER    \n";
    cout << "Ваше золото: " << gold << "\n";
    cout << "----------------------------------\n";
    cout << "1. Построить башню (Build Tower)\n";
    cout << "2. Показать все башни на карте (Show Towers)\n";
    cout << "3. Информация о башне по ID (Tower Details)\n";
    cout << "4. Отдать приказ башне (Perform Action)\n";
    cout << "5. Улучшить башню (Upgrade Tower)\n";
    cout << "6. Продать Башню (Sell Tower)\n";
    cout << "7. Выйти из игры (Exit)\n";
    cout << "----------------------------------\n";
    cout << "Выберите действие: ";
}

void KingdomManager::run() {
    int choice = 0;
    while (choice != 7) {
        showMenu();
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода! Пожалуйста, введите число от 1 до 7.\n";
            continue;
        }
        endl(cout);

        switch (choice) {
        case 1: buildTower(); break;
        case 2: showMapTowers(); break;
        case 3: showTowerDetails(); break;
        case 4: commandTower(); break;
        case 5: upgradeTower(); break;
        case 6: sellTower(); break;
        case 7: cout << "До встречи на полях сражений Линиреи!\n"; break;
        default: cout << "Неверный пункт меню!\n"; break;
        }
    }
}

void KingdomManager::buildTower() {
    cout << "    РЫНОК СТРОИТЕЛЬСТВА БАШЕН    \n";
    cout << "1. Archer Tower (Лучники)   - 70 золота\n";
    cout << "2. Mage Tower (Маги)        - 100 золота\n";
    cout << "3. Barracks Tower (Казармы) - 70 золота\n";
    cout << "4. Artillery Tower (Гномы)  - 125 золота\n";
    cout << "---------------------------------\n";
    cout << "Какую башню строим? ";

    int type;
    cin >> type;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка ввода! Пожалуйста, введите число от 1 до 4.\n";
        return;
    }

    cout << "Введите уникальное имя для башни: ";
    string name;
    cin >> name;

    if (name.empty()) {
        cout << "Ошибка ввода! Имя башни не может быть пустым!\n";
        return;
    }

    for (const auto& tower : mapTowers) {
        if (tower->getName() == name) {
            cout << "Ошибка! Башня с именем \"" << name << "\" уже существует!\n";
            return;
        }
    }

    shared_ptr<Tower> newTower = nullptr;

    if (type == 1 && gold >= 70) {
        newTower = make_shared<ArcherTower>(name, nextId);
        gold -= 70;
    }
    else if (type == 2 && gold >= 100) {
        newTower = make_shared<MageTower>(name, nextId);
        gold -= 100;
    }
    else if (type == 3 && gold >= 70) {
        newTower = make_shared<BarracksTower>(name, nextId);
        gold -= 70;
    }
    else if (type == 4 && gold >= 125) {
        newTower = make_shared<ArtilleryTower>(name, nextId);
        gold -= 125;
    }
    else {
        cout << "Недостаточно золота или выбран неверный тип башни!\n";
        return;
    }

    mapTowers.push_back(newTower);
    cout << "Башня \"" << name << "\" успешно возведена на карте! (Присвоен ID: " << nextId << ")\n";
    nextId++;
}

void KingdomManager::showMapTowers() const {
    if (mapTowers.empty()) {
        cout << "На карте пока нет башен. Оборона пуста!\n";
        return;
    }

    cout << "=== ВАША ОБОРОНИТЕЛЬНАЯ ЛИНИЯ ===\n";
    for (const auto& tower : mapTowers) {
        cout << "ID: " << tower->getId() << " | [" << tower->getType() << "] \"" << tower->getName() << "\" (Lvl " << tower->getLevel() << ")\n";
    }
}

void KingdomManager::showTowerDetails() const {
    cout << "Введите ID башни для просмотра инфо: ";
    int id;
    cin >> id;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка ввода! Пожалуйста, введите число.\n";
        return;
    }

    for (const auto& tower : mapTowers) {
        if (tower->getId() == id) {
            tower->showInfo();
            return;
        }
    }
    cout << "Башня с ID " << id << " не найдена.\n";
}

void KingdomManager::upgradeTower() {
    cout << "Введите ID башни для улучшения: ";
    int id;
    cin >> id;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка ввода! Пожалуйста, введите число.\n";
        return;
    }

    for (auto& tower : mapTowers) {
        if (tower->getId() == id) {
            auto upgradable = dynamic_cast<IUpgradable*>(tower.get());
            if (upgradable) {
                int upgradeCost = tower->getCost() * 0.7;
                if (gold >= upgradeCost) {
                    gold -= upgradeCost;
                    upgradable->upgrade();
                }
                else {
                    cout << "Недостаточно золота для улучшения! Требуется: " << upgradeCost << "\n";
                }
            }
            else {
                cout << "Эта постройка не может быть улучшена.\n";
            }
            return;
        }
    }
    cout << "Башня с ID " << id << " не найдена.\n";
}

void KingdomManager::commandTower() {
    cout << "Введите ID башни для активации ее способностей: ";
    int id;
    cin >> id;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка ввода! Пожалуйста, введите число.\n";
        return;
    }

    for (auto& tower : mapTowers) {
        if (tower->getId() == id) {
            auto attackable = dynamic_cast<IAttackable*>(tower.get());
            if (attackable) {
                attackable->attack();

                int level = tower->getLevel();
                int reward = 0;

                if (dynamic_cast<ArcherTower*>(tower.get())) {
                    reward = 15 * level;
                }
                else if (dynamic_cast<MageTower*>(tower.get())) {
                    reward = 22 * level;
                }
                else if (dynamic_cast<ArtilleryTower*>(tower.get())) {
                    reward = 30 * level;
                }
                else {
                    reward = 20 * level;
                }

                gold += reward;
                cout << tower->getType() << " \"" << tower->getName() << "\" " << level << "-го уровня принесла " << reward << " золота за атаку!\n";
                return;
            }
            auto creatable = dynamic_cast<ICreatable*>(tower.get());
            if (creatable) {
                creatable->createUnit();

                int level = tower->getLevel();
                int reward = 15 * level;

                gold += reward;
                cout << "Казармы \"" << tower->getName() << "\" " << level << "-го уровня принесли: +" << reward << " золота!\n";
                return;
            }
        }
    }
    cout << "Башня с ID " << id << " не найдена или не имеет активных приказов.\n";
}

void KingdomManager::sellTower() {
    cout << "Введите ID башни для ПРОДАЖИ: ";
    int id;
    cin >> id;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка ввода! Пожалуйста, введите число.\n";
        return;
    }

    for (auto it = mapTowers.begin(); it != mapTowers.end(); ++it) {
        if ((*it)->getId() == id) {
            int refund = (*it)->getCost() * 0.7;
            gold += refund;

            cout << "Башня \"" << (*it)->getName() << "\" снесена! Вы вернули " << refund << " золота.\n";
            mapTowers.erase(it);
            return;
        }
    }
    cout << "Башня с ID " << id << " не найдена.\n";
}