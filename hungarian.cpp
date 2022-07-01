#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = 2 * N;

int n1, n2, m, match[N], h[N], e[M], ne[M], idx;
bool st[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int find(int x) {
    for (int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        if (st[j]) continue;
        st[j] = true;
        if (!match[j] || find(match[j])) {
            match[j] = x;
            return true;
        }
    }
    return false;
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n1 >> n2 >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    int res = 0;
    for (int i = 1; i <= n1; ++i) {
        memset(st, false, sizeof st);
        if (find(i)) res++;
    }
    cout << res;
    return 0;
}