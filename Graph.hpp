#include <vector>

#include <fstream>

class Graph {
public:
    Graph();

    Graph(std::size_t n);

    ~Graph();

    std::size_t order;
    std::vector<int> xCoordinates;
    std::vector<int> yCoordinates;

    bool edge_exists(std::size_t from, std::size_t to) const;
    void add_edge(std::size_t from, std::size_t to);
    void add_location(std::size_t vertex, int x, int y);

    std::vector<std::size_t> successors(std::size_t v) const;

private:
    bool* matrix;
    int* visited;
};
