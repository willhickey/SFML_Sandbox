
#include <SFML/Graphics.hpp>
#include <cmath>
#define PI 3.1415926535

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900, 32), "SFML works!", sf::Style::Fullscreen);
    sf::CircleShape shape(20.f, 60);
    shape.setFillColor(sf::Color::Blue);
    float x, y;
    float xCenter = 400, yCenter = 300;
    float speed = 100;
    float angle = 0;
    sf::Clock clock;

    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            yCenter -= speed * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            yCenter += speed * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            xCenter -= speed * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            xCenter += speed * deltaTime;

        x = 20*cos(angle * PI / 180.0);
        y = 20*sin(angle * PI / 180.0);

        shape.setPosition(xCenter+x, yCenter+y);
        window.clear();
        window.draw(shape);
        window.display();
        angle+=deltaTime*100;
        if(angle==360)
            angle=0;
    }

    return 0;
}
