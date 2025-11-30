#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <cstdlib>

int main() {
    int radius = 15;
    float ballX = 400 - radius;
    float ballY = 200 - radius;
    float fallVelocity = 0.0f;
    float mouseX;
    float mouseY;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Test");

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    sf::CircleShape ball(radius);
    ball.setFillColor(sf::Color::White);
    ball.setPosition(ballX, ballY);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                window.close();
        }

        double dt = clock.restart().asSeconds();

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        mouseX = static_cast<float>(mousePos.x);
        mouseY = static_cast<float>(mousePos.y);

        

        if (ballY <= 600 - radius * 2) {
            fallVelocity += 10.f;
            ballY += fallVelocity * dt;
            ball.setPosition(ballX, ballY);
        }
        else {
            fallVelocity = 0.0f;
        }

        window.clear();

        ball.setPosition(ballX, ballY);
        window.draw(ball);

        window.display();
    }

    return 0;
}