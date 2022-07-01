#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10, INF = 0x3f3f3f3f;

struct Edge {
    int u, v, w;

    bool operator<(const Edge &E) const {
        return w < E.w;
    }
} edges[N];

int n, m, fa[N];

int find(int x) {
    return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}

int kruskal() {
    int res = 0, cnt = 0;
    for (int i = 0; i < m; ++i) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        u = find(u), v = find(v);
        if (u != v) fa[u] = v, res += w, cnt++;
    }
    if (cnt != n - 1) return INF;
    else return res;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) fa[i] = i;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u == v) continue;
        edges[i] = {u, v, w};
    }
    sort(edges, edges + m);
    int t = kruskal();
    if (t == INF) cout << "impossible";
    else cout << t;
    return 0;
}