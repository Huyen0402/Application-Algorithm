#include <iostream>
#include <vector>
#include <algorithm>

void heapify(std::vector<int>& heap, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] < heap[smallest]) {
        smallest = left;
    }

    if (right < n && heap[right] < heap[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        std::swap(heap[i], heap[smallest]);
        heapify(heap, n, smallest);
    }
}

void deleteMin(std::vector<int>& heap) {
    int n = heap.size();
    if (n == 0) {
        std::cout << "Heap is empty." << std::endl;
        return;
    }

    int minElement = heap[0];

    heap[0] = heap[n - 1];
    heap.pop_back();

    heapify(heap, heap.size(), 0);

    std::cout << minElement << std::endl;
}

int main() {
    std::vector<int> heap;
    std::string cmd;
    int e;

    do {
        std::cin >> cmd;

        if (cmd == "PUSH") {
            std::cin >> e;
            heap.push_back(e);
            std::push_heap(heap.begin(), heap.end(), std::greater<int>());
        } else if (cmd == "POP") {
            deleteMin(heap);
        }
    } while (cmd != "#");

    return 0;
}
