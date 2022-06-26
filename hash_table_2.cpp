#include <iostream>

using namespace std;

const int N = 100003;
int h[N], e[N], ne[N], n, idx;

void insert(int x) {
    int k = (x % N + N) % N;
    e[idx] = x, ne[idx] = h[k], h[k] = idx++;
}

bool find(int x) {
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i]) {
        if (e[i] == x) return true;
    }
    return false;
}

int main() {
    cin >> n;
    memset(h, -1, size(h));
    memset(ne, -1, size(ne));
    while (n--) {
        char op;
        int x;
        cin >> op >> x;
        if (op == 'I') insert(x);
        else {
            if (find(x)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}