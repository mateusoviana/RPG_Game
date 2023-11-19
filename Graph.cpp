#include "Graph.hpp"

Graph::Graph() {}

Graph::Graph(std::size_t n)
{
    this->order = n;
    this->matrix = new bool[n * n]{false};
}

Graph::~Graph()
{
    delete[] matrix;
}

bool Graph::edge_exists(std::size_t u, std::size_t v) const
{
    return matrix[u * order + v];
}

void Graph::add_edge(std::size_t from, std::size_t to)
{
    matrix[from * order + to] = true;
}

void Graph::add_location(std::size_t vertex, int x, int y)
{
    xCoordinates.push_back(x);
    yCoordinates.push_back(y);
}

std::vector<std::size_t> Graph::successors(std::size_t v) const
{
    std::vector<std::size_t> suc;
    for (std::size_t to = 0; to < order; ++to)
        if (edge_exists(v, to))
            suc.push_back(to);
    return suc;
}