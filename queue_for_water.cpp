#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n, a[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    long long res = 0;
    for (int i = 0; i < n - 1; i++) res += a[i] * (n - i - 1);
    cout << res;
    return 0;
}