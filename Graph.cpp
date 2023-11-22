#include "Graph.hpp"

Graph::Graph()
{
    //Open the graph file
    std::ifstream graphFile("C:\\RPG_Game\\edges.txt");

    //Read the number of vertex of the map and create the map graph
    size_t n;
    graphFile >> n;
    order = n;
    currentVertex = 0;
    goalVertex = 0;

    //Read and create the graph edges
    int edge;
    for (std::size_t i = 0; i < order; ++i)
        for (std::size_t k = 0; k < order; ++k)
        {
            graphFile >> edge;
            if (edge == 1)
                edges_matrix.push_back(true);
            else edges_matrix.push_back(false);
        }

    //Close the graph file
    graphFile.close();
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

float Graph::dist(std::size_t from, std::size_t to)
{
    return sqrt((xCoord(from)- xCoord(to)) * (xCoord(from)- xCoord(to)) +
                (yCoord(from)- yCoord(to)) * (yCoord(from)- yCoord(to)));;
}

void Graph::calc_edges_weights()
{
    size_t i, k;
    for (i = 0; i < order; ++i)
        for (k = 0; k < order; ++k)
            if (edge_exists(i, k))
                edges_weights.push_back(this->dist(i, k));
            else edges_weights.push_back(0.0);
}

float Graph::edge_weight(std::size_t from, std::size_t to) const
{
    return edges_weights[from * order + to];
}

std::size_t Graph::get_order()
{
    return order;
};

int Graph::xCoord(std::size_t vertex)
{
    return xCoordinates[vertex];
}

int Graph::yCoord(std::size_t vertex)
{
    return yCoordinates[vertex];
}

void Graph::locConfig()
{
    //Open the locations file
    std::ifstream locFile("C:\\RPG_Game\\locations.txt");

    //Read the vertex locations
    ;
    int x, y;
    for (std::size_t i = 0; i < order; ++i)
    {
        locFile >> x;
        locFile >> y;
        add_location(i, x, y);
    }

    //Close the locations file
    locFile.close();

    //Calculate distances between vertex locations
    calc_edges_weights();
}

void Graph::aStarSearch(std::size_t from, std::size_t goal)
{
    PriorityQueue priorityQueue;
    priorityQueue.push(from, 0.0);

    std::size_t* cameFrom;
    cameFrom = new size_t[order];
    cameFrom[from] = from;

    float* cost;
    float infinity = std::numeric_limits<float>::infinity();
    cost = new float[order];
    for (size_t i = 0; i < order; ++i)
        cost[i] = infinity;

    cost[from] = 0;

    size_t current;

    while (!priorityQueue.empty())
    {
        current = priorityQueue.pop();

        if (current == goal)
            break;

        std::vector<std::size_t> suc = successors(current);

        for (size_t k = 0; k < suc.size(); ++k)
        {
            size_t next = suc[k];

            float newCost = cost[current] + edge_weight(current, next);
            if (newCost < cost[next])
            {
                cost[next] = newCost;
                float priority = newCost + dist(goal, next);
                priorityQueue.push(next, priority);
                cameFrom[next] = current;
            }
        }
    }

    std::stack<std::size_t> path;

    while (current != from)
    {
        path.push(current);
        current = cameFrom[current];
    }

    delete cameFrom;
    delete cost;

    while (!path.empty())
    {
        std::cout << path.top() + 1 << " ";
        path.pop();
    }
    std::cout << "\n";
}

std::vector<std::size_t> Graph::successors(std::size_t v) const
{
    std::vector<std::size_t> suc;
    for (std::size_t to = 0; to < order; ++to)
        if (edge_exists(v, to))
            suc.push_back(to);
    return suc;
}