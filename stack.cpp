#include <iostream>

using namespace std;

int stk[100010], top = -1;

int main() {
    int m;
    cin >> m;
    while (m--) {
        string op;
        int x;
        cin >> op;
        if (op == "push") {
            cin >> x, stk[++top] = x;
        } else if (op == "pop") {
            top--;
        } else if (op == "empty") {
            if (top == -1) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else {
            cout << stk[top] << endl;
        }

    }
    return 0;
}