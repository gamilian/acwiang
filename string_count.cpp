#include <iostream>

using namespace std;

const int N = 100010;
int son[N][26], cnt[N], idx;

void insert(string str) {
    int p = 0;
    for (auto const &ch: str) {
        int u = ch - 'a';
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(string str) {
    int p = 0;
    for (auto const &ch: str) {
        int u = ch - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}


int main() {
    int n;
    string str;
    cin >> n;
    while (n--) {
        char op;
        cin >> op >> str;
        if (op == 'I') insert(str);
        else cout << query(str) << endl;
    }
    return 0;
}