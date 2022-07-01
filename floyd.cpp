#include <iostream>
#include <cstring>

using namespace std;

const int N = 210, INF = 1e9 + 10;
int n, m, q, d[N][N];

void floyd() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i != j) d[i][j] = INF;
        }
    }
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        d[x][y] = min(d[x][y], z);
    }
    floyd();
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (d[x][y] > INF / 2) cout << "impossible" << endl;
        else cout << d[x][y] << endl;
    }

    return 0;
}
