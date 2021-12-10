#include "Enemy.h"

Enemy::Enemy(): isAlive(true), name("Enemy"), maxHealth(100), currentHealth(100), speed(0.1), coordinats() {
    enemyTexture.loadFromFile("/home/vadim/CLionProjects/SFMLproject/Images/Enemy.jpg");
    enemySprite.setTexture(enemyTexture);
};

Enemy::Enemy(std::string &_name, const Point &_p): isAlive(true), name(_name), maxHealth(100), currentHealth(100), speed(0.1), coordinats(_p) {
    enemyTexture.loadFromFile("/home/vadim/CLionProjects/SFMLproject/Images/Enemy.jpg");
    enemySprite.setTexture(enemyTexture);
};

Enemy::Enemy(std::string &_name, int _maxHealth, int _currentHealth, int _speed, const Point &_p): isAlive(true), name(_name),
                                        maxHealth(_maxHealth), currentHealth(_currentHealth), speed(_speed), coordinats(_p)
{
    enemyTexture.loadFromFile("/home/vadim/CLionProjects/SFMLproject/Images/Enemy.jpg");
    enemySprite.setTexture(enemyTexture);
};

sf::Sprite& Enemy::getSprite() {
    return enemySprite;
}

void Enemy::setPoint(double x, double y) {
    coordinats.x = x;
    coordinats.y = y;
}

Point Enemy::getPoint() {
    return coordinats;
}

void Enemy::move(Castle &fortress, float time) {
    double distance = sqrt((fortress.getPoint().x - coordinats.x) * (fortress.getPoint().x - coordinats.x) +
            (fortress.getPoint().y - coordinats.y) * (fortress.getPoint().y - coordinats.y));
    if (distance > 2) {
        double xcoord = coordinats.x, ycoord = coordinats.y;
        coordinats.x = xcoord + (speed * time * (fortress.getPoint().x - coordinats.x)) / distance,
        coordinats.y = ycoord + (speed * time * (fortress.getPoint().y - coordinats.y)) / distance;
        enemySprite.setPosition(coordinats.x, coordinats.y);
    }
    else {
        fortress.setEndurance(fortress.getEndurance() - currentHealth);
        currentHealth = 0;
        isAlive = false;
        if (fortress.getEndurance() <= 0) fortress.setAlive();
    }
}