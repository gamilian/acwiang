#include <iostream>
#include <cstring>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e5 + 10, M = 2 * N;

int n, m, h[N], d[N], e[M], ne[M], idx;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(int u) {
    memset(d, -1, sizeof d);
    d[1] = 0;
    queue<int> q;
    q.push(u);
    while (q.size()) {
        int t = q.front();
        q.pop();
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[j] != -1) continue;
            q.push(j);
            d[j] = d[t] + 1;
        }
    }
}

int main() {
    memset(h, -1, sizeof h);
    d[0] = 0;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    bfs(1);
    cout << d[n];
    return 0;
}