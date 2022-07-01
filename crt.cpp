#include <iostream>

using namespace std;

typedef long long LL;
const int N = 30;

int a[N], m[N];

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
    LL res = 0, cnt = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m[i] >> a[i];
        cnt *= m[i];
    }

    for (int i = 0; i < n; i++) {
        LL Mi, x, y;
        Mi = cnt / m[i];
        exgcd(Mi, m[i], x, y);
        x %= m[i];
        res += a[i] * Mi % cnt * x % cnt;
    }
    cout << res % cnt;
    return 0;
}