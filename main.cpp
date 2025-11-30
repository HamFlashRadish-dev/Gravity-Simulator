#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main() {
    int radius = 50;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Test");

    sf::CircleShape ball(radius);
    ball.setFillColor(sf::Color::White);
    ball.setPosition(400 - radius / 2, 300 - radius / 2);

    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(ball);

        window.display();
    }

    return 0;
}