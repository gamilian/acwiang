#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = 2 * N;

int n, m, h[N], e[M], ne[M], idx;
int st[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u, int c) {
    st[u] = c;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            if (!dfs(j, 3 - c)) return false;
        } else if (st[j] == c) return false;
    }
    return true;
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    bool flag = true;
    for (int i = 1; i <= n; ++i) {
        if (st[i]) continue;
        if (!dfs(i, 1)) {
            flag = false;
            break;
        }
    }
    if (flag) cout << "Yes";
    else cout << "No";
}