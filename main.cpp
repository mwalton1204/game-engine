#include "main.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 450), "Hello, World!"); // Create the window

    sf::CircleShape shape(10.f); // Draw a shape
    shape.setFillColor(sf::Color::Green); // Color the shape

    sf::Clock clock; // Initialize clock
    window.setFramerateLimit(60); // Set framerate limit

    float speed = 2.0f; // Set default movement speed

    sf::Vector2f position;

    // Main application loop
    while (window.isOpen())
    {
        // Reset timer to zero and return time elapsed since last restart
        float currentTime = clock.restart().asSeconds();

        // Calculate fps (currentTime is equivalent of seconds per frame. The reciprocal gives frames per second.)
        float fps = 1.0f / currentTime;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        sf::Vector2f velocity;

        if(sf::Event::KeyPressed){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                velocity.x -= 1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                velocity.x += 1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                velocity.y -= 1;
                }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                velocity.y += 1;
             }

            velocity = VectorUtils::normalize(velocity); // Normalizes diagonal speed
        }

        position.x += velocity.x * speed; // Update position along x-axis
        position.y += velocity.y * speed; // Updates position along y-axis
        std::cout << "Position: (" << std::round(position.x) << ", " << std::round(position.y) << ")" << std::endl; // Prints position coordinates to terminal every frame
        shape.move(velocity * speed); // Moves the shape
        

        window.clear(); // Clear window

        window.draw(shape); // Render updated shape

        window.display(); // Display Content
    }

    return 0;
}