#ifndef SFMLPROJECT_LIAR_H
#define SFMLPROJECT_LIAR_H

#include "../Enemy/Enemy.h"
#include "../Point.h"
#include <vector>
#include "SFML/Graphics.hpp"

class Liar {
private:
    sf::Texture towerTexture;
    sf::Sprite towerSprite;

    Point coordinats;
public:
    void sendEnemy();
    void setPoint(double x = 0, double y = 0);
    Liar();

};

#endif
