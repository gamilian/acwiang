#include <iostream>

using namespace std;

typedef long long LL;

int qmi(int m, int k, int p) {
    int res = 1 % p;
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
    while (n--) {
        int a, p;
        cin >> a >> p;
        if (a % p) cout << qmi(a, p - 2, p) << endl;
        else cout << "impossible" << endl;
    }
    return 0;
}