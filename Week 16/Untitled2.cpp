#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int id;
    int width;
    int length;
    int rotated;
    int container;
    int x;
    int y;
};

struct Container {
    int id;
    int width;
    int length;
    int cost;
    int remainingWidth;
    int remainingLength;
};

bool compareItems(const Item& item1, const Item& item2) {
    return (item1.width * item1.length) > (item2.width * item2.length);
}

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<Item> items(N);
    for (int i = 0; i < N; i++) {
        std::cin >> items[i].width >> items[i].length;
        items[i].id = i + 1;
        items[i].rotated = 0;
        items[i].container = -1;
        items[i].x = -1;
        items[i].y = -1;
    }

    std::vector<Container> containers(K);
    for (int i = 0; i < K; i++) {
        std::cin >> containers[i].width >> containers[i].length >> containers[i].cost;
        containers[i].id = i + 1;
        containers[i].remainingWidth = containers[i].width;
        containers[i].remainingLength = containers[i].length;
    }

    std::sort(items.begin(), items.end(), compareItems);

    for (int i = 0; i < items.size(); i++) {
    	Item item = items[i];
        bool itemPlaced = false;
        for (int j = 0; j < containers.size(); j++) {
        	Container container = containers[j];
            if (item.width <= container.remainingWidth && item.length <= container.remainingLength) {
                item.container = container.id;
                item.x = container.width - container.remainingWidth;
                item.y = container.length - container.remainingLength;
                container.remainingWidth -= item.width;
                container.remainingLength -= item.length;
                itemPlaced = true;
                break;
            } else if (item.length <= container.remainingWidth && item.width <= container.remainingLength) {
                item.rotated = 1;
                item.container = container.id;
                item.x = container.width - container.remainingWidth;
                item.y = container.length - container.remainingLength;
                container.remainingWidth -= item.length;
                container.remainingLength -= item.width;
                itemPlaced = true;
                break;
            }
        }

        if (!itemPlaced) {
            Container newContainer = containers.back();
            containers.pop_back();
            item.container = newContainer.id;
            item.x = 0;
            item.y = 0;
            item.rotated = 0;
            newContainer.remainingWidth -= item.width;
            newContainer.remainingLength -= item.length;
            containers.push_back(newContainer);
        }
    }

    int totalCost = 0;
    for (int j = 0; j < containers.size(); j++) {
        Container container = containers[j];
        totalCost += container.cost;
    }

    for (int i = 0; i < items.size(); i++) {
    	Item item = items[i];
        std::cout << item.id << " " << item.container << " " << item.x << " " << item.y << " " << item.rotated << std::endl;
    }

    return 0;
}
