#include <iostream>

using namespace std;

const int N = 100010;

int n, m, a[N], b[N];

bool cmp_subsequence(int a[], int b[]) {
    int i = 0, j = 0;
    for (; i < n && j < m; j++) {
        if (a[i] == b[j]) i++;
    }
    if (i == n) return true;
    else return false;
}

int main() {
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    cout << (cmp_subsequence(a, b) ? "Yes" : "No");
    return 0;
}