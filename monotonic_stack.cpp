#include <iostream>

using namespace std;

int stk[100010], top = -1;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        while (top > -1 && stk[top] >= x) top--;
        if (top == -1) cout << "-1 ";
        else cout << stk[top] << ' ';
        stk[++top] = x;
    }
    return 0;
}