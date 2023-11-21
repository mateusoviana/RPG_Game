#include <vector>
#include <stack>
#include <cmath>
#include <limits>
#include "PriorityQueue.hpp"

#include <fstream>

class Graph {
public:
    Graph();

    Graph(std::size_t n);

    ~Graph();

    size_t currentVertex = 0;
    size_t goalVertex = 0;

    bool edge_exists(std::size_t from, std::size_t to) const;
    void add_edge(std::size_t from, std::size_t to);
    void add_location(std::size_t vertex, int x, int y);
    float dist(std::size_t from, std::size_t to);
    void calc_edges_weights();
    float edge_weight(std::size_t from, std::size_t to) const;

    std::size_t get_order();
    int xCoord(std::size_t vertex);
    int yCoord(std::size_t vertex);

    std::stack<size_t> aStarSearch(size_t current, size_t goal);

    std::vector<std::size_t> successors(std::size_t v) const;

private:
    std::size_t order;
    bool* edges_matrix;
    float* edges_weights;
    std::vector<int> xCoordinates;
    std::vector<int> yCoordinates;
};
