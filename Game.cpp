#include "Game.hpp"
#include <math.h>

//Private functions
void Game::initMap()
{
    this->graphConfig();
    this->locConfig();
}

void Game::graphConfig()
{
    //Open the graph file
    std::ifstream graphFile("C:\\RPG_Game\\edges.txt");

    //Read the number of vertex of the map and create the map graph
    size_t n;
    graphFile >> n;
    Graph Map(n);

    //Read and create the graph edges
    std::size_t i, k;
    int edge;
    int order = Map.get_order();
    for (i = 0; i < order; ++i)
        for (k = 0; k < order; ++k)
        {
            graphFile >> edge;
            if (edge == 1)
                Map.add_edge(i, k);
        }

    //Close the graph file
    graphFile.close();

    this->Map = Map;
}

void Game::locConfig()
{
    //Open the locations file
    std::ifstream locFile("C:\\RPG_Game\\locations.txt");

    //Read the vertex locations
    std::size_t i;
    int x, y;
    int order = Map.get_order();
    for (i = 0; i < order; ++i)
    {
        locFile >> x;
        locFile >> y;
        Map.add_location(i, x, y);
    }

    //Close the locations file
    locFile.close();

    //Calculate distances between vertex locations
    Map.calc_edges_weights();
}

void Game::initVariables()
{
    this->window = nullptr;
    currentVertex = 0;
    goalVertex = 0;
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
    int order = Map.get_order();
    for (std::size_t i = 0; i < order; ++i)
    {
        dist2 = (x - this->Map.xCoord(i)) * (x - this->Map.xCoord(i)) +
                (y - this->Map.yCoord(i)) * (y - this->Map.yCoord(i));
        if (dist2 <= 324)
            std::cout << "Dist: " << Map.dist(0, i) << "\n";
    };
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