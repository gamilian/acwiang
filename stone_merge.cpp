#include <iostream>
#include <cstring>

using namespace std;

const int N = 310, INF = 1e9;

int n, s[N], f[N][N];

int dp(int i, int j) {
    if (i >= j) return 0;
    int &v = f[i][j];
    if (v != -1) return v;
    v = INF;
    for (int k = i; k < j; k++) v = min(v, dp(i, k) + dp(k + 1, j) + s[j] - s[i - 1]);
    return v;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) s[i] += s[i - 1];
    memset(f, -1, sizeof f);
    cout << dp(1, n);
    return 0;
}