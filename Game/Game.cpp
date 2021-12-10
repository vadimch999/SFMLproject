#include "Game.h"

void game() {
    bool putTower = false;
    float savedTime = 0;
    double putTowerx, putTowery;
    Castle fortress;
    fortress.setPoint(600, 700);
    fortress.getSprite().setPosition(fortress.getPoint().x, fortress.getPoint().y);
    sf::Clock clock;
    Enemy enemy1;
    enemy1.setPoint(100, 400);
    enemy1.getSprite().setPosition(enemy1.getPoint().x, enemy1.getPoint().y);
    Tower tower;
    tower.setPoint(200, 300);
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    while (window.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();
        float getTime = clock.getElapsedTime().asSeconds();
        savedTime += getTime;
        clock.restart();
        time = time / 2000;
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    putTowerx = event.mouseButton.x;
                    putTowery = event.mouseButton.y;
                    putTower = true;
                }
            }
        }
        window.clear(sf::Color::White);
        tower.putTower(enemy1, putTowerx, putTowery, savedTime);
        if (putTower) window.draw(tower.getSprite());
        enemy1.move(fortress, time);
        if (enemy1.getAlive()) window.draw(enemy1.getSprite());
        if (fortress.getAlive()) window.draw(fortress.getSprite());
        window.display();
    }
}