#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 100010, M = 2 * N;

int n, m, h[N], q[N], d[N], e[M], ne[M], idx;
bool st[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topological_sort() {
    int head = 0, tail = -1;
    for (int i = 1; i < n; ++i)
        if (!d[i]) q[++tail] = i;
    while (head <= tail) {
        int t = q[head++];
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (--d[j] == 0) q[++tail] = j;
        }
    }
    return tail == n - 1;
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }
    if (!topological_sort()) cout << "-1";
    else {
        for (int i = 0; i < n; ++i)
            cout << q[i] << ' ';
    }
}