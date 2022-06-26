#include <iostream>

using namespace std;
const int N = 160010;

// 扩展域并查集
// x + n为x的食物
// x + n + n为x的天敌

int n, k, res, fa[N];

int find(int x) {
    return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}

int main(void) {
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= 3 * n; ++i) fa[i] = i;
    while (k--) {
        int d, x, y;
        cin >> d >> x >> y;
        if (x > n || y > n) {
            res++;
            continue;
        }
        if (d == 1) {
            // y的食物是x || y的天敌是x
            if (find(x) == find(y + n) || find(x) == find(y + n + n)) {
                res++;
                continue;
            }
            fa[find(x)] = find(y); // x与y同类
            fa[find(x + n)] = find(y + n); // x的食物与y的食物是同类
            fa[find(x + n + n)] = find(y + n + n); // x的天敌与y的天敌是同类
        } else {
            // x与y是同类 || x的天敌与y是同类
            if (find(x) == find(y) || find(x + n + n) == find(y)) {
                res++;
                continue;
            }
            fa[find(x + n)] = find(y); // x的食物与y同类
            fa[find(x + n + n)] = find(y + n); // x的天敌与y的食物是同类
            fa[find(x)] = find(y + n + n); //x与y的天敌是同类
        }
    }
    cout << res << endl;
    return 0;
}