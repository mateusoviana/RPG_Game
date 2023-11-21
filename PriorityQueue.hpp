#include <vector>
#include <stdexcept>

class PriorityQueue {
private:
    std::vector<std::pair<int, float>> heap; // pair: (number, weight)

    void siftUp(int index);

    void siftDown(int index);

public:
    void push(int number, float weight);

    int pop();

    bool empty() const;
};