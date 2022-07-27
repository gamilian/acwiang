#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, INF = 1e9;

int n, a[N], f[N];

int main() {
    cin >> n;
    for (int i = 0; i <= n + 1; i++) f[i] = -INF;
    cin >> f[1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) cin >> a[j];
        for (int j = i; j >= 1; j--) f[j] = max(f[j - 1], f[j]) + a[j];
    }
    int res = -INF;
    for (int i = 1; i <= n; i++) res = max(f[i], res);
    cout << res;
    return 0;
}