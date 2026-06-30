#pragma once
#include <string>

class Tower {
protected:
    std::string name;
    int id;
    int cost;
    int level;

public:
    Tower(std::string name, int id, int cost);

    virtual ~Tower() = default;

    virtual void showInfo() const = 0;
    virtual std::string getType() const = 0;

    int getId() const;
    std::string getName() const;
    int getLevel() const;
    int getCost() const;
};