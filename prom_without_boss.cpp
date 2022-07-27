#include <iostream>
#include <cstring>

using namespace std;

const int N = 6010;

int n, h[N], e[N], ne[N], idx;
int happy[N], fa[N], f[N][2];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u) {
    f[u][1] = happy[u];
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        dfs(j);
        f[u][1] += f[j][0];
        f[u][0] += max(f[j][1], f[j][0]);
    }
}

int main() {
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++) cin >> happy[i];
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        add(b, a);
        fa[a] = b;
    }
    int root = 1;
    while (fa[root]) root = fa[root];
    dfs(root);
    cout << max(f[root][1], f[root][0]);
    return 0;
}