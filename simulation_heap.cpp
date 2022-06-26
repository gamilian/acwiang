#include <iostream>

using namespace std;

const int N = 100010;
//idx表示第几个插入的节点
//ph[i]为idx为i的节点对应堆中的下标
//hp[i]为堆下标为i的节点的idx值
int n, Size, idx, h[N], ph[N], hp[N];

//交换堆中下标为x与y的两个节点
void swap_heap(int x, int y) {
    swap(ph[hp[x]], ph[hp[y]]);
    swap(hp[x], hp[y]);
    swap(h[x], h[y]);
}

void down(int u) {
    int t = u;
    if (u * 2 <= Size && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= Size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (t != u) swap_heap(t, u), down(t);
}

void up(int u) {
    while (u / 2 && h[u] < h[u / 2]) swap_heap(u, u / 2), u /= 2;
}

int main(void) {
    cin >> n;
    while (n--) {
        string op;
        int k, x;
        cin >> op;
        if (op == "I") {
            cin >> x;
            h[++Size] = x;
            ph[++idx] = Size;
            hp[Size] = idx;
            up(Size);
        } else if (op == "PM") {
            cout << h[1] << endl;
        } else if (op == "DM") {
            swap_heap(1, Size--);
            down(1);
        } else if (op == "D") {
            cin >> k;
            swap_heap(ph[k], Size--);
            down(ph[k]), up(ph[k]);
        } else {
            cin >> k >> x;
            h[ph[k]] = x;
            down(ph[k]), up(ph[k]);
        }
    }
    return 0;
}