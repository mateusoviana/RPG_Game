#include "Game.hpp"

//Private functions
void Game::initVariables()
{
    this->window = nullptr;
}

void Game::initWindow()
{
    this->videoMode.height = 640;
    this->videoMode.width = 874;

    this->window = new sf::RenderWindow(this->videoMode, "Atravessando o DCTA", sf::Style::Titlebar | sf::Style::Close);
}

//Constructor/Destructor
Game::Game()
{
    this->initVariables();
    this->initWindow();
}

Game::~Game()
{
    delete this->window;
}

//Accessors
const bool Game::running() const
{
    return this->window->isOpen();
}

//Functions
void Game::pollEvents()
{
    //Event polling
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
        }
    }
}

void Game::update()
{
    this->pollEvents();

    //Update mouse position
    std::cout << "Mouse position: "
    << sf::Mouse::getPosition(*this->window).x << " "
    << sf::Mouse::getPosition(*this->window).y << "\n";
}

void Game::render()
{
    /*
        - clear old frame
        - render objects
        - display frame in window

        Renders the game objects.
    */

    //Clear old frame
    this->window->clear(sf::Color::White);

    //Create texture and load image file
    sf::Texture t;
    t.loadFromFile("C:\\Exame\\map.png");
    sf::Sprite s(t);

    //Draw game objects
    this->window->draw(s);
    this->window->display();
}