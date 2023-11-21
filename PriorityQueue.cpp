#include "PriorityQueue.hpp"

void PriorityQueue::siftUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index].second < heap[parent].second) {
            std::swap(heap[index], heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void PriorityQueue::siftDown(int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild < heap.size() && heap[leftChild].second < heap[smallest].second) {
        smallest = leftChild;
    }

    if (rightChild < heap.size() && heap[rightChild].second < heap[smallest].second) {
        smallest = rightChild;
    }

    if (smallest != index) {
        std::swap(heap[index], heap[smallest]);
        siftDown(smallest);
    }
}

void PriorityQueue::push(int number, float weight) {
    heap.emplace_back(number, weight);
    siftUp(heap.size() - 1);
}

int PriorityQueue::pop() {
    if (empty()) {
        throw std::out_of_range("Priority queue is empty");
    }

    std::pair<int, float> topElement = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    siftDown(0);

    return topElement.first;
}

bool PriorityQueue::empty() const {
    return heap.empty();
}