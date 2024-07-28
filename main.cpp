#include "SFML/Graphics.hpp"

int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Move the Circle with WASD");

    // Create a circle
    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(375, 275); // Center the circle

    // Set the movement speed
    float moveSpeed = 5.0f;

    // Start the game loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Handle circle movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            circle.move(0, -moveSpeed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            circle.move(-moveSpeed, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            circle.move(0, moveSpeed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            circle.move(moveSpeed, 0);
        }

        // Clear screen
        window.clear();

        // Draw the circle
        window.draw(circle);

        // Update the window
        window.display();
    }
	return 0;
}