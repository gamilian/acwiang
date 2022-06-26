#include <iostream>

using namespace std;

const int N = 100010;
int n, m, fa[N], Rank[N], Size[N];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int a, int b) {
    int x = find(a), y = find(b);
    if (x == y) return;
    else {
        if (Rank[x] < Rank[y]) fa[x] = y, Size[y] += Size[x];
        else if (Rank[x] == Rank[y]) fa[x] = y, Size[y] += Size[x], Rank[y]++;
        else fa[y] = x, Size[x] += Size[y];
    }
}

int main(void) {
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) fa[i] = i, Rank[i] = 1, Size[i] = 1;
    while (m--) {
        string op;
        int a, b;
        cin >> op;
        if (op == "C") {
            cin >> a >> b;
            merge(a, b);
        } else if (op == "Q1") {
            cin >> a >> b;
            cout << (find(a) == find(b) ? "Yes" : "No") << endl;
        } else {
            cin >> a;
            cout << Size[find(a)] << endl;
        }
    }

    return 0;
}