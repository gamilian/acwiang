#include <iostream>

using namespace std;

typedef long long LL;

int p;

int qmi(int m, int k, int p) {
    int res = 1 % p;
    while (k) {
        if (k & 1) res = (LL) res * m % p;
        k >>= 1;
        m = (LL) m * m % p;
    }
    return res;
}

int C(int a, int b) {
    if (a < b) return 0;
    int res = 1;
    for (int i = a, j = 1; j <= b; --i, ++j) {
        res = (LL) res * i % p;
        res = (LL) res * qmi(j, p - 2, p) % p;
    }
    return res;
}

int lucas(LL a, LL b) {
    if (a < p && b < p) return C(a, b);
    return (LL) C(a % p, b % p) * lucas(a / p, b / p) % p;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        LL a, b;
        cin >> a >> b >> p;
        cout << lucas(a, b) << endl;
    }
    return 0;
}