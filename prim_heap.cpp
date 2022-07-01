#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

//考虑无向图M = 4 * N
const int N = 1e5 + 10, M = 4 * N, INF = 0x3f3f3f3f;

typedef pair<int, int> PII;
int n, m, h[N], e[M], w[M], ne[M], idx;
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int prim() {
    int res = 0, cnt = 0;
    priority_queue<PII, vector<PII>, greater<> > heap;
    heap.push({0, 1});
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        int dis = t.first, ver = t.second;
        if (st[ver]) continue;
        st[ver] = true, res += dis, cnt++;
        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (st[j]) continue;
            heap.push({w[i], j});
        }
    }
    if (cnt != n) return INF;
    return res;
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        // 最小生成树不考虑自环
        if (a == b) continue;
        add(a, b, c);
        add(b, a, c);
    }
    int t = prim();
    if (t == INF) cout << "impossible";
    else cout << t;
    return 0;
}