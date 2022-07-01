#include <iostream>

using namespace std;

const int N = 1000010;

int prime[N], cnt;
bool st[N];

void get_prime(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            prime[cnt++] = i;
            for (int j = i; j <= n; j += i) st[j] = true;
        }
    }
}

int main() {
    int n;
    cin >> n;
    get_prime(n);
    cout << cnt;
    return 0;
}