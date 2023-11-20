#include <vector>

#include <fstream>

class Graph {
public:
    Graph();

    Graph(std::size_t n);

    ~Graph();

    bool edge_exists(std::size_t from, std::size_t to) const;
    void add_edge(std::size_t from, std::size_t to);
    void add_location(std::size_t vertex, int x, int y);
    std::size_t get_order();
    int xCoord(std::size_t vertex);
    int yCoord(std::size_t vertex);

    std::vector<std::size_t> successors(std::size_t v) const;

private:
    std::size_t order;
    bool* matrix;
    std::vector<int> xCoordinates;
    std::vector<int> yCoordinates;
    int* visited;
};
