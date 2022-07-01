#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m, d[N], g[N][N];
bool st[N];

int prim() {
    memset(d, 0x3f, sizeof d);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int t = -1;
        for (int j = 1; j <= n; ++j)
            if (!st[j] && (t == -1 || d[t] > d[j])) t = j;
        if (i && d[t] == INF) return INF;
        if (i) res += d[t];
        st[t] = true;
        for (int j = 1; j <= n; ++j) d[j] = min(d[j], g[j][t]);
    }
    return res;
}


int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j) g[i][j] = INF;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = min(g[u][v], w);
    }
    int t = prim();
    if (t == INF) cout << "impossible";
    else cout << t;
}