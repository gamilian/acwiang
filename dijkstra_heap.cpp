#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 150010, M = 2 * N;

typedef pair<int, int> PII;
int n, m, d[N], h[N], e[M], w[M], ne[M], idx;
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra() {
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    heap.push({d[1], 1});
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        int ver = t.second, dis = t.first;
        if (st[ver]) continue;
        st[ver] = true;
        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[j] > d[ver] + w[i]) {
                d[j] = d[ver] + w[i];
                heap.push({d[j], j});
            }
        }
    }
    return d[n] == 0x3f3f3f3f ? -1 : d[n];
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    cout << dijkstra();
    return 0;
}