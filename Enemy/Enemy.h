#ifndef SFMLPROJECT_ENEMY_H
#define SFMLPROJECT_ENEMY_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Point.h"
#include "../Castle/Castle.h"
#include <cmath>

class Enemy {
private:
    bool isAlive;
    std::string name;
    sf::Texture enemyTexture;
    sf::Sprite enemySprite;
    int maxHealth;
    int currentHealth;
    double speed;
    Point coordinats;
public:
    Enemy();
    Enemy(std::string &_name, const Point &_p);
    Enemy(std::string &_name, int _maxHealth, int _currentHealth, int _speed, const Point &_p);
    sf::Sprite& getSprite();
    void setPoint(double x = 0, double y = 0);
    Point getPoint();
    void move(Castle &fortress, float time);
    void setAlive() { isAlive = false; }
    bool getAlive() const { return isAlive; }
    void setHealth(int _currentHealth) { currentHealth = _currentHealth; }
    int isHealth() const { return currentHealth; }
};

#endif
