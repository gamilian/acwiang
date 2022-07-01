#include <iostream>

using namespace std;

typedef long long LL;

const int mod = 1e9 + 7;

int qmi(int m, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1) res = (LL) res * m % p;
        k >>= 1;
        m = (LL) m * m % p;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    int res = 1;
    for (int i = 2 * n, j = 1; j <= n; --i, ++j) {
        res = (LL) res * i % mod;
        res = (LL) res * qmi(j, mod - 2, mod) % mod;
    }
    cout << (LL) res * qmi(n + 1, mod - 2, mod) % mod;
    return 0;
}