#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, M = 10010;
struct Edge {
    int a, b, w;
} edge[M];
int n, m, k, d[N], last_d[N];

void bellman_ford() {
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    for (int i = 1; i <= k; ++i) {
        memcpy(last_d, d, sizeof d);
        for (int j = 0; j < m; ++j) {
            auto e = edge[j];
            d[e.b] = min(d[e.b], last_d[e.a] + e.w);
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {a, b, c};
    }
    bellman_ford();
    if (d[n] > 0x3f3f3f3f / 2) cout << "impossible";
    else cout << d[n];
    return 0;
}