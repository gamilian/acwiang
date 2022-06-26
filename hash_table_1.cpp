#include <iostream>

using namespace std;

const int N = 100003, null = 0x3f3f3f3f;
int n, h[3 * N];

//开方定址法解决冲突
//返回x在哈希表中的位置，或者x需要插入在哈希表位置
int find(int x) {
    int k = (x % N + N) % N;
    while (h[k] != null && h[k] != x) {
        k++;
        if (k == N) k = 0;
    }
    return k;
}

int main(void) {
    cin >> n;
    memset(h, 0x3f, size(h));
    while (n--) {
        char op;
        int x;
        cin >> op >> x;
        int k = find(x);
        if (op == 'I') h[k] = x;
        else {
            if (h[k] == x) cout << "Yes" << endl;
            else cout << " No" << endl;
        }
    }
    return 0;
}