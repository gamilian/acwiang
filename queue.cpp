#include <iostream>

using namespace std;

int q[100010], head, tail = -1;

int main() {
    int m;
    cin >> m;
    while (m--) {
        string op;
        int x;
        cin >> op;
        if (op == "push") {
            cin >> x, q[++tail] = x;
        } else if (op == "pop") {
            ++head;
        } else if (op == "empty") {
            if (head <= tail) cout << "NO" << endl;
            else cout << "YES" << endl;
        } else {
            cout << q[head] << endl;
        }

    }
    return 0;
}