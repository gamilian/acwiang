#include <iostream>

using namespace std;

const int N = 1000010;

int prime[N], cnt;
bool st[N];

void get_prime(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!st[i]) prime[cnt++] = i;
        for (int j = 0; prime[j] <= n / i; ++j) {
            st[prime[j] * i] = true;
            if (i % prime[j] == 0) break;
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