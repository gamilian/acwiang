#include <iostream>

using namespace std;

typedef long long LL;

int qmi(int m, int k, int p) {
    int res = 1 % p;
    while (k) {
        if (k & 1) res = (LL) res * m % p;
        m = (LL) m * m % p;
        k >>= 1;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int m, k, p;
        cin >> m >> k >> p;
        cout << qmi(m, k, p) << endl;
    }
    return 0;
}