#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

struct Range {
    int l, r;

    bool operator<(const Range &w) const {
        return r < w.r;
    }
} range[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        range[i] = {l, r};
    }
    sort(range, range + n);
    int res = 0, end = -(1e9 + 10);
    for (int i = 0; i < n; i++)
        if (range[i].l > end) res++, end = range[i].r;
    cout << res;
}
