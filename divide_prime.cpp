#include <iostream>

using namespace std;

void divide(int n) {
    for (int i = 2; i <= n / i; ++i) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) n /= i, cnt++;
            cout << i << ' ' << cnt << endl;
        }
    }
    if (n > 1) cout << n << ' ' << 1 << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        divide(x);
        cout << endl;
    }
    return 0;
}