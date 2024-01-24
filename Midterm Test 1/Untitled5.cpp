#include <iostream>
#include <vector>
#include <algorithm>

void delete_min(std::vector<int>& D) {
    if (!D.empty()) {
        int minElement = std::min_element(D.begin(), D.end());
        std::cout << *minElement << std::endl;
        D.erase(minElement);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::vector<int> D;
    std::string cmd;
    int e;

    do {
        std::cin >> cmd;
        if (cmd == "PUSH") {
            std::cin >> e;
            D.emplace_back(e);
        }

        if (cmd == "POP") {
            delete_min(D);
        }
    } while (cmd != "#");

    return 0;
}
