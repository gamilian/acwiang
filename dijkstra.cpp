#include <iostream>
#include <cstring>

using namespace std;

const int N = 510;

int n, m, g[N][N], d[N];
bool st[N];

int dijkstra() {
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    for (int i = 1; i <= n; ++i) {
        // t为未被访问中距离最小的一个点
        int t = -1;
        for (int j = 1; j <= n; ++j) {
            if (!st[j] && (t == -1 || d[j] < d[t])) t = j;
        }
        // 访问t，并更新所有以t为中介节点的最短距离
        st[t] = true;
        for (int j = 2; j <= n; ++j)
            d[j] = min(d[j], d[t] + g[t][j]);
        if (t == n) break;
    }
    return d[n] == 0x3f3f3f3f ? -1 : d[n];
}

int main() {
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    while (m--) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a][b] = min(g[a][b], w);
    }
    cout << dijkstra();
    return 0;
}