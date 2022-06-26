#include <iostream>

using namespace std;

const int N = 100010, M = 31 * N;
int son[M][2], idx;

void insert(int x) {
    int p = 0;
    for (int i = 30; i >= 0; --i) {
        int u = x >> i & 1;
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
}

int query(int x) {
    int p = 0, res = 0;
    for (int i = 30; i >= 0; --i) {
        int u = x >> i & 1;
        if (son[p][!u]) {
            res = 2 * res + 1;
            p = son[p][!u];
        } else {
            res *= 2;
            p = son[p][u];
        }
    }
    return res;
}


int main(void) {
    cin.tie(0);
    int n, a[N];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        insert(a[i]);
    }
    int res = 0;
    for (int i = 0; i < n; ++i) res = max(res, query(a[i]));
    cout << res << endl;
    return 0;
}