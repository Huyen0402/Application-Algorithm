#include<bits/stdc++.h>

using namespace std;
#define MAX 1001

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

int N, K;
vector<Item> items(MAX);
vector<Container> containers(MAX);

void input() {
	cin >> N >> K;
	for(int i = 0; i < N; i++) {
		cin >> items[i].width >> items[i].length;
		items[i].id = i + 1;
		items[i].rotated = 0;
		items[i].container = -1;
		items[i].x = -1;
		items[i].y = -1;
	}
	for(int i = 0; i < K; i++) {
		cin >> containers[i].width >> containers[i].length >> containers[i].cost;
		containers[i].id = i + 1;
		containers[i].remainingWidth = containers[i].width;
		containers[i].remainingLength = containers[i].length;
	}
}

bool compareItems(const Item& item1, const Item& item2) {
	return (item1.width * item1.length) > (item2.width * item2.length);
}

bool compareContainersCost(const Container& container1, const Container& container2) {
	return container1.cost > container2.cost;
}

bool sortById(const Item& item1, const Item& item2) {
	return (item1.id) > (item2.id);
}

void solve() {
	sort(items.begin(), items.end(), compareItems);
	sort(containers.begin(), containers.end(), compareContainersCost);
	for (int i = 0; i < N; i++) {
        for (int j = K - 1; j >= 0; j--) {
            if (items[i].width <= containers[j].remainingWidth && items[i].length <= containers[j].remainingLength) {
                items[i].container = containers[j].id;
                items[i].x = containers[j].width - containers[j].remainingWidth;
                items[i].y = containers[j].length - containers[j].remainingLength;
                containers[j].remainingWidth -= items[i].width;
                containers[j].remainingLength -= items[i].length;
                break;
            } else if (items[i].length <= containers[j].remainingWidth && items[i].width <= containers[j].remainingLength) {
                items[i].rotated = 1;
                items[i].container = containers[j].id;
                items[i].x = containers[j].width - containers[j].remainingWidth;
                items[i].y = containers[j].length - containers[j].remainingLength;
                containers[j].remainingWidth -= items[i].length;
                containers[j].remainingLength -= items[i].width;
                break;
            }
        }
    }

	sort(items.begin(), items.end(), sortById);

    for (int i = N - 1; i >= 0; i--) {
    	Item item = items[i];
        cout << item.id << " " << item.container << " " << item.x << " " << item.y << " " << item.rotated << endl;
    }
}

int main() {
	input();
	solve();
	
	return 0;
}
