#ifndef SFMLPROJECT_TOWER_H
#define SFMLPROJECT_TOWER_H

#include <SFML/Graphics.hpp>
#include "../Point.h"
#include "../Enemy/Enemy.h"

class Tower {
private:
    int level;
    sf::Texture towerTexture;
    sf::Sprite towerSprite;
    Point coordinats;
protected:
    int cost;
    int radius;
    int damage;
    int rate;
public:
    Tower();
    explicit Tower(const Point &_p);
    void putTower(Enemy &enemy, double positionX, double positionY, float time);
    sf::Sprite& getSprite();
    void setPoint(double x = 0, double y = 0);
};

#endif
