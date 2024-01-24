#include <bits/stdc++.h>
      
using namespace std;

int n, m, i, j, heap_size = 0;
vector<int> c, d, shortest_to, heap, idx;
vector<bool> done;
vector<vector<int>> adj, cost, reachable;
vector<vector<bool>> traveled;

void input() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    c.resize(n + 1);
    d.resize(n + 1);
    shortest_to.resize(n + 1, INT32_MAX);
    adj.resize(n + 1);
    heap.resize(n + 1);
    idx.resize(n + 1, -1);
    reachable.resize(n + 1);
    cost.resize(n + 1, vector<int>(n + 1, INT32_MAX));
    traveled.resize(n + 1, vector<bool>(n + 1, false));

    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> d[i];
    }
    for (int t = 0; t < m; t++) {
        cin >> i >> j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
}

void travel(int from, int dest, int c, int remain_d) {
    if (traveled[from][dest]) {
        return;
    }

    traveled[from][dest] = true;
    cost[from][dest] = c;
    reachable[from].push_back(dest);

    if (remain_d > 1) {
        for (int to : adj[dest]) {
            travel(from, to, c, remain_d - 1);
        }
    }
}

void precompute() {
    for (int i = 1; i <= n; i++) {
        traveled[i][i] = true;
        cost[i][i] = 0;
        for (int to : adj[i]) {
            travel(i, to, c[i], d[i]);
        }
    }
}

void swap_heap(int i, int j) {
    swap(heap[i], heap[j]);
    idx[heap[i]] = i;
    idx[heap[j]] = j;
}

void up_heap(int i) {
    int p = i / 2;
    if (i > 1 && shortest_to[i] < shortest_to[p]) {
        swap_heap(i, p);
        up_heap(p);
    }
}

void down_heap(int i) {
    int l = i * 2, r = i * 2 + 1, next = i;
    if (l <= heap_size && shortest_to[l] < shortest_to[next]) {
        next = l;
    }
    if (r <= heap_size && shortest_to[r] < shortest_to[next]) {
        next = r;
    }
    if (i != next) {
        swap_heap(i, next);
        down_heap(next);
    }
}

void insert_heap(int u) {
    heap_size++;

    heap[heap_size] = u;
    idx[u] = heap_size;

    up_heap(heap_size);
}

int pop_heap() {
    if (heap_size == 0) {
        cout << "err";
    }
    int ans = heap[1];

    swap_heap(1, heap_size);
    heap_size--;
    down_heap(1);

    return ans;
}

void dijkstra() {
    done.resize(n + 1, false);
    done[1] = true;
    shortest_to[1] = 0;
    insert_heap(1);

    while (!done[n] && heap_size) {
        int u = pop_heap();
        done[u] = true;
        for (int v : reachable[u]) {
            if (done[v]) {
                continue;
            }

            int tmp_d = shortest_to[u] + cost[u][v];
            if (tmp_d < shortest_to[v]) {
                shortest_to[v] = tmp_d;
                if (idx[v] != -1) {
                    up_heap(idx[v]);
                } else {
                    insert_heap(v);
                }
            }
        }
    }
}

int main() {
    input();
    precompute();
    dijkstra();

    cout << shortest_to[n];
}

/**
 * Ý tưởng giải thuật:
 * 1. Tính toán trước, sử dụng đệ quy để tìm chi phí nhỏ nhất để đi từ thành phố i đến thành phố j với đúng 1 lần lên bus.
 * 2. Khi này bài toán đã trở về bài toán tìm đường đi ngắn nhất trong đồ thị CÓ HƯỚNG. Sử dụng thuật toán Dijkstra để tính
 */