#include <iostream>

using namespace std;

const int N = 100010;
int n, m, fa[N], Rank[N];

int find(int x) {
    //while (p[x] != x) x = p[x];

    //路径压缩
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int a, int b) {
    int x = find(a), y = find(b);
    if (x == y) return;
    else {
        //按秩合并
        if (Rank[x] < Rank[y]) fa[x] = y;
        else if (Rank[x] == Rank[y]) fa[x] = y, Rank[y]++;
        else fa[y] = x;
    }
}

int main() {
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) fa[i] = i, Rank[i] = 1;
    while (m--) {
        char op;
        int a, b;
        cin >> op >> a >> b;
        if (op == 'M') merge(a, b);
        else cout << (find(a) == find(b) ? "Yes" : "No") << endl;
    }
    return 0;
}