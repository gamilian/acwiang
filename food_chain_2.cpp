#include <iostream>

using namespace std;

const int N = 50010;
// 带权并查集(有向带权图)
// x与y的距离%3等于0时,说明x和y是同类
// x与y的距离%3等于1时,说明x捕食y
// x与y的距离%3等于2时,说明y是x的天敌
// dis[x]表示x到其父节点的距离：
// 1、压缩路径后即为到跟节点的距离
// 2、未merge时候为到父节点的距离
int n, k, res, fa[N], dis[N];

int find(int x) {
    if (fa[x] != x) {
        int root = find(fa[x]);
        dis[x] = (dis[x] + dis[fa[x]] + 3) % 3;
        fa[x] = root;
    }
    return fa[x];
}

// t为x与y之间的关系
// 每次merge时fa[x]到fa[b]的距离未知
// (dis[x] + dis[px] - dis[y]) % 3 = t (有向图，经过路经压缩后dis[y]为y到py之间的距离，py到y的距离为-dis[y])
// => dis[px] = (t + dis[y] - dis[x]) % 3
bool merge(int x, int y, int t) {
    int px = find(x), py = find(y);
    if (px == py) return dis[x] % 3 == (t + dis[y]) % 3;
    fa[px] = py;
    dis[px] = (t + dis[y] - dis[x] + 3) % 3;
    return true;
}

int main() {
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i <= n; ++i) fa[i] = i;
    while (k--) {
        int d, x, y;
        cin >> d >> x >> y;
        if (x > n || y > n) {
            res++;
            continue;
        }
        if (d == 1) {
            if (!merge(x, y, 0)) res++;
        } else {
            if (!merge(x, y, 1)) res++;
        }
    }
    cout << res << endl;
    return 0;
}