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
            hp[++Size] = ++idx;
            h[Size] = x;
            ph[idx] = Size;
            up(Size);
        } else if (op == "PM") {
            cout << h[1] << endl;
        } else if (op == "DM") {
            swap_heap(1, Size--);
            down(1);
        } else if (op == "D") {
            cin >> k;
            // 必须先保存ph[k]，不然swap_heap之后ph[k]就变了，这样down与up时候的ph[k]就是修改过的值
            // 故，下面注释代码就是错误的
            // swap_heap(ph[k], Size--);
            // down(ph[k]), up(ph[k]);
            k = ph[k];
            swap_heap(k, Size--);
            down(k), up(k);
        } else {
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            down(k), up(k);
        }
    }
    return 0;
}