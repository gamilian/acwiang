#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10, mod = 1e9 + 7;

int fact[N], infact[N];

LL qmi(int m, int k, int p) {
    LL res = 1 % p;
    while (k) {
        if (k & 1) res = (LL) res * m % p;
        k >>= 1;
        m = (LL) m * m % p;
    }
    return res;
}

void init() {
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = (LL) fact[i - 1] * i % mod;
        infact[i] = (LL) infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }
}

int main() {
    init();
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << (LL) fact[a] * infact[a - b] % mod * infact[b] % mod << endl;
    }
    return 0;
}