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
    bool touchingBall = false;
    bool mouseDown = false;
    bool mouseInWindow = false;
    bool ballHittingGround = false;
    bool inBallRange = false;

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

        //Checks if mouse down
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            mouseDown = true;
        }
        else {
            mouseDown = false;
        }
        // Check if mouse is within window bounds
        if (mouseX >= 0 && mouseX <= 800 && mouseY >= 0 && mouseY <= 600) {
            mouseInWindow = true;
        }
        else {
            mouseInWindow = false;
        }

        //Checks if mouse is touching ball
        if (mouseX >= ballX && mouseX <= ballX + radius * 2 && mouseY >= ballY && mouseY <= ballY + radius * 2) {
            touchingBall = true;
        }
        else {
            touchingBall = false;
        }

        //Checks if mouse is in ball range
        if (mouseX >= ballX - 100 && mouseX <= ballX + radius * 2 + 100 && mouseY >= ballY - 100 && mouseY <= ballY + radius * 2 + 100) {
            inBallRange = true;
        }
        else {
            inBallRange = false;
        }
        

        //Checks if ball is hitting ground
        if (ballY >= 600 - radius * 2) {
            ballHittingGround = true;
        }
        else {
            ballHittingGround = false;
        }
        
        // Reset ball position on R key press
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            ballX = 400 - radius;
            ballY = 200 - radius;
            fallVelocity = 0.0f;
            ball.setPosition(ballX, ballY);
        }

        if (mouseDown && inBallRange && mouseInWindow) {
            fallVelocity = 0.0f;
            ballX = mouseX - radius;
            ballY = mouseY - radius;
        }
        
        if (!ballHittingGround) {
            fallVelocity += 950.0f * dt;
            ballY += fallVelocity * dt;
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