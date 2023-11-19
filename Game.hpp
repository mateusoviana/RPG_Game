#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

/*
    Class that works as the game engine.
    Wrapper class.
*/

class Game
{
private:
    //Variables
    size_t currentVertex;
    size_t goalVertex;

    //Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;

    //Mouse positions
    sf::Vector2i mousePosWindow;

    //Private functions
    void initVariables();
    void initWindow();

public:
    //Constructor/Destructor
    Game();
    virtual ~Game();

    //Accessors
    const bool running() const;

    //Functions
    void pollEvents();
    void checkGoalPosition();
    void update();
    void render();
};