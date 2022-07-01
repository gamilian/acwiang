#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010, M = N * 2;

int n, h[N], e[M], ne[M], idx, ans = N;
bool st[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u) {
    st[u] = true;
    int size = 0, sum = 1;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (st[j]) continue;
        int s = dfs(j);
        size = max(size, s);
        sum += s;
    }
    size = max(size, n - sum);
    ans = min(ans, size);
    return sum;
}


int main() {
    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1);
    cout << ans;
    return 0;
}