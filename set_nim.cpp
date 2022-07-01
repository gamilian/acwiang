#include <iostream>
#include <cstring>
#include <unordered_set>

using namespace std;

const int N = 110, M = 10010;

int n, k, s[N], f[M];

int sg(int x) {
    if (f[x] != -1) return f[x];
    //S集合存放节点x的所有后继节点的SG函数值
    unordered_set<int> S;
    for (int i = 0; i < k; i++)
        if (x >= s[i]) S.insert(sg(x - s[i]));
    //从S集合中找到最小的没有出现在该集合中的非负整数,就是节点x的SG函数值，即Mex(S)
    for (int i = 0;; i++)
        if (!S.count(i)) return f[x] = i;
}

int main() {
    cin >> k;
    for (int i = 0; i < k; i++) cin >> s[i];
    cin >> n;
    memset(f, -1, sizeof f);
    int res = 0;
    while (n--) {
        int x;
        cin >> x;
        res ^= sg(x);
    }
    if (res) cout << "Yes";
    else cout << "No";
    return 0;
}