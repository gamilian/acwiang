#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int prime[N], euler[N], cnt;
bool st[N];

long long get_eulers(int n) {
    euler[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!st[i]) {
            prime[cnt++] = i;
            euler[i] = i - 1;
        }
        for (int j = 0; prime[j] <= n / i; ++j) {
            int t = prime[j] * i;
            st[t] = true;
            if (i % prime[j] == 0) {
                euler[t] = euler[i] * prime[j];
                break;
            }
            euler[t] = euler[i] * (prime[j] - 1);
        }
    }
    long long res = 0;
    for (int i = 1; i <= n; ++i) res += euler[i];
    return res;
}

int main() {
    int n;
    cin >> n;
    cout << get_eulers(n);
    return 0;
}