#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e5 + 10;
int n, m, d[N], h[N], e[N], w[N], ne[N], idx;
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void spfa() {
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    queue<int> q;
    q.push(1);
    st[1] = true;
    while (q.size()) {
        int t = q.front();
        q.pop();
        // 从队列中取出来之后该节点st被标记为false,代表之后该节点如果发生更新可再次入队
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[j] > d[t] + w[i]) {
                d[j] = d[t] + w[i];
                if (st[j]) continue;
                q.push(j);
                st[j] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof d);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    spfa();
    if (d[n] == 0x3f3f3f3f) cout << "impossible";
    else cout << d[n];
}