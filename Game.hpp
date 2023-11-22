#pragma once

#include <iostream>

#include "Graph.hpp"

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
    Graph Map;

    //Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;

    //Private functions
    void initMap();
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
    void checkGoalPosition(int x, int y);
    void update();
    void render();
};