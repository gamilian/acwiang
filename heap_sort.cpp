#include <iostream>

using namespace std;

const int N = 100010;
int n, m, Size, h[N];


void down(int u) {
    //t存放当前节点，及其左右孩子的最小值节点的下标
    int t = u;
    if (u * 2 <= Size && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= Size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (t != u) swap(h[t], h[u]), down(t);
}

void up(int u) {
    while (u / 2 && h[u] < h[u / 2]) swap(h[u], h[u / 2]), u /= 2;
}

int main(void) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> h[i];
    Size = n;
    for (int i = n / 2; i > 0; --i) down(i);
    while (m--) {
        swap(h[1], h[Size]);
        cout << h[Size--] << ' ';
        down(1);
    }
    return 0;
}