#include <iostream>

using namespace std;

typedef long long LL;

LL exgcd(LL a, LL b, LL &x, LL &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    LL d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main() {
    int n;
    LL a1, m1;
    cin >> n;
    cin >> a1 >> m1;
    for (int i = 0; i < n - 1; i++) {
        LL a2, m2;
        cin >> a2 >> m2;
        LL k1, k2;
        LL d = exgcd(a1, a2, k1, k2);

        if ((m2 - m1) % d) {
            cout << "-1";
            return 0;
        }
        LL mod = a2 / d;
        k1 = (k1 * (m2 - m1) / d % mod + mod) % mod;
        m1 = k1 * a1 + m1;
        a1 = a1 / d * a2;
    }
    cout << m1 << endl;
    return 0;
}