#include <iostream>
#include <cstring>

using namespace std;

const int N = 310;

int n, m, w[N][N], f[N][N];

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int dp(int i, int j) {
    if (f[i][j] != -1) return f[i][j];
    int &v = f[i][j];
    v = 1;
    for (int t = 0; t < 4; t++) {
        int a = i + dx[t], b = j + dy[t];
        if (a >= 1 && a <= n && b >= 1 && b <= m && w[i][j] > w[a][b])
            v = max(v, dp(a, b) + 1);
    }
    return v;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> w[i][j];
    memset(f, -1, sizeof f);
    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            res = max(res, dp(i, j));
    cout << res;
    return 0;
}