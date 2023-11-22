#include "Game.hpp"

//Private functions
void Game::initMap()
{
    Graph graph;
    Map = graph;
    Map.locConfig();
}

void Game::initVariables()
{
    this->window = nullptr;
}

void Game::initWindow()
{
    this->videoMode.height = 640;
    this->videoMode.width = 874;

    this->window = new sf::RenderWindow(this->videoMode, "A Jornada do Bixo", sf::Style::Titlebar | sf::Style::Close);
}

//Constructor/Destructor
Game::Game()
{
    this->initMap();
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
            case sf::Event::MouseButtonPressed:
                if (this->ev.mouseButton.button == sf::Mouse::Left)
                    checkGoalPosition(sf::Mouse::getPosition(*this->window).x,
                                      sf::Mouse::getPosition(*this->window).y);
                break;
        }
    }
}

void Game::checkGoalPosition(int x, int y)
{
    int dist2;   //Distance^2
    std::size_t order = Map.get_order();
    for (std::size_t i = 0; i < order; ++i)
    {
        dist2 = (x - this->Map.xCoord(i)) * (x - this->Map.xCoord(i)) +
                (y - this->Map.yCoord(i)) * (y - this->Map.yCoord(i));

        if (dist2 <= 324)
        {
            Map.goalVertex = i;
            std::cout << "Current Vertex: " << Map.currentVertex + 1 << " Goal Vertex: " << Map.goalVertex + 1 << "\n";
            Map.aStarSearch(Map.currentVertex, Map.goalVertex);
            Map.currentVertex =  Map.goalVertex;
        }
    }
}

void Game::update()
{
    this->pollEvents();
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
    t.loadFromFile("C:\\RPG_Game\\map.png");
    sf::Sprite s(t);

    //Draw game objects
    this->window->draw(s);
    this->window->display();
}