#ifndef SFMLPROJECT_CASTLE_H
#define SFMLPROJECT_CASTLE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Point.h"

class Castle {
private:
    bool isAlive;
    std::string name;
    sf::Texture castleTexture;
    sf::Sprite castleSprite;
    int currentEndurance;
    int maxEndurance;
    int gold;
    Point coordinats;
public:
    Castle();
    Castle(std::string &_name, const Point &_p);
    Castle(std::string &_name, int _currentEndurance, int _maxEndurance, int _gold, const Point &_p);
    void setGold(int _gold);
    [[nodiscard]] int getGold() const;
    sf::Sprite& getSprite();
    void setPoint(double x, double y);
    Point getPoint();
    [[nodiscard]] int getEndurance() const;
    void setEndurance(int _currentEndurance);
    bool getAlive() const { return isAlive; }
    void setAlive() { isAlive = false; }
};

#endif
