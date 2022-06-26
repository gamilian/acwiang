#include <bits/stdc++.h>

using namespace std;

char s[1000010], p[1000010];
int ne[1000010], n, m;


int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    cin >> m;
    for (int i = 1; i <= m; ++i) cin >> s[i];
    for (int i = 2, j = 0; i <= n; ++i) {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j++;
        // 若ne[i] = j, 表示以i为结尾的, 长度是j的串 和 从1开始, 长度为j的串相等, 即p[1, j] = p[i - j + 1, i]
        ne[i] = j;
    }

    for (int i = 1, j = 0; i <= m; ++i) {
        // j初始等于0, 每次匹配p[j + 1]
        // p[j]及之前为已经匹配成功的节点, p[j + 1]为正在匹配的节点
        // ne[j]表示j + 1匹配失败时, 需要j回退到哪里开始匹配(匹配ne[j] + 1)
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j++;
        if (j == n) {
            cout << i - n << ' ';
            j = ne[j];
        }
    }
    return 0;
}