#include "Graph.hpp"

Graph::Graph() {}

Graph::Graph(std::size_t n)
{
    this->order = n;
    edges_matrix = new bool[n * n]{false};
    edges_weights = new float[order * order]{0.0};
}

Graph::~Graph()
{
    delete[] edges_matrix;
    delete[] edges_weights;
}

bool Graph::edge_exists(std::size_t u, std::size_t v) const
{
    return edges_matrix[u * order + v];
}

void Graph::add_edge(std::size_t from, std::size_t to)
{
    edges_matrix[from * order + to] = true;
}

void Graph::add_location(std::size_t vertex, int x, int y)
{
    xCoordinates.push_back(x);
    yCoordinates.push_back(y);
}

void Graph::calc_edges_weights()
{
    size_t i, k;
    float dist;
    for (i = 0; i < order; ++i)
        for (k = 0; k < order; ++k)
            if (edge_exists(i, k))
                edges_weights[i * order + k] = this->dist(i, k);
}

std::size_t Graph::get_order()
{
    return order;
};

float Graph::dist(std::size_t from, std::size_t to)
{
    return sqrt((xCoord(from)- xCoord(to)) * (xCoord(from)- xCoord(to)) +
                (yCoord(from)- yCoord(to)) * (yCoord(from)- yCoord(to)));;
}

int Graph::xCoord(std::size_t vertex)
{
    return xCoordinates[vertex];
}

int Graph::yCoord(std::size_t vertex)
{
    return yCoordinates[vertex];
}

std::vector<std::size_t> Graph::successors(std::size_t v) const
{
    std::vector<std::size_t> suc;
    for (std::size_t to = 0; to < order; ++to)
        if (edge_exists(v, to))
            suc.push_back(to);
    return suc;
}